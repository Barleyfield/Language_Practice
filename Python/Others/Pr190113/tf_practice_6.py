'''

3분 딥러닝 텐서플로맛
4.3 심층 신경망 구현하기
신경망의 층을 둘 이상으로 구성

'''

# tf_practice_5.py 코드 가져옴. 주석 제거

import tensorflow as tf
import numpy as np

x_data = np.array(
    [ [0,0], [1,0], [1,1], [0,0], [0,0], [0,1] ]
)

y_data = np.array( [
    [1,0,0],
    [0,1,0],
    [0,0,1],
    [1,0,0],
    [1,0,0],
    [0,0,1]
])

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

# W와 b를 하나씩 더 추가
W1 = tf.Variable(tf.random_uniform([2,10], -1., 1.))    # [특징, 은닉층의 뉴런 수]
W2 = tf.Variable(tf.random_uniform([10,3], -1., 1.))    # [은닉층의 뉴런 수, 분류 수]
        
b1 = tf.Variable(tf.zeros([10]))    # 은닉층의 뉴런 수
b2 = tf.Variable(tf.zeros([3]))     # 분류 수

L1 = tf.add(tf.matmul(X, W1), b1)
L1 = tf.nn.relu(L1)

# 출력층을 만들기 위해 두 번째 가중치와 편향 적용하여 최종 모델 생성
# W2[10,3]와 b2[3] 적용 → 3개의 출력값 가짐
model = tf.add(tf.matmul(L1, W2), b2)

# 손실 함수 작성 (교차 엔트로피 함수 사용)
# 이번에는 식을 직접 쓰느 대신 텐서플로가 제공하는 교차 엔트로피 함수 사용
# AdamOptimizer 최적화 함수 사용. '보편적으로' GradientDescentOptimizer보다 좋다고 한다.
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=Y, logits=model))
optimizer = tf.train.AdamOptimizer(learning_rate=0.01)
train_op = optimizer.minimize(cost)

'''
비교해보기
cost = tf.reduce_mean(-tf.reduce_sum(Y * tf.log(model), axis=1))
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.01)
train_op = optimizer.minimize(cost)
'''

init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)

for step in range(100) :
    sess.run(train_op, feed_dict = {X: x_data, Y: y_data})
    
    if( (step+1) % 10 == 0 ) :
        print(step+1, sess.run(cost, feed_dict = {X: x_data, Y: y_data}))

prediction = tf.argmax(model, axis=1)
target = tf.argmax(Y, axis=1)
print('예측값 : ', sess.run(prediction, feed_dict = {X: x_data, Y: y_data}))
print('실제값 : ', sess.run(target, feed_dict = {X: x_data, Y: y_data}))

is_correct = tf.equal(prediction, target)
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
print('정확도 : %.2f' % sess.run(accuracy * 100, feed_dict = {X: x_data, Y: y_data}))


     