#include<stdio.h>
#include<stdlib.h>
#define SIZE 8

void convertBi(int num);
void convertBy(double num);

int main() {
	int n;
	int s;
	double t;

	printf("Please press Number 1 if there are integer or press Number 2 if there are real number>>");
	scanf_s("%d", &s);

	if (s != 1 && s != 2) printf("Please re-enter!\n");

	switch (s) {
	case 1:
		while (1) {
			printf("Please enter an integer greater than or equal to 1 >> ");
			scanf_s("%d", &n);
			printf("%d is changed to Hexadecimal %x\n\n", n, n);
			convertBi(n);

			if (n < 1)  {printf("You entered incorrectly\n"); break;}

		}
		break;

	case 2:
		while (1) {

			printf("Please enter a real number less than 1 >> \n");
			scanf_s("%lf", &t);

			printf("%lf is changed to Hexadecimal %x\n\n", t, (double)t);
			convertBy(t);

			if (t > 1)  printf("You entered incorrectly \n");
			break;


		}

		break;
	}
	return 0;
}

void convertBi(int num) {
	int i;
	int q[SIZE] = { 0 };


	if (num == 1 && num == 0) printf("%d", num);

	if (num > 1) { 

		for (i = 0; num > 1; i++) { 
			q[i] = num % 2; 
			num /= 2;   
			if (num == 0) break;
		}
		q[i] = num; 

		for (i = SIZE - 1; i >= 0; i--)
			printf("%d", q[i]);

	}

}

void convertBy(double num) {
	int i = 12, temp;
	int str[16] = { 0 };


	if (num == 1 && num == 0) printf("%d", num);
	temp = num - (int)num;
	num = num - temp;

	for (int j = 0; ; j++) {
		if (num < 1) {
			num = num * 2;
			if (num < 1) str[j] = 0; 
			else if (num > 1) 
				str[j] = 1; 
		}
		else if (num > 1) {
			num = num - 1;
			j--;
		}
		if (j > 12) break;
	}

	printf("Binary number = 0.");
	for (int k = 0; k < 16; k++)
		printf("%d", str[k]);
	printf("\n");


}