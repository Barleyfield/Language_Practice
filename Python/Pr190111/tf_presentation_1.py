'''
190110 동아리 세미나 발표용
텐서플로 돌려보기

'''

import tensorflow as tf

a = tf.constant(10)
b = tf.constant(32)
c = tf.add(a,b)

sess = tf.Session()
print(sess.run([a,b,c]))

sess.close()
