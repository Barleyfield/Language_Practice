#include <stdio.h>

int main() {
	int euler1=0, euler2=0, euler3=0, euler4=0, eulerResult=0;
    int euclid1=0, euclid2=0, euclid3=0, euclid4=0, euclidResult=0;
    scanf("%d %d %d %d", &euler1, &euler2, &euler3, &euler4);
    scanf("%d %d %d %d", &euclid1, &euclid2, &euclid3, &euclid4);
    eulerResult = euler1+euler2+euler3+euler4;
    euclidResult = euclid1+euclid2+euclid3+euclid4;
    if(eulerResult >= euclidResult) {
        printf("%d\n", eulerResult);
    } else {
        printf("%d\n", euclidResult);
    }

	return 0;
}