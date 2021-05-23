#pragma once
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct date
{
	uint32_t d;
	uint32_t m;
	uint32_t y;
}date_t;

typedef struct student
{
	std::string name;
	date_t birth;
} stud_t;

void printData(stud_t* stud, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stud[i].name << " " << stud[i].birth.d << "." << stud[i].birth.m << "." << stud[i].birth.y << endl;
	}

	cout << endl;
}

void findIf(stud_t* stud, size_t size)
{
	cout << "k=";
	uint32_t k;
	cin >> k;
	
	stud_t t;
	t.birth = { 0 };
	t.name = "";

	for (size_t i = 0; i < size; i++)
	{
		if (stud[i].birth.y == k)
		{
			if (stud[i].birth.m > t.birth.m
				|| (stud[i].birth.m == t.birth.m
					&& stud[i].birth.d > t.birth.d))
			{
				t.birth = stud[i].birth;
				t.name = stud[i].name;
			}

		}
	}
	
	cout << endl;

	if (t.name == "")
	{
		cout << "Ошибка в поиске старшего студента в k-ый год" << endl << endl;
		return;
	}

	cout << "Самый старший студент в " << k << " году: ";
	//cout << t.name << " " << t.birth.d << "." << t.birth.m << "." << t.birth.y << endl;
	printData(&t, 1);
}

int laba4()
{

	cout << "Программа для нахождения самого старшего студента, родившегося в k-ый год" << endl;
	cout << endl;

	size_t size;

	cout << "Введите N (количество студентов):" << endl;
	cout << "N=";
	cin >> size;

	stud_t* s = new stud_t[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "Введите данные студента №" << i + 1 << endl;

		cout << "Имя:";
		string n;
		string iniz;
		cin >> n >> iniz;
		s[i].name = n + " " + iniz;

		cout << "День:";
		cin >> s[i].birth.d;

		cout << "Месяц:";
		cin >> s[i].birth.m;

		cout << "Год:";
		cin >> s[i].birth.y;

		cout << endl;
	}

	cout << "Список всех студентов:" << endl;
	printData(s, size);

	cout << "Введите год k для поиска самого старшего студента:" << endl;
	findIf(s, size);

	cout << endl << endl;

	delete[] s;

	return 0;
}