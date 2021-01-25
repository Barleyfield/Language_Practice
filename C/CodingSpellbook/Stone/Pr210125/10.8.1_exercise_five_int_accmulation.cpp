/*
* 코딩마법서 10.8.1 연습문제
* 5개의 정수가 주어지면 주어진 정수의 누적 결과를 각 줄에 차례대로
* 출력하는 프로그램을 작성하라.
* Input Form : 1 이상 100 이하의 5개의 정수가 각 줄에 주어진다.
* Output Form : 첫째 줄에는 1번째로 입력한 정수의 누적 결과를 출력하여라.
*               둘째 줄에는 앞에서 누적된 결과에 2번째로 입력한 정수의 누적 결과를 출력하여라.
*               (다섯째까지 반복)
*/

#pragma warning(disable:4996)
#include <cstdio>
int main() {
	int input = 0, result = 0, i = 0;
	int result_arr[5] = { 0, };			// 결과 배열(result_arr) 이름은 최종 결과 변수(result)의 이름과 다르게
	for (i = 0; i < 5; i++) {
		scanf("%d", &input);
		result += input;
		result_arr[i] = result;
	}
	for (i = 0; i < sizeof(result_arr) / sizeof(int); i++) {
		printf("%d\n", result_arr[i]);
	}
	printf("결과 : %d\n", result);
	return 0;
}