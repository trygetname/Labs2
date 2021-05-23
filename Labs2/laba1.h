#pragma once
#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::cin;
using std::setw;

void laba1()
{
	setlocale(0, "ru");

	float** mat = nullptr;
	float* b = nullptr;

	cout << "Программа для обхода матрицы по часовой стрелке" << endl;
	cout << endl;
	int n = 0;
	
	cout << "Введите размер матрицы N x N:" << endl;;
	cout << "Введите N=";
	cin >> n;
	cout << endl;

	mat = new float* [n];
	b = new float[n * n];

	for (size_t i = 0; i < n; i++)
	{
		mat[i] = new float[n];
	}

	cout << "Введите элементы матрицы A:" << endl;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << "(" << i << ")(" << j << ")=";
			cin >> mat[i][j];
			//mat[i][j] = rand() % 100;
		}
	}
	cout << endl;

	/*for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << setw(4) << mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << endl;*/

	int step = 1;
	int curIter = 0;
	int d = 0;
	int maxIter = n - 1;
	int k = 0;
	int i = n;
	int j = 0;
	int v = 0;
	bool bl = true;
	int g = 0;

	while (k < n * n)
	{

		if (step == 1)
		{
			i--;
		}
		else if (step == 2)
		{
			j++;
		}
		else if (step == 3)
		{
			i++;
		}
		else if (step == 4)
		{
			j--;
		}
		else
		{
			cout << "Ошибка" << endl;
		}

		if (maxIter - d == curIter)
		{
			step++;
			
			if (bl)
			{
				v++;
				bl = false;

			}
			if (step == 4)
			{
				d++;
			}
			else if (step == 2)
			{
				g++;
				if (g >= 2)
					v++;
			}
			else if (step > 4)
				step = 1;

			curIter = v;
		}
		else
		{
			curIter++;
		}

		b[k] = mat[i][j];
		//cout << b[k] << " ";
		k++;
	}

	cout << endl;

	cout << "Полученная матрца B={ ";
	for (size_t i = 0; i < n * n; i++)
	{
		cout << b[i] << " ";
	}

	cout << "}" << endl;
	cout << endl;

	for (size_t i = 0; i < n; i++)
	{
		delete mat[i];
	}

	delete[] mat;
	delete[] b;
}