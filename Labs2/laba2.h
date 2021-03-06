#pragma once

#include <iostream>

using namespace std;

float sum(float* x, float* y, int len)
{
	float s = 0;
	for (size_t i = 0; i < len; i++)
	{
		s += abs(x[i] + y[i]);
	}

	return s;
}

void input(float* x, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << "(" << i + 1 << ")=";
		cin >> x[i];

		//x[i] = rand() % 200 - 100;
	}

	cout << endl;
}

void output(float* x, int len)
{
	for (size_t i = 0; i < len; i++)
	{
		cout << x[i] << " ";
	}
	cout << endl;
}

void laba2()
{

	cout << "Программа для нахождения p = Sum(|a + b|) + Sum(|b + c|) + Sum(|a + c|)" << endl;
	cout << endl;

	int len;
	cout << "Введите длину массивов:" << endl;
	cin >> len;
	cout << endl;

	float* a = new float[len];
	float* b = new float[len];
	float* c = new float[len];

	cout << "Введите длину массива A:" << endl;
	input(a, len);
	cout << "Введите длину массива B:" << endl;
	input(b, len);
	cout << "Введите длину массива C:" << endl;
	input(c, len);

	//output(a, len);
	//output(b, len);
	//output(c, len);

	cout << endl;

	float p = sum(a, b, len) + sum(b, c, len) + sum(a, c, len);
	cout << "Результат сложений: ";
	cout << p << endl;

	delete[] a;
	delete[] b;
	delete[] c;
}