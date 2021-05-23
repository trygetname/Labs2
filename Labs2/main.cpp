#if 1
#include <Windows.h>

//#include "laba1.h"
//#include "laba2.h"
//#include "laba3.h"
//#include "laba4.h"
#include "laba5.h"
//#include "laba6.h"


int main()
{
	setlocale(0, "ru");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	laba5();

	system("pause");
	return 0;
}
#endif // 0

#if 0

# include <iostream>

# include <fstream>

# include <string>

#include <iomanip>

#include <conio.h>

#include <windows.h>

#include <stdio.h>

using namespace std;

//������� ���������� ������� � �����

//int studcount = 0;

//���� �������� ��������

struct stdata { int d, m, y; };

//��������� ��������

struct student {

	string FIO;

	stdata dr;

};

string textfile;

// ����� ���������� ��������� / \ � ������

std::string dirnameOf(const std::string& fname)

{

	size_t pos = fname.find_last_of("\\/");

	return (std::string::npos == pos)

		? ""

		: fname.substr(0, pos);

}

void ReadFromFile(student x[], int& studcount)

{

	ifstream fin;

	string file;

	string iniz;

	student t;

	file = textfile;

	fin.open(file.c_str());

	if (fin.fail()) { throw std::runtime_error("���� ������ �������."); }

	// ������� ����� ������� � ��������� �����

	studcount = 0;

	string myyyyy;

	while (1)

	{

		fin >> t.FIO >> iniz >> t.dr.d >> t.dr.m >> t.dr.y;

		//cout<< myyyyy<< endl;

		if (fin.fail()) break;

		studcount++;

	}

	fin.close();

	fin.open(file.c_str());

	cout << "���������� �������: " << studcount << endl;

	// ���������� ��������� ������� �������� ������� �� ���������� �����

	for (int i = 0; i < studcount; i++)

	{

		fin >> x[i].FIO >> iniz >> x[i].dr.d >> x[i].dr.m >> x[i].dr.y;

		x[i].FIO = x[i].FIO + " " + iniz;

	}

	fin.close();

	cout << "���� ������ " << endl;

}

void WriteToScreen(student x[], int& studcount)

{

	cout << " � |\t ������� \t\t\t" << "|\t" << "����\t" << "|\t" << "�����\t" << "|\t" << "��� ��������\n" << endl;

	cout << "--------------------------------------------------------------------------------------------------------\n" << endl;

	for (int i = 0; i < studcount; i++) {

		{

			cout << " " << setw(2) << i + 1 << "|\t" << setw(31) << x[i].FIO << "|\t" << " " << setw(8) << x[i].dr.d << "|\t" << " " << setw(8) << x[i].dr.m << "|\t" << " " << setw(8) << x[i].dr.y << "|\t\n";

		}

	}

	cout << "--------------------------------------------------------------------------------------------------------\n" << endl;

}

void WriteToFile(student x[], int& studcount)

{

	ofstream fout;

	string file;

	int i;

	file = textfile;

	fout.open(file.c_str());

	// ������ �� ������������� ����� ����� �����

	if (fout.fail()) {

		cout << file << "�� ���������.\n";

		_getch(); return;

	}

	if (fout.is_open())

	{

		// ����� ��������� ����� �������

		for (i = 0; i < studcount; i++)

		{

			fout << setw(2) << i + 1 << "|\t" << x[i].FIO << "|\t" << " " << x[i].dr.d << "|\t" << " " << x[i].dr.m << "|\t" << " " << x[i].dr.y << "|\t\n";

		}

	}

	fout.close();

	cout << "������ �������� �������� � ����� " << textfile << "\n";

}

int main(int argc, char* argv[])

{

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	student a[20], b[20];

	int ma, mb;

	cout << "������������ ������ �5\n����� ������ � ��������� ��������� � ���������� ���.\n\n";

	//int ma, mb, j;

	// ����� ���� �� ����� debug �������

	textfile = dirnameOf(argv[0]) + "\\text.txt";

	//textfile = "d:\\4\\text.txt";

	cout << "��� �������� �����:" << textfile << "\n";

	SetConsoleCP(1251);

	SetConsoleOutputCP(1251);

	ReadFromFile(a, ma);

	//����� ������� ������ �� �����

	cout << "������ ������:" "\n" << endl;

	WriteToScreen(a, ma);

	mb = 0;

	for (int i = 0; i < ma; i++)

	{

		//������� ������

		if (((a[i].dr.y % 4) == 0) && (((a[i].dr.y % 100) != 0) || ((a[i].dr.y % 400) == 0)))

		{

			b[mb] = a[i];

			mb++;

		}

	}

	//����� ���������������� ������ �� �����

	cout << "��������������� ������:" "\n" << endl;

	WriteToScreen(b, mb);

	textfile = dirnameOf(argv[0]) + "\\text-out.txt";

	WriteToFile(b, mb);

	system("pause");

	return 0;
}
#endif // 0
