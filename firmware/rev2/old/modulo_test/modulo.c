#include <stdio.h>

char buffer[10];
void main(void) {
	int result = 0;
	int mybool = 0;
	printf("Hello World\n");
	for(int i = 0; i<100; i++) {
		result = i % 10;
		if(result) mybool = 1;
		else mybool = 0;
		printf("%i Modulo 10 = %i, Bool = %i\n",i,result,mybool);
	}
	exit(0);
}