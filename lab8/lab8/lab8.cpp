


#include <iostream>
#include <math.h>
#include <iomanip>
#include <string>

using namespace std;

typedef double (*uf)(double, double, int&);

void tabl(double, double, double, double, uf);
bool sravnenie(double num1, double num2, double eps);
unsigned int fac(unsigned int el);
double y(double, double, int&);
double s(double, double, int&);
double y3(double, double, int&);
double s3(double, double, int&);
double y7(double, double, int&);
double s7(double, double, int&);

int main()
{
	setlocale(LC_ALL, "");


	{
		double a = -0.9;
		double b = 0.9;
		double eps = 0.001;
		double h = 0.3;

		cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, y);
		cout << endl;
		cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, s);

	
	}

	cout << "\n\n_________________________________________\n\n";
	
	{
		double a = -0.9;
		double b = 0.9;
		double eps = 0.0001;
		double h = 0.3;

		cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, y3);
		cout << endl;
		cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, s3);

		
	}

	cout << "\n\n_________________________________________\n\n";

	{
		double a = -0.5;
		double b = 0.5;
		double eps = 0.00001;
		double h = 0.1;

		cout << setw(8) << "x" << setw(15) << "y(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, y7);
		cout << endl;
		cout << setw(8) << "x" << setw(15) << "s(x)" << setw(10) << "k" << endl;
		tabl(a, b, h, eps, s7);


	}

	return 0;


}

void tabl(double a, double b, double h, double eps, uf fun)
{
	int k = 0;
	double sum;

	for (double x = a; x <= b; x += h)
	{
		if (x > -0.1 && x < 0.1)
		{
			sum = 0;
			k = 0;
			x = 0;
			cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
		}
		else
		{
			sum = fun(x, eps, k);
			cout << setw(8) << x << setw(15) << sum << setw(10) << k << endl;
		}
		
	}
}

double y(double x, double eps, int& k)
{
	return (0.5 * log((1.0 + x) / (1.0 - x)));
}

double s(double x, double eps, int& k)
{
	double a, c, sum;


	a = c = x;
	k = 1;
	sum = x;


	while (fabs(c) > eps && k != 99)
	{
		c = (pow(x, (2.0 * k + 1.0))) / (2 * k + 1);
		sum += c;
		k++;
	}

	return sum;
}


double y3(double x, double eps, int& k)
{
	return pow(1 + x, 1 / 3.);
}

double s3(double x, double eps, int& k)
{
	double a, c, sum, b, f, l;
	a = c = x;
	k = 2;
	sum = 1 + x / 3.;

	while (fabs(c)>eps && k != 99)
	{
		a = pow(-1, k - 1);
		b = pow(3, k) * fac(k);
		f = 3 * k - 4;
		l = pow(x, k);
		c = a * (f / b) * l;
		sum += c;
		k++;
	}
	return sum;
}

double y7(double x, double eps, int& k)
{
	return 0.25*(log((1+x)/(1-x)))- 0.5*(atan(x));
}

double s7(double x, double eps, int& k) {
double a, c, sum, b, f, l;
a = c = x;
k = 1;
sum = 0;

while (fabs(c) > eps && k != 99)
{

	c = (pow(x, (4*k-1))/(4*k-1));
	sum += c;
	k++;
}
return sum;
}



unsigned int fac(unsigned int el)
{
	if (el == 0)
		return 1;
	return el * fac(el - 1);
}



