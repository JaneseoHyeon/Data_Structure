#define _CRT_SECURE_NO_WARNINGS
#include "Stack2.h"

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
	bool singleQuotation = true;
	bool doubleQuotation = true;
	bool remark = true;

	while ((ch = getc(fp)) != EOF) {
		if (ch == '\'' && singleQuotation == true)
			singleQuotation = false;
		else if (ch == '\'')
			singleQuotation = true;

		if (ch == '\"' && doubleQuotation == true)
			doubleQuotation = false;
		else if (ch == '\"')
			doubleQuotation = true;

		if (ch == '/' && getc(fp) == '*' && remark == true)
			remark = false;
		else if (ch == '*' && getc(fp) == '/' && remark == false)
			remark = true;
		else if (ch == '/')
			remark = false;

		if ((ch == '[' || ch == '(' || ch == '{') && singleQuotation == true && doubleQuotation == true && remark == true)
			stack.push(ch);
		else if ((ch == ']' || ch == ')' || ch == '}') && singleQuotation == true && doubleQuotation == true && remark == true) 
		{
			int prev = stack.pop();
			if ((ch == ']' && prev != '[')
				|| (ch == ')' && prev != '(')
				|| (ch == '}' && prev != '{')) break;
		}
		if (ch == '\n') {
			nLine++;
			remark = true;
		}
		nChar++;
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
	CheckMatching("C:\\Users\\김서현\\source\\repos\\CheckMatching_HW2\\CheckMatching_HW2\\03장-CheckBracketMain.cpp");

	system("PAUSE");
}