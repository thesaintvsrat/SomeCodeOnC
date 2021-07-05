#include <iostream>
#include <cmath>
using namespace std;

double f(double x)
{
	return (pow(x, 3) / (1 + x + pow(x, 2)));
}

void Trap(double b, double a)
{
	double I, h, n;
	h = 0.1;
	n = (b - a) / h;
	I = h * (f(a) + f(b)) / 2.0;
	for (int i = 1; i <= n - 1; i++)
		I = I + h * f(a + h * i);
	printf("Интеграл по формуле трапеций = %f \n", I);
}

int main()
{
	setlocale(LC_ALL, "rus");
	double a, b, e;
	a = 1.0;
	b = 3.5;
	Trap(b, a);
	system("pause");
	return 0;
}