'''

3분 딥러닝 텐서플로맛
5.2 텐서보드 사용하기

'''

import tensorflow as tf
import numpy as np

csv_path = 'C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190114\\data.csv'
ckpt_model_path = 'C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190114\\model'

# 데이터를 읽어들이는 코드와 플레이스홀더 값 설정
data = np.loadtxt(csv_path, delimiter=',', unpack=True, dtype='float32')

x_data = np.transpose(data[0:2])
y_data = np.transpose(data[2:])

global_step = tf.Variable(0, trainable=False, name='global_step')

X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

# with을 사용하여 신경망의 각 계층에 코드 붙이기 (이러면 close() 메소드 사용할 필요 없음)
with tf.name_scope('layer1') :
    W1 = tf.Variable(tf.random_uniform([2, 10], -1., 1.), name='W1')
    L1 = tf.nn.relu(tf.matmul(X, W1))
    # 가중치와 편향의 변화를 그래프로 살펴보기
    W1_hist = tf.summary.histogram('Weight1', W1)
    L1_hist = tf.summary.histogram('Layer1', L1)


with tf.name_scope('layer2') :
    W2 = tf.Variable(tf.random_uniform([10, 20], -1., 1.), name='W2')
    L2 = tf.nn.relu(tf.matmul(L1, W2))
    # 가중치와 편향의 변화를 그래프로 살펴보기
    W2_hist = tf.summary.histogram('Weight2', W2)
    L2_hist = tf.summary.histogram('Layer2', L2)


with tf.name_scope('output') :
    W3 = tf.Variable(tf.random_uniform([20, 3], -1., 1.), name='W3')
    model = tf.matmul(L2, W3)
    # 가중치와 편향의 변화를 그래프로 살펴보기
    W3_hist = tf.summary.histogram('Weight3', W3)

with tf.name_scope('optimizer') :
    cost = tf.reduce_mean(
        tf.nn.softmax_cross_entropy_with_logits(labels=Y, logits=model)
    )
    optimizer = tf.train.AdamOptimizer(learning_rate=0.01)
    train_op = optimizer.minimize(cost, global_step=global_step)

    # 손실 값을 추적하기 위해 수집할 값을 지정하는 코드 작성
    # scalar 함수는 값이 하나인 텐서를 수집할 때 사용
    # 참고 : https://www.tensorflow.org/api_docs/python/tf/summary
    tf.summary.scalar('cost', cost)


# 모델을 불러들이거나 초기화하는 코드 넣기
sess = tf.Session()
saver = tf.train.Saver(tf.global_variables())
ckpt = tf.train.get_checkpoint_state(ckpt_model_path)
if ckpt and tf.train.checkpoint_exists(ckpt.model_checkpoint_path) :
    saver.restore(sess, ckpt.model_checkpoint_path)
else :
    sess.run(tf.global_variables_initializer())


# 앞서 지정한 텐서를 수집
merged = tf.summary.merge_all()
# 그래프와 텐서들의 값을 저장할 디렉터리 설정
writer = tf.summary.FileWriter('./logs', sess.graph)

# 최적화 실행하는 코드 작성
for step in range(100) :
    sess.run(train_op, feed_dict={X: x_data, Y: y_data})
    print('Step: %d, ' % sess.run(global_step), end='')
    print('Cost: %.3f' % sess.run(cost, feed_dict={X: x_data, Y: y_data}))

    # sess.run을 이용해 앞서 merged로 모아둔 텐서의 값들을 계산 & 수집
    # writer.add_summary 함수를 이용해 해당 값들을 앞서 지정한 디렉터리에 저장
    # global_step으로 수집한 시점 기록
    summary = sess.run(merged, feed_dict={X: x_data, Y: y_data})
    writer.add_summary(summary, global_step=sess.run(global_step))


# 모델을 저장하고 예측하는 부분 작성
saver.save(sess, './model/dnn.ckpt', global_step=global_step)
prediction = tf.argmax(model, 1)
target = tf.argmax(Y, 1)
print('예측값 : ', sess.run(prediction, feed_dict={X: x_data}))
print('실제값 : ', sess.run(target, feed_dict={Y: y_data}))

is_correct = tf.equal(prediction, target)
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
print("정확도 : %.2f" % sess.run(accuracy * 100, feed_dict={X: x_data, Y: y_data}))




'''
실행하면 logs라는 디렉터리가 생성됨.
tensorboard --logdir=./logs 명령 실행하기
MS Edge나 Firefox로 볼 것!
Scalars 또는 Graphs를 본다.

'''

