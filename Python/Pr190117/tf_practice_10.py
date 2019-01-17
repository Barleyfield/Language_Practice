'''

3분 딥러닝 텐서플로맛
Ch.6 헬로 딥러닝 MNIST
6.2 드롭아웃

tf_practice_9.py 코드 재사용

'''

mnist_data_path = 'C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190117\\mnist\\data'

import tensorflow as tf
import numpy as np

from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets(mnist_data_path, one_hot=True)

X = tf.placeholder(tf.float32, [None, 784])
Y = tf.placeholder(tf.float32, [None, 10])

# keep_prob라는 플레이스홀더를 만들어 학습 시에는 0.8을 넣어 드롭아웃 사용.
# 예측 시에는 1을 넣어 신경망 전체를 사용하도록 만든다.
keep_prob = tf.placeholder(tf.float32)

# b1 = tf.Variable() 대신 L1을 한 번 더 넣고 dropout 적용
W1 = tf.Variable(tf.random_normal([784, 256], stddev=0.01)) 
L1 = tf.nn.relu(tf.matmul(X, W1))
L1 = tf.nn.dropout(L1, keep_prob)

W2 = tf.Variable(tf.random_normal([256, 256], stddev=0.01))
L2 = tf.nn.relu(tf.matmul(L1, W2))
L2 = tf.nn.dropout(L2, keep_prob)

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
# Dropout을 적용하면 학습이 느리게 진행되기 때문에 Epoch 횟수를 늘려야 정확도가 높아진다.
for epoch in range(30) :
    total_cost = 0

    for i in range(total_batch) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        # 여기에 keep_prob 넣기
        _, cost_val = sess.run([optimizer, cost], feed_dict={X: batch_xs, Y: batch_ys, keep_prob: 0.8})
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
# keep_prob를 1로 넣어준다.
print("Accuracy : ", sess.run(accuracy, feed_dict={X: mnist.test.images, Y: mnist.test.labels, keep_prob: 1}))
