# -*- coding: utf-8 -*-
"""
Created on Sun Apr 26 21:30:03 2020

@author: Isaac
"""

import tensorflow as tf
graph = tf.Graph()
with graph.as_default() :
    a = tf.constant([[2,1], [2,1]])
    b = tf.constant([[1,2], [1,2]])
    c = tf.matmul(a,b)

with tf.Session(graph=graph) as sess :
    print(sess.run(c))