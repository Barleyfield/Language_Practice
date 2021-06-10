'''

3분 딥러닝 텐서플로맛
5.1 학습 모델 저장하고 재사용하기
텐서보드를 이용해 손실 값의 변화를 그래프로 추적

'''

import tensorflow as tf
import numpy as np

csv_path = 'D:\\Study\\CodePractice\\LanguagePractice\\Python\\Pr190113\\data.csv'
ckpt_model_path = 'D:\\Study\\CodePractice\\LanguagePractice\\Python\\Pr190113\\model'
dnn_ckpt_path = 'D:\\Study\\CodePractice\\LanguagePractice\\Python\\Pr190113\\model\\dnn.ckpt'

# 데이터를 읽어들이고 변환하는 코드르 프로그램 시작
# unpack = True : csv 파일의 행과 열을 바꾼다
# np.transpose도 마찬가지
# 파일 경로는 ./data.csv로 하려 했으나 인식이 안 되어 절대 경로로 넣음
data = np.loadtxt(csv_path, delimiter=',', unpack=True, dtype='float32')
x_data = np.transpose(data[0:2])
y_data = np.transpose(data[2:])

# 신경망 모델 구성
# 먼저 학습 횟수 세는 변수 만들기
global_step = tf.Variable(0, trainable=False, name='global_step')

# 4장보다 계층을 하나 더 늘리고, 편향은 없이 가중치만 사용
X = tf.placeholder(tf.float32)
Y = tf.placeholder(tf.float32)

W1 = tf.Variable(tf.random_uniform([2,10], -1., 1.))
L1 = tf.nn.relu(tf.matmul(X, W1))

# 앞 계층의 출력 크기 = 10, 뒤 계층의 출력 크기 = 20
# 이 수를 늘리면 복잡도가 높은 문제를 해결할 수 있다. 너무 올리면 과적합 문제 발생
W2 = tf.Variable(tf.random_uniform([10,20], -1., 1.))
L2 = tf.nn.relu(tf.matmul(L1, W2))

W3 = tf.Variable(tf.random_uniform([20,3], -1., 1.))
model = tf.matmul(L2, W3)

cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(labels=Y, logits=model))
optimizer = tf.train.AdamOptimizer(learning_rate=0.01)

# global_step 변수를 넣어주면 최적화 함수가 학습용 변수들을 최적화할 때마다 global_step += 1 수행
train_op = optimizer.minimize(cost, global_step=global_step)

# 세션 열고 최적화
# Saver를 쓰면 모델을 불러오거나 저장할 수 있다.
sess = tf.Session()
saver = tf.train.Saver(tf.global_variables())

# './model' 디렉토리에 기존에 학습해둔 모델이 있는지 확인.
# 모델이 있다면 saver.restore 함수로 학습된 값 불러옴. 없으면 변수를 새로 초기화
# 체크포인트 파일 = 학습된 모델을 저장한 파일
ckpt = tf.train.get_checkpoint_state(ckpt_model_path)
if ckpt and tf.train.checkpoint_exists(ckpt.model_checkpoint_path) :
    saver.restore(sess, ckpt.model_checkpoint_path)
else :
    sess.run(tf.global_variables_initializer())


# global_step 값을 이용해 학습을 몇 번째 진행하고 있는지 출력
# global_step은 텐서 타입의 변수이므로 값을 가져올 때 sess.run(global_step) 이용
for step in range(2) :
    sess.run(train_op, feed_dict={X: x_data, Y: y_data})
    print('Step : %d, ' % sess.run(global_step), end='')
    print('Cost : %.3f' % sess.run(cost, feed_dict={X: x_data, Y: y_data}))


# 최적화가 끝난 뒤 학습된 변수들을 지정한 체크포인트 파일에 저장
# 2번째 매개 변수는 체크포인트 파일의 위치와 이름. model 디렉토리는 이미 만들어져 있어야 한다.
# global_step의 값은 저장할 파일의 이름에 추가로 붙는다. 이걸로 여러 상태의 체크포인트 생성 가능.
saver.save(sess, dnn_ckpt_path, global_step=global_step)

# 예측 결과와 정확도 확인하는 코드 삽입, 실행 결과 확인
prediction = tf.argmax(model, 1)
target = tf.argmax(Y, 1)
print('예측값 : ', sess.run(prediction, feed_dict={X: x_data}))
print('실제값 : ', sess.run(target, feed_dict={Y: y_data}))
is_correct = tf.equal(prediction, target)
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
print('정확도 : %.2f' % sess.run(accuracy * 100, feed_dict = {X: x_data, Y: y_data}))