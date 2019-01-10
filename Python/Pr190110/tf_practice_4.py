"""

3분 딥러닝 텐서플로맛
선형 회귀 모델 구현하기 

"""
import tensorflow as tf

x_data = [1, 2, 3]
y_data = [1, 2, 3]

# x와 y의 상관관계를 설명하기 위한 변수들인 W와 b를 각각 -1.0부터 1.0 사이의 균등분포를 가진 무작위 값으로 초기화
W = tf.Variable(tf.random_uniform([1], -1.0, 1.0))
b = tf.Variable(tf.random_uniform([1], -1.0, 1.0))

# 자료를 입력받을 플레이스홀더를 설정
X = tf.placeholder(tf.float32, name="X")
Y = tf.placeholder(tf.float32, name="Y")

# X와 Y의 상관관계를 분석하기 위한 수식 작성
# W와의 곱과 b와의 합을 통해 X와 Y의 관계를 설명
# W = Weight. 가중치 / b = bias. 편향
hypothesis = W*X + b


# 손실 함수 : 한 쌍(x,y)의 데이터에 대한 손실값 계산
# 손실값 : 실제 값과 모델로 예측한 값의 차이 정도
# 학습 : 이 손실값을 최소화하는 W와 b 구하기
cost = tf.reduce_mean(tf.square(hypothesis - Y))

# 경사하강법 최적화 함수를 이용해 손실값을 최소화하는 연산 그래프 생성
optimizer = tf.train.GradientDescentOptimizer(learning_rate=0.1)
train_op = optimizer.minimize(cost)

# 모델을 만들었으니 그래프를 실행해 학습시킨다.
# with로 세션 블록을 만들고 세션 종료를 자동으로 처리
with tf.Session() as sess :
    sess.run(tf.global_variables_initializer())
    for step in range(100) :
        _, cost_val = sess.run([train_op, cost], feed_dict={X: x_data, Y: y_data})
        print(step, cost_val, sess.run(W), sess.run(b))
    # 이제 이 학습을 써먹어보자.
    # 위에서 X가 1,2,3일 때 Y도 똑같이 1,2,3이 나온다고 하였다. 그렇다면, 저기에 없던 5와 2.5를 넣으면 과연 어떻게 나올까?
    print("X: 5라면 Y는? : ", sess.run(hypothesis, feed_dict={X: 5}))
    print("X: 2.5라면 Y는? : ", sess.run(hypothesis, feed_dict={X: 2.5}))








