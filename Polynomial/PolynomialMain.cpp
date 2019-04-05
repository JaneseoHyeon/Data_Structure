#include "Polynomial.h"
#include <cstdlib>

void main() {
	Polynomial a, b, c;
	a.read();
	b.read();
	a.display("A = ");
	b.display("B = ");
	c.add(a, b);
	c.display("A+B= ");
	c.sub(a, b);
	c.display("A-B= ");
	c.mult(a, b);
	c.display("A*B= ");

	system("PAUSE");
}