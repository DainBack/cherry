#include<stdio.h>
#include<string.h>
#define Size 1000

int main(void) {
	char str[Size];
	int key;
	printf("Enter text to encrypt(However, type in capital letters) : ");
	gets_s(str);
	printf("Enter to Key value : ");
	scanf_s("%d", &key);

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			str[i] += key;
			if (str[i] >= 'A' && str[i] <= 'Z')
				continue;
			else if (str[i] > 'Z') {
				if (key > 0)
					str[i] = str[i] - 26;
				else
					str[i] = str[i] + 26;
			}
			else if (str[i] < 'A') {
				if (key > 0)
					str[i] = str[i] + 26;
				else
					str[i] = str[i] - 26;
			}
				

		 }

	}
	printf("An encrypted sentence : %s\n", str);
}