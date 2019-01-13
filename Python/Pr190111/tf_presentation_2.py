'''

190110 동아리 세미나 발표용
텐서플로 돌려보기

'''

import tensorflow as tf

X = tf.placeholder(tf.float32, [None, 3], 'X')

x_data = [[1,2,3], [4,5,6]]

W = tf.Variable(tf.random_normal([3,2]))    # Weight
b = tf.Variable(tf.random_normal([2,1]))    # bias
expr = tf.matmul(X,W) + b

sess = tf.Session()
sess.run(tf.global_variables_initializer())

print("--- x_data ---")
print(x_data)
print("--- W ---")
print(sess.run(W))
print("--- b --- ")
print(sess.run(b))
print("--- expr ---")
print(sess.run(expr, feed_dict={X: x_data}))

sess.close()