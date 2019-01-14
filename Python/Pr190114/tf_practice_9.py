'''

3분 딥러닝 텐서플로맛
Ch.6 헬로 딥러닝 MNIST
6.1 MNIST 학습하기

'''
# MNIST 데이터셋 가져오기
# 코드 몇 줄이면 된다!!
mnist_data_path = 'C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190114\\mnist\\data'

import tensorflow as tf
import numpy as np

from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets(mnist_data_path, one_hot=True)

# 신경망 모델 구성
# MNIST 손글씨 픽셀 = 28x28 = 784개
# 레이블 : 숫자니까 0~9까지 = 10개
X = tf.placeholder(tf.float32, [None, 784])
Y = tf.placeholder(tf.float32, [None, 10])

# 미니배치(Minibatch)를 이용하여 코드 구성
# 위의 플레이스홀더에서 학습할 개수를 계속 바꿔줘야 할 경우 None을 쓴다.
# 편향은 내가 임의로 추가함 (책에서도 알아서 추가하라고 나와있었음)
# 784(입력, 특징 개수) → 256(1번째 은닉층 뉴런 개수)
W1 = tf.Variable(tf.random_normal([784, 256], stddev=0.01))     # 표준편차를 넣으면 stddev=0.01인 정규분포를 가지는 임의의 값으로 초기화
L1 = tf.nn.relu(tf.matmul(X, W1))
b1 = tf.Variable(tf.zeros([256]))

# 256(1번째 은닉층 뉴런 개수) → 256(2번째 은닉층 뉴런 개수)
W2 = tf.Variable(tf.random_normal([256, 256], stddev=0.01))
L2 = tf.nn.relu(tf.matmul(L1, W2))
b2 = tf.Variable(tf.zeros([256]))

# 256(2번째 은닉층 뉴런 개수) → 10(결과값 0~9 분류 개수)
W3 = tf.Variable(tf.random_normal([256, 10], stddev=0.01))
b3 = tf.Variable(tf.zeros([10]))
model = tf.matmul(L2, W3)

# 각 이미지에 대한 손실 값(실제값과 예측값의 차이)를 구하고 tf.reduce_mean으로 미니배치의 평균 손실값 구하기
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=model, labels=Y))

# AdamOptimizer로 손실값을 최소화하는 최적화를 수행
optimizer = tf.train.AdamOptimizer(0.001).minimize(cost)

# 신경망 모델 초기화, 학습 진행할 세션 시작
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)

# 실제 학습 진행
# MNIST는 데이터가 수만 개로 매우매우 커서 미니배치를 사용한다 (100개씩 나눈다.)
batch_size = 100
total_batch = int(mnist.train.num_examples / batch_size)

# MNIST 데이터 전체를 학습하는 일을 15번 반복
# 에포크(epoch) : 학습 데이터 전체를 한 바퀴 도는 일. 여기서는 15번 반복하니 15 epochs.
for epoch in range(15) :
    total_cost = 0
    '''
    미니배치의 총 개수만큼 반복하여 학습
    next_batch 함수를 이용해 학습할 데이터를 batch_size만큼 가져온다.
    이후, 입력값인 이미지 데이터는 batch_xs에, 출력값인 레이블 데이터는 batch_ys에 저장.
    sess.run을 이용하여 최적화. 손실 값을 가져와서 저장.
    feed_dict에는 입력값 X와 예측을 평가할 실제 레이블값 Y에 사용할 데이터를 넣음.
    total_cost에 손실 값 저장
    '''
    for i in range(total_batch) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        _, cost_val = sess.run([optimizer, cost], feed_dict={X: batch_xs, Y: batch_ys})
        total_cost += cost_val
    
    # 한 세대의 학습이 끝나면 학습한 세대의 평균 손실 값 출력
    print('Epoch : %04d, ' % (epoch+1), end='')
    print('Avg cost = ', '{:.3f}'.format(total_cost / total_batch))

print("Optimization Complete!")


# 학습이 잘 되었는지 평가
# 예측 결과인 model의 값과 실제 레이블인 Y의 값 비교
# (참고 : 책 p.101)
is_correct = tf.equal(tf.argmax(model, 1), tf.argmax(Y, 1))

# tf.cast를 이용해 is_correct를 0 or 1로 변환
# tf.reduce_mean으로 평균을 내면 그것이 바로 정확도!
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))

# mnist.test를 이용해 테스트 이미지와 레이블 데이터를 넣어 accuracy를 계산한다.
print("Accuracy : ", sess.run(accuracy, feed_dict={X: mnist.test.images, Y: mnist.test.labels}))

'''
아래 코드를 넣어 중간중간 결과도 확인해보자.
print(W3)
print(model)
print(sess.run(model, feed_dict={X: mnist.test.images, Y: mnist.test.labels})[0])
print(is_correct)
print(sess.run(is_correct, feed_dict={X: mnist.test.images, Y: mnist}))

'''