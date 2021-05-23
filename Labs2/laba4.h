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
		cout << "������ � ������ �������� �������� � k-�� ���" << endl << endl;
		return;
	}

	cout << "����� ������� ������� � " << k << " ����: ";
	//cout << t.name << " " << t.birth.d << "." << t.birth.m << "." << t.birth.y << endl;
	printData(&t, 1);
}

int laba4()
{

	cout << "��������� ��� ���������� ������ �������� ��������, ����������� � k-�� ���" << endl;
	cout << endl;

	size_t size;

	cout << "������� N (���������� ���������):" << endl;
	cout << "N=";
	cin >> size;

	stud_t* s = new stud_t[size];

	for (size_t i = 0; i < size; i++)
	{
		cout << "������� ������ �������� �" << i + 1 << endl;

		cout << "���:";
		string n;
		string iniz;
		cin >> n >> iniz;
		s[i].name = n + " " + iniz;

		cout << "����:";
		cin >> s[i].birth.d;

		cout << "�����:";
		cin >> s[i].birth.m;

		cout << "���:";
		cin >> s[i].birth.y;

		cout << endl;
	}

	cout << "������ ���� ���������:" << endl;
	printData(s, size);

	cout << "������� ��� k ��� ������ ������ �������� ��������:" << endl;
	findIf(s, size);

	cout << endl << endl;

	delete[] s;

	return 0;
}