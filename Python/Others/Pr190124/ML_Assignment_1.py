'''

머신 러닝 과제 1
MNIST database에 대하여 LeNet-5 (CNN)를 구현하여 training하고 test하여 최대의 정확도를 달성할 것
- https://github.com/sujaybabruwad/LeNet-in-Tensorflow 에서 아래의 Specs 설명을 그대로 준수할 것
    (소스 : https://github.com/sujaybabruwad/LeNet-in-Tensorflow/blob/master/LeNet-Lab.ipynb)
- Activation function의 조합을 바꿔가면서 가장 좋은 조합을 찾을 것
- Training을 통해 activation function의 최적 조합을 찾기 위해서 K-Fold cross validation 방법을 사용할 것 (다음 슬라이드 참고) 
- Test에서 정확도를 측정할 때는 MNIST database의 test set만을 이용할 것


'''

mnist_data_path = "C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190124\\mnist_data"
saver_path = "C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190124\\saver"

import tensorflow as tf
import numpy as np
import scipy as sp
import matplotlib.pyplot as plt
import pandas as pd
import random
import mglearn
from tensorflow.examples.tutorials.mnist import input_data
from sklearn.model_selection import cross_val_score, KFold
from sklearn.linear_model import LogisticRegression

# reshape=False를 넣자! 안 그러면 operands could not be broadcast together with remapped shapes 오류 발생
mnist = input_data.read_data_sets(mnist_data_path, reshape=False)      
X_train, y_train = mnist.train.images, mnist.train.labels
X_validation, y_validation = mnist.validation.images, mnist.validation.labels
X_test, y_test = mnist.test.images, mnist.test.labels

print("\n")
print("Image Shape : {}".format(X_train[0].shape))
print("Training Set: {} samples".format(len(X_train)))
print("Validation Set: {} samples".format(len(X_validation)))
print("Test set: {} samples".format(len(X_test)))

'''
Tensorflow가 불러오는 MNIST 데이터셋은 28x28x1 이미지이다.
그러나, LeNet 아키텍처는 32x32xC(상수) 이미지만 받아들인다.
그래서, LeNet이 받아들일 수 있도록 MNIST 데이터에 padding을 붙인다.
(위, 아래, 왼쪽, 오른쪽 각각 2줄 붙이기)
'''
X_train = np.pad(X_train, ((0,0),(2,2),(2,2),(0,0)), 'constant')
X_validation = np.pad(X_validation, ((0,0),(2,2),(2,2),(0,0)), 'constant')
X_test = np.pad(X_test, ((0,0),(2,2),(2,2),(0,0)), 'constant')
print("X_train에 패딩 씌우기: {}".format(X_train[0].shape))

# 데이터 시각화
index = random.randint(0, len(X_train))     # 0~55000 사이 중에서 난수 뽑기
# squeeze : 차원 중 사이즈가 1인 것을 찾아 스칼라값으로 바꿔 해당 차원 제거
# X_train의 index번째를 squeeze했기 때문에 최종적으로 남는 모양은 2차원인 (32,32)
image = X_train[index].squeeze()            
plt.figure(figsize=(1,1))
plt.imshow(image, cmap="gray")
print(y_train[index])

# 데이터 전처리
from sklearn.utils import shuffle
X_train, y_train = shuffle(X_train, y_train)

# EPOCH, BATCH_SIZE 설정
EPOCHS = 1
BATCH_SIZE = 128

# LeNet-5 사용하기
from tensorflow.contrib.layers import flatten

def LeNet(x=0):
    mu = 0
    sigma = 0.1
    layer_depth = {
        'layer_1' : 6,
        'layer_2' : 16,
        'layer_3' : 120,
        'layer_4' : 84
    }

    # Layer 1 : 컨볼루션. Input = 32x32x1, Output = 28x28x6
    conv1_w = tf.Variable(tf.truncated_normal(shape=[5,5,1,6], mean=mu, stddev=sigma))
    conv1_b = tf.Variable(tf.zeros(6))
    conv1 = tf.nn.conv2d(x, conv1_w, strides=[1,1,1,1], padding='VALID') + conv1_b
    conv1 = tf.nn.leaky_relu(conv1)   # Activation

    # 풀링 1. Input = 28x28x6, Output = 14x14x6
    pool_1 = tf.nn.max_pool(conv1, ksize=[1,2,2,1], strides=[1,2,2,1], padding='VALID')

    # Layer 2 : 컨볼루션. Input = 14x14x16, Output = 10x10x16
    conv2_w = tf.Variable(tf.truncated_normal(shape=[5,5,6,16], mean=mu, stddev=sigma))
    conv2_b = tf.Variable(tf.zeros(16))
    conv2 = tf.nn.conv2d(pool_1, conv2_w, strides=[1,1,1,1], padding='VALID') + conv2_b
    conv2 = tf.nn.leaky_relu(conv2)   # Activation

    # 풀링 2. Input = 10x10x16, Output = 5x5x16
    pool_2 = tf.nn.max_pool(conv2, ksize=[1,2,2,1], strides=[1,2,2,1], padding='VALID')

    # Flatten(평탄화. 리스트를 1줄로 풀어주기). Input = 5x5x16, Output = 400
    fc1 = flatten(pool_2)   # 완전 연결 계층으로 이어질거라 fc1이라 명명.

    # Layer 3 : 완전 연결 계층. Input = 400, Output = 120
    fc1_w = tf.Variable(tf.truncated_normal(shape=(400,120), mean=mu, stddev=sigma))
    fc1_b = tf.Variable(tf.zeros(120))
    fc1 = tf.matmul(fc1, fc1_w) + fc1_b
    fc1 = tf.nn.leaky_relu(fc1)   # Activation

    # Layer 4 : 완전 연결 계층. Input = 120, Output = 84
    fc2_w = tf.Variable(tf.truncated_normal(shape=(120,84), mean=mu, stddev=sigma))
    fc2_b = tf.Variable(tf.zeros(84))
    fc2 = tf.matmul(fc1, fc2_w) + fc2_b
    fc2 = tf.nn.leaky_relu(fc2)   # Activation

    # Layer 5 : 완전 연결 계층. Input = 84, Output = 10
    fc3_w = tf.Variable(tf.truncated_normal(shape=(84,10), mean=mu, stddev=sigma))
    fc3_b = tf.Variable(tf.zeros(10))
    logits = tf.matmul(fc2, fc3_w) + fc3_b
    return logits

# ----------------- 여기까지 LeNet(x) 함수 -----------------

# 특징과 레이블
# 원-핫 인코딩 사용
x = tf.placeholder(tf.float32, (None, 32, 32, 1))
y = tf.placeholder(tf.int32, (None))
one_hot_y = tf.one_hot(y, 10)

# 트레이닝 파이프라인
# MNIST 데이터를 분류하는 모델을 사용하는 트레이닝 파이프라인 만들기
rate = 0.001
logits = LeNet(x)
cross_entropy = tf.nn.softmax_cross_entropy_with_logits(logits=logits, labels=one_hot_y)
loss_operation = tf.reduce_mean(cross_entropy)
optimizer = tf.train.AdamOptimizer(learning_rate = rate)
training_operation = optimizer.minimize(loss_operation)

# 모델 평가
# 데이터셋이 주어졌을 때 모델의 정확도 구하기
correct_prediction = tf.equal(tf.argmax(logits, 1), tf.argmax(one_hot_y, 1))
accuracy_operation = tf.reduce_mean(tf.cast(correct_prediction, tf.float32))
saver = tf.train.Saver()

def evaluate(X_data, y_data) :
    num_examples = len(X_data)
    total_accuracy = 0
    sess = tf.get_default_session()
    for offset in range(0, num_examples, BATCH_SIZE) :
        batch_x, batch_y = X_data[offset:offset+BATCH_SIZE], y_data[offset:offset+BATCH_SIZE]
        accuracy = sess.run(accuracy_operation, feed_dict={x: batch_x, y: batch_y})
        total_accuracy += (accuracy * len(batch_x))
    
    return (total_accuracy / num_examples)

# 모델 학습
# 모델을 훈련시키기 위해 아까 만든 트레이닝 파이프라인을 통해 학습
with tf.Session() as sess :
    sess.run(tf.global_variables_initializer())
    num_examples = len(X_train)
    
    print("Training...")
    print()
    for i in range(EPOCHS) :
        X_train, y_train = shuffle(X_train, y_train)
        for offset in range(0, num_examples, BATCH_SIZE) :
            end = offset + BATCH_SIZE
            batch_x, batch_y = X_train[offset:end], y_train[offset:end]
            sess.run(training_operation, feed_dict={x: batch_x, y: batch_y})
        
        validation_accuracy = evaluate(X_validation, y_validation)
        print("Epoch {}, ".format(i+1), end="")
        print("Validation Accuracy = {:.3f}".format(validation_accuracy))
        print()
    
    saver.save(sess, saver_path)
    print("Model Saved")



# KFold와 모델 객체 만들기
kfold = KFold(n_splits=5)
logreg = LogisticRegression()
scores = cross_val_score(logreg, X_train, y_train, cv=kfold)
print("교차 검증 점수 : {}".format(scores))
print()



# 모델 평가하기
# 모델에 만족했다면 테스트셋을 넣어 성능을 평가
# 테스트 시 동일한 데이터셋을 되도록이면 여러 번 사용하지 않도록 하기.
with tf.Session() as sess :
    saver.restore(sess, tf.train.latest_checkpoint('.'))
    test_accuracy = evaluate(X_test, y_test)
    print("Test Accuracy = {:.3f}".format(test_accuracy))
    
        
        
    

