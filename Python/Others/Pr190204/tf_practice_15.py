# -*- coding: utf-8 -*-
"""
Created on Mon Feb  4 16:32:33 2019

@author: Isaac

3분 딥러닝 텐서플로맛
Ch.9 딥러닝의 미래 GAN
9.1 GAN 기본 모델 구현하기

※ 주의 : 시작 전 이 코드가 있는 디렉토리에 samples 폴더를 만들기

"""

mnist_data_path = "C:\\Users\\Isaac\\Documents\\LanguagePractice\\Python\\Pr190204\\mnist_data"

import tensorflow as tf
import matplotlib.pyplot as plt
import numpy as np
import time
from tensorflow.examples.tutorials.mnist import input_data
mnist = input_data.read_data_sets(mnist_data_path, one_hot=True)

# 하이퍼파라미터 설정
total_epoch = 100
batch_size = 100            # 미니배치로 한 번에 학습할 데이터(이미지)의 개수
learning_rate = 0.0002      # 최적화 함수에서 사용할 학습률 (숫자가 적을수록 꼼꼼히)
n_hidden = 256              # 은닉층의 뉴런 개수
n_input = 28 * 28           # 입력값의 크기
n_noise = 128               # 생성자의 입력값으로 사용할 노이즈의 크기. 노이즈에서 손글씨 이미지를 무작위로 생성

''' 
1. 플레이스홀더 설정
GAN도 비지도 학습이므로 Autoencoder처럼 Y를 사용하지 않는다.
단, 구분자에 넣을 이미지가 실제 이미지와 생성한 가짜 이미지 2개이고,
가짜 이미지는 노이즈에서 생성할 것이므로 노이즈를 입력할 플레이스홀더 Z를 추가한다.
'''
X = tf.placeholder(tf.float32, [None, n_input])
Z = tf.placeholder(tf.float32, [None, n_noise])

'''
2. 생성자 신경망에 사용할 변수들을 설정.
W1, b1 : 은닉층으로 출력하기 위한 변수
W2, b2 : 출력층에 사용할 변수. 변수의 크기 = 실제 이미지의 크기 (n_input = 28*28)
'''

G_W1 = tf.Variable(tf.random_normal([n_noise, n_hidden], stddev=0.01))
G_b1 = tf.Variable(tf.zeros([n_hidden]))
G_W2 = tf.Variable(tf.random_normal([n_hidden, n_input], stddev=0.01))
G_b2 = tf.Variable(tf.zeros([n_input]))

''' 
3. 구분자 신경망에 사용할 변수들 설정
구분자 : 진짜와 얼마나 가까운가? 0~1 출력
은닉층 : 생성자와 동일하게 구성
※ 구분자 신경망 변수 사용 시 반드시 '실제 이미지 판별하는 것', '생성한 이미지 판별하는 것'
이 2개는 같은 변수 사용!
같은 신경망으로 구분을 시켜야 진짜/가짜 이미지 구분하는 특징을 동시에 잡을 수 있음
'''

D_W1 = tf.Variable(tf.random_normal([n_input, n_hidden], stddev=0.01))
D_b1 = tf.Variable(tf.zeros([n_hidden]))
D_W2 = tf.Variable(tf.random_normal([n_hidden, 1], stddev=0.01))
D_b2 = tf.Variable(tf.zeros([1]))       # 0~1 사이 값을 출력하므로 결과는 '하나'

'''
4. 생성자와 구분자 신경망 구성
'''
# 생성자
def generator(noise_z) :
    hidden = tf.nn.relu(tf.matmul(noise_z, G_W1) + G_b1)
    output = tf.nn.sigmoid(tf.matmul(hidden, G_W2) + G_b2)
    return output

# 구분자
# 0~1 사이의 값 하나만 출력.
def discriminator(inputs) :
    hidden = tf.nn.relu(tf.matmul(inputs, D_W1) + D_b1)
    output = tf.nn.sigmoid(tf.matmul(hidden, D_W2) + D_b2)
    return output


# 무작위 노이즈를 만드는 함수
def get_noise(batch_size, n_noise) :
    return np.random.normal(size=(batch_size, n_noise))

# 생성자 G 선언 : 노이즈 Z를 이용해 가짜 이미지 생성
# 구분자 2개 선언 : 가짜 이미지 판별(G) & 진짜 이미지 판별(X)
G = generator(Z)
D_gene = discriminator(G)
D_real = discriminator(X)

'''
5. 손실값 구하기 (경찰 학습용)
생성자가 만든 이미지를 구분자가 '가짜'라고 판단하도록 하는 손실값
경찰을 학습시키려면 진짜 이미지 판별값 D_real은 1, 가짜 이미지 판별값 D_gene은 1에 가까워야 한다.
즉, 손실값 = D_real + (1 - D_gene). 이 값을 최대화하면 경찰 학습 이루어짐.
'''
loss_D = tf.reduce_mean(tf.log(D_real) + tf.log(1 - D_gene))

'''
6. 손실값 구하기 (위조지폐범 학습용)
생성자가 만든 이미지를 구분자가 '진짜'라고 판단하도록 하는 손실값
위조지폐범이라 가짜 이미지 판별값인 D_gene를 1에 가깝게 만든다.
손실값 = D_gene, 이 값 최대화.
'''
loss_G = tf.reduce_mean(tf.log(D_gene))

'''
7. 손실값을 이용한 학습 준비
loss_D : 구분자 신경망에 사용되는 변수들만 사용 → 생성자가 변하지 않음
loss_G : 생성자 신경망에 사용되는 변수들만 사용 → 구분자가 변하지 않음
'''
D_var_list = [D_W1, D_b1, D_W2, D_b2]
G_var_list = [G_W1, G_b1, G_W2, G_b2]

'''
8. 변수 최적화
원래대로라면 loss를 최대화해야 하지만 최적화에 쓸 수 있는 함수는 minimize뿐이다.
따라서, 최적화하려는 loss_D와 loss_G에 음수 부호를 붙인다.
'''
train_D = tf.train.AdamOptimizer(learning_rate).minimize(-loss_D, var_list=D_var_list)
train_G = tf.train.AdamOptimizer(learning_rate).minimize(-loss_G, var_list=G_var_list)

'''
9. 학습하기
2개의 손실값을 학습해야 해서 코드가 약간 더 추가되었다.
'''
sess = tf.Session()
sess.run(tf.global_variables_initializer())
total_batch = int(mnist.train.num_examples / batch_size)        # 미니배치 설정
loss_val_D, loss_val_G = 0, 0                                   # loss_D, loss_G의 결과를 받을 변수 설정

count_t = time.time()       # 시간 측정 ㅇ시작
for epoch in range(total_epoch) :
    for i in range(total_batch) :
        batch_xs, batch_ys = mnist.train.next_batch(batch_size)
        # get_noise() 함수로 배치 크기만큼 노이즈 만들고 이를 입력
        noise = get_noise(batch_size, n_noise)
        
        # 구분자와 생성자 신경망을 각가 학습
        _, loss_val_D = sess.run([train_D, loss_D], feed_dict={X: batch_xs, Z: noise})
        _, loss_val_G = sess.run([train_G, loss_G], feed_dict={Z: noise})
    
    print("Epoch : %04d" % epoch, end='')
    print('D loss : {:.4}'.format(loss_val_D), end='')
    print('G loss : {:.4}'.format(loss_val_G))
    '''
    10. 학습 결과 확인
    아홉수마다 확인하기
    (※ 아직 반복문 안에 있음)
    노이즈를 만들고 생성자 G에 넣어 결과값 제작
    '''
    if (epoch == 0 or (epoch+1) % 10 == 0) :
        sample_size = 10
        noise = get_noise(sample_size, n_noise)
        samples = sess.run(G, feed_dict={Z: noise})
    # 결과값들을 28 x 28 크기의 가짜 이미지로 만들어 samples 폴더에 저장
    fig, ax = plt.subplots(1, sample_size, figsize=(sample_size, 1))
    for i in range(sample_size) :
        ax[i].set_axis_off()
        ax[i].imshow(np.reshape(samples[i], (28, 28)))
    plt.savefig('samples/{}.png'.format(str(epoch).zfill(3)), bbox_inches='tight')
    plt.close(fig)

print("최적화 완료!")
print("소요 시간 : %.02f" % (time.time() - count_t))




    
    
        

