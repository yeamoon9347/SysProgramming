#include <stdio.h>

int main() {
	char ch;
	while(1) {
		scanf("%c", &ch);

		if (ch >= 'a' && ch <= 'z') {
			ch -= 32;
			printf("입력한 %c의 대문자는 %c입니다.\n", ch + 32, ch);
		}
		else if (ch >= 'A' && ch <= 'Z') {
			ch += 32;
			printf("입력한 %c의 소문자는 %c입니다.\n", ch - 32, ch);
		}
		else if (ch == '0') {
			break;
		}
	}	
}
