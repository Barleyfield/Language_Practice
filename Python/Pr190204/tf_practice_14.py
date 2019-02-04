# -*- coding: utf-8 -*-
"""
Created on Mon Feb  4 14:21:33 2019

@author: Isaac

3분 딥러닝 텐서플로맛
Ch.8 대표적 비지도 학습법 Autoencoder
8.2 오토인코더 구현하기

"""

mnist_data_path = "C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190204\\mnist_data"

import time
import tensorflow as tf
import numpy as np
import matplotlib.pyplot as plt
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets(mnist_data_path, one_hot=True)

# 하이퍼파라미터로 사용할 옵션들을 따로 빼내어 코드를 구조화
learning_rate = 0.01        # 최적화 함수에서 사용할 학습률
training_epoch = 20         # 전체 데이터를 학습할 총 횟수
batch_size = 100            # 미니배치로 한 번에 학습할 데이터(이미지)의 개수
n_hidden = 256              # 은닉층의 뉴런 개수
n_input = 28*28             # 입력값의 크기

# X의 플레이스홀더 설정
X = tf.placeholder(tf.float32, [None, n_input])

# 오토인코더의 핵심은 '인코더'와 '디코더'
# 인코더와 디코더 만들기

# n_hidden개의 뉴런을 가진 은닉층 생성
# 중요 : n_input > n_hidden. 대부분 입력값 압축 + 노이즈 제거 시 이렇게 사용
W_encode = tf.Variable(tf.random_normal([n_input, n_hidden]))         
b_encode  =tf.Variable(tf.random_normal([n_hidden]))

# (입력값 * 가중치) + 편향 수행 후 sigmoid 함수 적용
encoder = tf.nn.sigmoid(tf.add(tf.matmul(X, W_encode), b_encode))   

# 입력값 = n_hidden (은닉층의 크기), 출력값 = n_input (입력층의 크기)
W_decode = tf.Variable(tf.random_normal([n_hidden, n_input]))   
b_decode = tf.Variable(tf.random_normal([n_input]))             
decoder = tf.nn.sigmoid(tf.add(tf.matmul(encoder, W_decode), b_decode))

# 손실값 설정 = 디코더가 내보낸 결과값의 차이
# tf.pow()로 이 차이를 제곱한다.
# tf.reduce_mean()으로 평균을 구한다.
cost = tf.reduce_mean(tf.pow(X - decoder, 2))

# 최적화
optimizer = tf.train.RMSPropOptimizer(learning_rate).minimize(cost)

# 학습 진행 코드
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)

count_t = time.time()   # 학습 시간 측정
total_batch = int(mnist.train.num_examples / batch_size)
for epoch in range(training_epoch) :
    total_cost = 0
    for i in range(total_batch) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        _, cost_val = sess.run([optimizer, cost], feed_dict={X: batch_xs})
        total_cost += cost_val
    print("Epoch: %04d, " % (epoch + 1), end="")
    print("Avg cost : {:.4f}".format(total_cost / total_batch))

print("최적화 완료!")
print("학습 시간 : %.02f" % (time.time() - count_t))

# 결과값을 정확도가 아닌 디코더로 생성해낸 결과를 직관적인 방법으로 확인
# matplotlib을 이용해 이미지로 출력
# 총 sample_size 만큼의 테스트 데이터를 가져와 디코더를 이용해 출력값 만들기
sample_size = 10
samples = sess.run(decoder, feed_dict={X: mnist.test.images[:sample_size]})


fig, ax = plt.subplots(2, sample_size, figsize=(sample_size, 2))

for i in range(sample_size) :
    ax[0][i].set_axis_off()
    ax[1][i].set_axis_off()
    # numpy 모듈로 MNIST 데이터를 28 x 28 크기의 이미지 데이터로 재구성
    # matplotlib의 imshow 함수로 그래프에 이미지로 출력
    ax[0][i].imshow(np.reshape(mnist.test.images[i], (28, 28)))     # 입력값의 이미지
    ax[1][i].imshow(np.reshape(samples[i], (28, 28)))               # 신경망으로 생성한 이미

plt.show()






    










