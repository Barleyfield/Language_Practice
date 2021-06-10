# -*- coding: utf-8 -*-
"""
Created on Thu Jan 10 14:56:01 2019

@author: Isaac

3분 딥러닝 텐서플로맛
플레이스홀더와 변수

"""
import tensorflow as tf
import numpy as np

# None은 크기가 정해지지 않았음을 의미
X = tf.placeholder(tf.float32, [None, 3])
print("X의 값 : ", X)

# 위에서 텐서의 모양을 (?, 3)으로 정의했으므로 2번째 차원은 요소가 3개 있어야 한다.
x_data = [[1,2,3], [4,5,6]]

# 변수 정의하기
W = tf.Variable(tf.random_normal([3,2]))
# W = tf.Variable([[0.1, 0.1], [0.2, 0.2], [0.3, 0.3]]) → 이건 원하는 텐서의 형태의 데이터를 넣고 싶을 때 사용
b = tf.Variable(tf.random_normal([2,1]))

# 행렬 X와 W를 이용하여 연산
expr = tf.matmul(X,W) + b
sess = tf.Session()
sess.run(tf.global_variables_initializer())
print("=== x_data ===")
print(x_data)
print("=== W ===")
print(sess.run(W))
print("=== b ===")
print(sess.run(b))
print("=== expr ===")
print(sess.run(expr, feed_dict={X: x_data}))

sess.close()





