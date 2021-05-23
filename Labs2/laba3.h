#pragma once
#include <iostream>

#include "leaksCheaker.h"

using namespace std;

int iterA = 1;
int iterX = 1;

float** createMatrix(int row, int col)
{
	cout << "Введите матрцицу A" << iterA << ":" << endl;

	float** matrix = new float* [row];

	for (size_t i = 0; i < row; i++)
	{
		matrix[i] = new float[col];
	}

	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << "a" << iterA << "(" << i + 1 << ")(" << j + 1<< ")=";
			cin >> matrix[i][j];
			//matrix[i][j] = rand() % 100 - 50;
		}
	}

	iterA++;

	return matrix;
}

float* createVector(int size)
{
	cout << "Введите вектор X" << iterX << ":" << endl;
	float* vec = new float[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "x" << iterX << "(" << i + 1 << ")=";
		cin >> vec[i];
		//vec[i] = rand() % 100 - 50;
	}

	iterX++;

	return vec;
}

float* mul(float** mat, float* vec, int row, int col)
{
	float* r = new float[row];

	for (size_t i = 0; i < row; i++)
	{
		r[i] = 0.0f;
	}

	for (int i = 0; i < row; i++)
	{
		for (size_t k = 0; k < col; k++)
		{
			r[i] += mat[i][k] * vec[k];

		}
	}

	return r;
}

void vecSum(float* res, float* vec1, float* vec2, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		res[i] = vec1[i] + vec2[i];
	}
}

void printMatrix(float** matrix, int row, int col)
{
	for (size_t i = 0; i < row; i++)
	{
		for (size_t j = 0; j < col; j++)
		{
			cout << setw(4) << matrix[i][j] << " ";
		}

		cout << endl;
	}

	cout << endl;
}

void printVector(float* matrix, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << setw(4) << matrix[i];
		cout << endl;
	}

	cout << endl;
}

int laba3()
{
	leaksChecker();

	int row;
	int col;

	cout << "Программа для нахождения суммы векторов, полученных путем умножения матрицы на вектор" << endl << endl;

	int count;
	cout << "Введите количество матриц A(векторов X)" << endl;
	cout << "Кол-во матриц A(векторов X)=";
	cin >> count;
	cout << endl;

	cout << "Введите кол-во строк в матрицах и векторах:" << endl;
	cout << "Кол-во строк в матрицах и векторах=";
	cin >> row;
	cout << endl;

	cout << "введите кол-во столбцов в матрицах:" << endl;
	cout << "Кол-во столбцов в матрицах=";
	cin >> col;
	cout << endl;

	float*** arrMat = new float** [count];
	float** arrVec = new float* [count];
	float* vector = new float[row] {0};

	for (size_t i = 0; i < count; i++)
	{
		arrMat[i] = createMatrix(row, col);
		cout << endl << endl;
		cout << "Введенная матрица A" << iterA - 1 << ":" << endl;
		printMatrix(arrMat[i], row, col);

		arrVec[i] = createVector(col);
		cout << endl << endl;
		cout << "Введенный вектор X" << iterX - 1 << ":" << endl;
		printVector(arrVec[i], col);
	}

	for (size_t i = 0; i < count; i++)
	{
		float* mulMat = mul(arrMat[i], arrVec[i], row, col);
		cout << "Результат умножения матрицы A" << i + 1 << " на вектор X" << i + 1 << ":" << endl;
		printVector(mulMat, row);

		vecSum(vector, vector, mulMat, row);

		delete[] mulMat;
	}

	cout << "Сумма векторов:" << endl;
	printVector(vector, row);

	delete[] vector;

	for (size_t i = 0; i < count; i++)
	{
		for (size_t j = 0; j < row; j++)
		{
			delete[] arrMat[i][j];
		}

		delete[] arrVec[i];
		delete[] arrMat[i];
	}

	delete[] arrMat;
	delete[] arrVec;
	
	return 0;
}