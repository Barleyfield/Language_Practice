#include <stdio.h>

struct sawon {
    char name[10];
    char jikwi[10];
    int pay;
};

struct sawon data;

int main() {
    printf("Name : ");
    scanf("%s", data.name);
    printf("Rank : ");
    scanf("%s", data.jikwi);
    printf("Pay : ");
    scanf("%d", &data.pay);

    printf("\n\n");

    printf("Name : %s\n", data.name);
    printf("Rank : %s\n", data.jikwi);
    printf("Pay : %d\n", data.pay);
}