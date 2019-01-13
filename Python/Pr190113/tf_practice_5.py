'''

3분 딥러닝 텐서플로맛
4.2 간단한 분류 모델 구분하기
포유류 / 조류 구분 - 털과 날개가 있는가?

'''

import tensorflow as tf
import numpy as np


# 학습에 사용할 데이터를 정의.
# 1 = 있다, 0 = 없다.
# [털, 날개]
x_data = np.array(
    [ [0,0], [1,0], [1,1], [0,0], [0,0], [0,1] ]
)

# 원-핫 인코딩 방식으로 개체 표현
y_data = np.array( 
    [
        [1,0,0],    # 기타
        [0,1,0],    # 포유류
        [0,0,1],    # 조류
        [1,0,0],
        [1,0,0],
        [0,0,1],
    ]
)


# 신경망 모델 구성
# X와 Y에 실측값을(Ground Truth) 넣어 학습시킬 예정. 그래서 플레이스홀더로 설정함.
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

# 가중치와 편향 변수 설정
# W = [입력층(특징 수, x_data), 출력층(레이블 수, y_data)]의 구성인 [2,3]으로 설정
# b = 레이블 수인 3개의 요소를 가진 변수로 설정.
W = tf.Variable(tf.random_uniform([2,3], -1., 1.))
b = tf.Variable(tf.zeros([3]))

# X*W + b를 활성화 함수인 ReLU에 적용하면 신경망 구성 끝!
L = tf.add(tf.matmul(X,W), b)
L = tf.nn.relu(L)

# softmax 함수로 사용하기 쉽게 다듬기
# softmax 함수는 배열 내의 결과값들을 전체 합이 1이 되도록 만든다.
# 이렇게 나온 'model' = 신경망을 통해 나온 예측값.
model = tf.nn.softmax(L)


# 손실 함수 작성하기 (교차 엔트로피 함수 사용)
# → 원-핫 인코딩을 이용한 대부분의 모델에서 사용
# reduce_sum(axis=1) : 2번째 행 (1번째 인덱스)의 값을 다 더하고 그 행을 없앰.
cost = tf.reduce_mean(-tf.reduce_sum(Y * tf.log(model), axis=1))

# 기본적인 경사 하강법으로 최적화
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train_op = optimizer.minimize(cost)

# 텐서플로의 세션 초기화
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)

# 앞서 구성한 특징과 레이블 데이터를 이용해 학습을 100번 진행
for step in range(100) :
    sess.run(train_op, feed_dict = {X: x_data, Y: y_data})

    # 학습 도중 10번에 한 번씩 손실값 출력
    if ( (step+1) % 10 == 0) :
        print(step+1, sess.run(cost, feed_dict = {X: x_data, Y: y_data}))


# 학습된 결과 확인
# 예측값인 model를 바로 출력하면 [0.2 0.7 0.1]과 같이 나오기 때문에,
# 요소 중 가장 큰 값의 인덱스를 찾아주는 argmax 함수를 사용하여 레이블 값 출력
# 즉, 원-핫 인코딩을 거꾸로 한 결과를 만든다.
prediction = tf.argmax(model, axis=1)
target = tf.argmax(Y, axis=1)
print('예측값 : ', sess.run(prediction, feed_dict={X: x_data}))
print('실제값 : ', sess.run(target, feed_dict={Y: y_data}))

# 간단하게 정확도 출력
# 신경망이 한 층만 있어 학습 횟수를 늘려도 정확도는 미미하게 개선된다.
is_correct = tf.equal(prediction, target)
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
print('정확도 : %.2f' % sess.run(accuracy * 100, feed_dict = {X: x_data, Y: y_data}))

