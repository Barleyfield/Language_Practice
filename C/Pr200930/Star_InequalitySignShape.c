#include <stdio.h>

int main() {
	int space_counter = 0;
	int i=1, j=0;
	int n=5;
			
	for(i=1;i<=n;i++) {
		for(j=0;j<space_counter;j++) {		
			printf(" ");
		}
		printf("*\n");
		
		if(i>(n/2)) {
			space_counter--;
		}
		else {
			if(n%2==0) {
				if(i==(n/2))
					continue;
			}
			space_counter++;			
		}
	}
	return 0;
}