'''

3분 딥러닝 텐서플로맛
Ch.7 이미지 인식의 은총알 CNN
7.2 모델 구현하기

'''

mnist_data_path = "C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190123\\mnist_data"

import tensorflow as tf
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets(mnist_data_path, one_hot=True)

# X의 첫 번째 차원인 None : 입력 데이터의 개수
# 마지막 1 : 특징의 개수. MNIST 데이터 이미지는 회색이라 채널에 색상이 1개만 있다.
X = tf.placeholder(tf.float32, [None, 28, 28, 1])

# 출력값인 10개의 분류 + keep_prob 선언
Y = tf.placeholder(tf.float32, [None, 10])
keep_prob = tf.placeholder(tf.float32)

# 첫 번째 CNN 계층
# 3x3 크기, 1개 입력(?), 32개 커널의 컨볼루션 계층. conv2d 함수 사용
# padding='SAME' : 입력 크기 = 출력 크기
W1 = tf.Variable(tf.random_normal([3,3,1,32], stddev=0.01))
L1 = tf.nn.conv2d(X, W1, strides=[1, 1, 1, 1], padding='SAME')  # 오른쪽과 아래 1칸씩
L1 = tf.nn.relu(L1)

# 풀링 계층
# 입력값 : 앞서 만든 컨볼루션 계층
# stride : 슬라이딩 시 2칸씩 움직임
L1 = tf.nn.max_pool(L1, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')

# 두 번째 계층
W2 = tf.Variable(tf.random_normal([3,3,32,64], stddev=0.01))    # 3x3 크기, 32개 입력(? - W1의 결과), 64개 커널. 중간의 32는 W1에서의 32.
L2 = tf.nn.conv2d(L1, W2, strides=[1,1,1,1], padding='SAME') 
L2 = tf.nn.relu(L2)
L2 = tf.nn.max_pool(L2, ksize=[1,2,2,1], strides=[1,2,2,1], padding='SAME')     # 2x2 풀링 계층

# 추출한 특징으로 10개의 분류를 만들어내는 계층
W3 = tf.Variable(tf.random_normal([7*7*64, 256], stddev=0.1))   # 직전의 풀링 계층 크기 = 7*7*64
L3 = tf.reshape(L2, [-1, 7*7*64])       # reshape 7*7*64 크기의 1차원 계층으로 만들기 (완전 연결 계층)
L3 = tf.matmul(L3, W3)
L3 = tf.nn.relu(L3)
L3 = tf.nn.dropout(L3, keep_prob)

# 드롭아웃 추가 (과적합 예방)
# 직전의 은닉층인 L3의 출력값 256개를 받아 최종 출력값인 0~9 레이블을 갖는 10개의 출력값 만들기
W4 = tf.Variable(tf.random_normal([256,10], stddev=0.1))
model = tf.matmul(L3, W4)

# 손실 함수와 AdamOptimizer 이용
cost = tf.reduce_mean(tf.nn.softmax_cross_entropy_with_logits(logits=model, labels=Y))
optimizer = tf.train.AdamOptimizer(0.001).minimize(cost)

# 최적화 함수를 RMSPropOptimizer로 바꿔서 결과 비교
optimizer = tf.train.RMSPropOptimizer(0.001, 0.9).minimize(cost)

# 결과 확인
# 모델에 입력값을 전달하기 위해 MNIST 데이터를 28x28 형태로 재구성
init = tf.global_variables_initializer()
sess = tf.Session()
sess.run(init)

batch_size = 100
total_batch = int(mnist.train.num_examples / batch_size)

for epoch in range(15) :
    total_cost = 0

    for i in range(15) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        batch_xs = batch_xs.reshape(-1, 28, 28, 1)

        _, cost_val = sess.run([optimizer, cost], feed_dict={X: batch_xs, Y: batch_ys, keep_prob: 0.7})
        total_cost += cost_val

    print('Epoch: %04d' % (epoch+1), end=', ')
    print('Avg cost:  {:.3f}'.format(total_cost / total_batch))

print("최적화 완료!")
is_correct = tf.equal(tf.argmax(model, 1), tf.argmax(Y, 1))
accuracy = tf.reduce_mean(tf.cast(is_correct, tf.float32))
print("정확도: ", sess.run(accuracy, feed_dict={X: mnist.test.images.reshape(-1,28,28,1), Y: mnist.test.labels, keep_prob: 1}))
