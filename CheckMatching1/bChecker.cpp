#define _CRT_SECURE_NO_WARNINGS
#include "Stack.h"
#include <fstream>

bool CheckMatching(const char* filename) {
	FILE *fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("Error: 파일이 존재하지 않습니다.\n");
		exit(1);
	}

	int nLine = 1;
	int nChar = 0;
	Stack stack;
	char ch;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\n') 
			nLine++;
		nChar++;
		
		switch (ch) {
		case '(': case '[': case'{':
			stack.push(ch);
			stack.display();
			break;
		case ')': case']': case '}':
			if (stack.isEmpty()) {
				printf("underflow");
				exit(1);
			}
			else {
				int prev = stack.pop();
				stack.display();
				if (ch != prev)
					break;
			}
			break;
		}
	}
	fclose(fp);
	printf("[%s] 파일 검사결과:\n", filename);
	if (!stack.isEmpty())
		printf("Error: 문제발견!(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	else
		printf(" OK: 괄호닫기정상(라인수=%d, 문자수=%d)\n\n", nLine, nChar);
	return stack.isEmpty();
}
void main() {
	CheckMatching("C:\\Users\\김서현\\source\\repos\\CheckMatching_HW\\CheckMatching_HW\\data.txt");

	system("PAUSE");
}