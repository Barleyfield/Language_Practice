/*
* 코딩마법서 15.3.1 연습문제
* 점수 S가 주어지면 점수에 해당하는 학점을 구하는 프로그램을 작성하여라.
* 각 점수에 대한 구간별 학점은 아래와 같다.
* |   점수(S)  | 학점 |
* |:----------:|:----:|
* | 90<=S<=100 |   A  |
* |  80<=S<90  |   B  |
* |  70<=S<80  |   C  |
* |  60<=S<70  |   D  |
* |    S<60    |   F  |
* Input Form : 첫째 줄에 0 이상 100 이하의 1개의 정수 S가 주어진다.
* Output Form : 입력으로 주어진 점수 S에 해당하는 학점을 영문 알파벳 대문자로 첫째 줄에 출력하여라.
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int s = 0;
	scanf("%d", &s);
	switch (s / 10) {
	case 10:
		printf("A\n");
		break;
	case 9:
		printf("A\n");
		break;
	case 8:
		printf("B\n");
		break;
	case 7:
		printf("C\n");
		break;
	case 6:
		printf("D\n");
		break;
	default:
		printf("F\n");
		break;
	}
	return 0;

}