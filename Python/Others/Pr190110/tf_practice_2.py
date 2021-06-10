# -*- coding: utf-8 -*-
"""
Created on Thu Jan 10 14:24:28 2019

@author: Isaac

3분 딥러닝 텐서플로맛
텐서와 그래프 실행

"""
# Hello 변수의 '값' 출력
import tensorflow as tf

hello = tf.constant("Hello, Tensorflow!")
print("Hello 변수의 값 : ", hello)

# 연산
a = tf.constant(10)
b = tf.constant(32)
c = tf.add(a, b)
print("c의 값 : ", c)

# 실제 그래프의 실행
sess = tf.Session()
print(sess.run(hello))
print(sess.run([a,b,c]))
sess.close() 
