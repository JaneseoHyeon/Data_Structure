#pragma once
#include <cstdio>
#define MAX_DEGREE 80
class Polynomial {
	int degree;
	float coef[MAX_DEGREE];
public:
	Polynomial() { degree = 0; }

	void read() {
		printf("���׽��� �ְ� ������ �Է��Ͻÿ�: ");
		scanf_s( "%d", &degree ); //&degree ������ �ּҸ� �Ѱ���
		printf("�� ���� ����� �Է��Ͻÿ�(�� %d��): ", degree+1);
		for (int i = 0; i <= degree; i++)
			scanf_s( "%f", coef+i );
	}

	void display(const char *str = " Poly = ") {
		printf("\t%s", str);
		for (int i = 0; i < degree; i++) {
			if (coef[i] == 1)
				printf(" x^%d +", degree - i);
			else if (coef[i] == 0)
				printf("");
			else
				printf("%5.1f x^%d +", coef[i], degree - i);
		}
		printf("%4.1f\n", coef[degree]);
	}

	void add(Polynomial a, Polynomial b) {
		if (a.degree > b.degree) {
			*this = a; //a ���׽� ��ü�� �ڱ� ��ü�� ����
			for (int i = 0; i <= b.degree; i++)
				coef[i + (degree - b.degree)] += b.coef[i];
		}
		else {
			*this = b;
			for (int i = 0; i <= a.degree; i++)
				coef[i + (degree - a.degree)] += a.coef[i];
		}
		trim();
	}

	void sub(Polynomial a, Polynomial b) {
		b.negate();
		add(a, b);
	}

	void mult(Polynomial a, Polynomial b) {
		degree = a.degree + b.degree;
		for (int i = 0; i <= degree; i++)
			coef[i] = 0;
		for (int i = 0; i <= degree; i++)
			for (int j = 0; j <= b.degree; j++)
				coef[i + j] += a.coef[i] * b.coef[j];
		trim();
	}

	void trim() {
		int nZero = 0;
		while (coef[nZero]==0)
			nZero++;
		if (nZero!=0) {
			degree -= nZero;
			for (int i = 0; i <= degree; i++)
				coef[i] = coef[i + nZero];
		}
	}

	bool isZero() { return degree == 0; }

	void negate() {
		for (int i = 0; i <= degree; i++)
			coef[i] = -coef[i];
	}
};