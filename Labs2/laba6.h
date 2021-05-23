#pragma once
#pragma warning(disable: 26495)
#pragma warning(disable: 6385)

#include <iostream>
#include <fstream>
#include <assert.h>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

typedef struct date
{
	int d;
	int m;
	int y;
} date;

typedef struct name
{
	string surn;
	string iniz;
} name;

typedef struct car
{
	name name;
	string mark;
	string number;
	int year;
} car;

vector<car> cars;
vector<car> outCar;
size_t carSize = 0;

void addData()
{
	ifstream fin("data\\laba6Data.txt");

	if (fin.fail())
	{
		cout << "fail" << endl;
		throw std::runtime_error("error");
	}

	string temp;
	size_t i = 0;
	while (!fin.eof())
	{
		fin >> temp;
		i++;
	}
	fin.close();
	fin.open("data\\laba6Data.txt");

	i = 0;

	while (!fin.eof())
	{
		cars.push_back({ "", "", "", "", 0 });
		fin >> cars[i].name.surn;
		fin >> cars[i].name.iniz;
		fin >> cars[i].mark;
		fin >> cars[i].number;
		fin >> cars[i].year;

		i++;
	}
	fin.close();
	
	carSize = i;
}

void printData(const vector<car>& tcars = cars)
{
	cout << " № |" << setw(2) << setw(18) << "ФИО" << setw(18) << "|" << setw(11) <<
		"Марка" << setw(7) << "|" << setw(12) << "Гос. номер"<< setw(4) <<
		"|" << setw(14) << "Год выпуска" << setw(2) << "|" << endl;

	cout << "------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tcars.size(); i++)
	{
			cout << " " << setw(2) << i + 1 << "|\t" << setw(31) << tcars[i].name.surn + " " + tcars[i].name.iniz
				<< "|\t" << " " << setw(8) << tcars[i].mark << "|\t" << " " <<
				setw(8) << tcars[i].number << "|\t" << " " <<
				setw(8) << tcars[i].year << "|\t\n";
	}
	
	cout << "------------------------------------------------------------------------------------------" << endl << endl;
	
	ofstream fout("data\\laba6DataOut.txt");
	fout << " № |" << setw(2) << setw(18) << "ФИО" << setw(18) << "|" << setw(11) <<
		"Марка" << setw(7) << "|" << setw(12) << "Гос. номер" << setw(4) <<
		"|" << setw(14) << "Год выпуска" << setw(2) << "|" << endl;

	fout << "------------------------------------------------------------------------------------------" << endl;

	for (int i = 0; i < tcars.size(); i++)
	{
		fout << " " << setw(2) << i + 1 << "|\t" << setw(31) << tcars[i].name.surn + " " + tcars[i].name.iniz
			<< "|\t" << " " << setw(8) << tcars[i].mark << "|\t" << " " <<
			setw(8) << tcars[i].number << "|\t" << " " <<
			setw(8) << tcars[i].year << "|\t\n";
	}

	fout << "------------------------------------------------------------------------------------------" << endl << endl;
	
	fout.close();
}


void findIf()
{
	outCar.clear();

	cout << "Введите Фамилию и Инициалы владельца для поиска:" << endl;
	cout << "Фамилия=";
	name name;
	cin >> name.surn;

	for (size_t i = 0; i < carSize; i++)
	{
		if (cars[i].name.surn == name.surn)
		{
			outCar.push_back(cars[i]);
			//cout << "Mark: " << cars[i].mark << "; " << "Number: " << cars[i].number << endl;
			//break;
		}
	}

	cout << endl;
	printData(outCar);

}

void sortInArr1()
{
	for (int i = 0; i < carSize - 1; i++)
	{
		for (int j = 0; j < carSize - i - 1; j++)
		{
			string n1 = cars[j].name.surn + cars[j].name.iniz;
			string n2 = cars[j + 1].name.surn + cars[j + 1].name.iniz;
			if (n1 > n2)
			{
				car temp = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = temp;
			}
			else if (n1 == n2)
			{
				if (cars[j].number > cars[j + 1].number)
				{
					car temp = cars[j];
					cars[j] = cars[j + 1];
					cars[j + 1] = temp;
				}
			}
		}
	}
}

void sortInArr2()
{
	for (int i = 0; i < carSize - 1; i++)
	{
		for (int j = 0; j < carSize - i - 1; j++)
		{
			if (cars[j].year < cars[j + 1].year)
			{
				car temp = cars[j];
				cars[j] = cars[j + 1];
				cars[j + 1] = temp;
			}
		}
	}
}

void sortOutArr(vector<car>* tcars = &cars)
{
	for (int i = 0; i < tcars->size() - 1; i++)
	{
		for (int j = 0; j < tcars->size() - i - 1; j++)
		{
			if ((*tcars)[j].mark > (*tcars)[j + 1].mark)
			{
				car temp = (*tcars)[j];
				(*tcars)[j] = (*tcars)[j + 1];
				(*tcars)[j + 1] = temp;
			}
		}
	}
}

void writetofile()
{
	string marks[] = { "Audi", "BMW", "Ford", "Honda", "Hyundai", "Kia", "Lada", "Mazda" };
	ifstream fin("laba6Data.txt");

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
		data[ss] += marks[rand() % 8];
		data[ss] += " ";
		char ch[3];
		int num[3];
		for (size_t i = 0; i < 3; i++)
		{
			ch[i] = rand() % (122 - 97 + 1) + 97;
			num[i] = rand() % 10;
		}

		data[ss] += ch[0];
		data[ss] += to_string(num[0]);
		data[ss] += to_string(num[1]);
		data[ss] += to_string(num[2]);
		data[ss] += ch[1];
		data[ss] += ch[2];
		data[ss] += " ";

		fin >> t;
		data[ss] += t;


		ss++;
	}

	fin.close();

	ofstream fout("data\\laba6Data.txt");
	for (size_t i = 0; i < ss; i++)
	{
		fout << data[i];
		if (i != ss - 1)
			fout << "\n";
	}
	fout.close();
}

int laba6()
{
	//writetofile();
	addData();
	
	int index;
	while (true)
	{
		system("cls");
		cout << "Меню:" << endl;
		cout << "1.Вывести данные" << endl;
		cout << "2.Отсортировать исходный массив по фамилии и инциалам владельца в алфавитном порядке" << endl;
		cout << "3.Отсортировать исходный массив по году выпуска в порядке убывания" << endl;
		cout << "4.Отсортировать выходной массив по марке автомобиля" << endl;
		cout << "5.Найти марку и номер автомобиля по фамилии владельца" << endl;
		cout << "6.Выйти из программы" << endl;
		cout << "Выберите один из пунктов(1-6):";

		cin >> index;
		cout << endl;

		switch (index)
		{
		case 1:
		{
			printData();
		} break;
		case 2:
		{
			sortInArr1();
			printData();
		} break;
		case 3:
		{
			sortInArr2();
			printData();
		} break;
		case 4:
		{
			sortOutArr(&outCar);
			printData(outCar);
		} break;
		case 5:
		{
			findIf();
		} break;
		case 6:
		{
			exit(0);
		} break;
		default:
		{
			cout << "Такого пункта нет!!!" << endl << endl;
		} break;
		}

		system("pause");
	}

	return 0;
}