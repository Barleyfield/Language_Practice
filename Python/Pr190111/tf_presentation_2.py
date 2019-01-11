'''

190110 동아리 세미나 발표용
텐서플로 돌려보기

'''

import tensorflow as tf

X = tf.placeholder(tf.float32, [None, 3], 'X')

print(X)