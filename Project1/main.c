/*Функция возведения числа в степень*/
double Stepen(double x, int st)
{
	double res;
	int i;
	res = 1.0;
	if (st == 0) {
		return 1;
	}
	else if (st == 1) {
		return x;
	}

	else
		for (i = 1; i <= st; i++)
		{
			res = res * x;
		}
	return(res);
}
/* Функция нахождения факториала числа */
double Factorial(int n) {
	if (n < 2)
		return 1;
	return n * Factorial(n - 1);
}

/* Функция нахождения модуля числа */
double Module(double x) {
	if (x > 0)
		return x;
	else return x * -1;
}

/* Функция нахождения экспоненты разложением в ряд Тейлора */
double Exponent(double x) {
	int k;
	double exp;
	exp = 0.0;
	for (k = 0; k <= 50; k++)
	{
		exp = exp + (Stepen(x,  k ) / Factorial(k));
	}

	return(exp);
}

/*Функция для проверки точности вычисления косинуса*/
int Test_exp() {
	int r;
	r = 0;

	r = r || (Module(Exponent(0) - 1.0) >= 0.00001);
	r = r || (Module(Exponent(1) - 2.71828) >= 0.00001);
	r = r || (Module(Exponent(2) - 7.38905) >= 0.00001);
	r = r || (Module(Exponent(3) - 20.08553) >= 0.00001);
	r = r || (Module(Exponent(4) - 54.59815) >= 0.00001);
	return r;
}

int main(int argc, char** argv) {
	return Test_exp();
}