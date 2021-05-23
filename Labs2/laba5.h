#pragma once
#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>

using namespace std;

typedef struct date
{
	uint32_t d;
	uint32_t m;
	uint32_t y;
}date_t;

typedef struct student
{
	std::string name = "";
	date_t birth;
} stud_t;

stud_t* createArr(size_t size)
{
	return new stud_t[size];
}

void addData(stud_t** stud, size_t& size, std::string name, date_t birth)
{
	size++;
	stud_t* newArr = createArr(size);

	for (size_t i = 0; i < size - 1; i++)
	{
		//cout << (*stud)[i].name << endl;
		newArr[i] = (*stud)[i];
	}

	delete[] *stud;


	newArr[size - 1].name = name;
	newArr[size - 1].birth = birth;

	*stud = createArr(size);
	for (size_t i = 0; i < size; i++)
	{
		(*stud)[i] = newArr[i];
	}

	delete[] newArr;
}

void printData(stud_t* stud, size_t size)
{
	ofstream fout("dataOut.txt");
	for (size_t i = 0; i < size; i++)
	{
		std::cout << stud[i].name << " " << stud[i].birth.d << "." << stud[i].birth.m << "." << stud[i].birth.y << endl;
		fout << stud[i].name << " " << stud[i].birth.d << "." << stud[i].birth.m << "." << stud[i].birth.y << '\n';
	}

	fout.close();
}

void printData1(stud_t* stud, size_t size)
{
	cout << " № |" << setw(2) << setw(18) << "ФИО" << setw(18) << "|" << setw(11) <<
		"День" << setw(7) << "|" << setw(10) << "Месяц" << setw(6) <<
		"|" << setw(10) << "Год" << setw(6) << "|" << endl;

	cout << "------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		cout << " " << setw(2) << i + 1 << "|\t" << setw(31) << stud[i].name
			<< "|\t" << " " << setw(8) << to_string(stud[i].birth.d) << "|\t" << " " <<
			setw(8) << to_string(stud[i].birth.m) << "|\t" << " " <<
			setw(8) << to_string(stud[i].birth.y) << "|\t\n";
	}

	cout << "------------------------------------------------------------------------------------------" << endl << endl;

	ofstream fout("dataOut.txt");
	fout << " № |" << setw(2) << setw(18) << "ФИО" << setw(18) << "|" << setw(11) <<
		"День" << setw(7) << "|" << setw(10) << "Месяц" << setw(6) <<
		"|" << setw(10) << "Год" << setw(6) << "|" << endl;

	fout << "------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < size; i++)
	{
		fout << " " << setw(2) << i + 1 << "|\t" << setw(31) << stud[i].name
			<< "|\t" << " " << setw(8) << to_string(stud[i].birth.d) << "|\t" << " " <<
			setw(8) << to_string(stud[i].birth.m) << "|\t" << " " <<
			setw(8) << to_string(stud[i].birth.y) << "|\t\n";
	}

	fout << "------------------------------------------------------------------------------------------" << endl << endl;
	fout.close();

}

void findIf(stud_t* stud, size_t size)
{
	cout << "Введите k:";
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
					&& stud[i].birth.d >= t.birth.d))
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

	cout << "Самый старший студент в " << k << " году " << endl << endl;
	printData1(&t, 1);
}

void writetofile()
{
	ifstream fin("data.txt");

	vector<string> data;
	int ss = 0;
	while (!fin.eof())
	{
		data.push_back("");

		string t = "";

		fin >> t;
		data[ss] += t;
		data[ss] += " ";
		fin >> t;
		data[ss] += t;
		data[ss] += " ";
		data[ss] += to_string(rand() % (28 - 1) + 1);
		data[ss] += " ";
		data[ss] += to_string(rand() % (12) + 1);
		data[ss] += " ";
		fin >> t;
		data[ss] += t;
		ss++;
	}

	fin.close();

	ofstream fout("data.txt");
	for (size_t i = 0; i < ss; i++)
	{
		fout << data[i];
		if (i != ss - 1)
			fout << "\n";
	}
	fout.close();
}

int laba5()
{
	//writetofile();
	size_t size = 0;

	stud_t* s = createArr(size);

	ifstream fin("data.txt");
	
	while (!fin.eof())
	{
		string name;
		string t;
		
		fin >> t;
		name = t + " ";

		fin >> t;
		name += t;

		uint32_t date[3];

		fin >> date[0];
		fin >> date[1];
		fin >> date[2];

		addData(&s, size, name, { date[0], date[1], date[2] });
	}

	fin.close();

	cout << "Программа для нахождения самого старшего студента, родившегося в k-ый год" << endl;
	cout << endl;
	cout << "Список всех студентов" << endl << endl;
	printData1(s, size);
	cout << endl;
	cout << "Введите год k для поиска самого старшего студента:" << endl;
	findIf(s, size);
	cout << endl << endl;

	delete[] s;

	return 0;
}