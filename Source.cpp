#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
using namespace std;

struct Date
{
	int day;
	int mounth;
	int year;
};

struct Person
{
	char name[25];
	char surname[50];
	char parronymic[50];
	Date Birthday;
};

int main()
{
	setlocale(LC_ALL, "Russian");
	time_t t = time(0);
	struct tm * now = localtime(&t);
	/*Date mybirthday = {05,10,1951};
	cout << "DAY " << mybirthday.day << "\n";
	cout << "MOUNTH " << mybirthday.mounth << "\n";
	cout << "YEAR " << mybirthday.year << "\n";*/
	Person vote[5];
	for (int i = 0; i < 5; i++)
	{
		cout << "������� ���� ������� ";
		cin >> vote[i].name;
		cout << "������� ��� ��� ";
		cin >> vote[i].surname;
		cout << "������� ��� �������� ";
		cin >> vote[i].parronymic;
		cout << "������� ���� ������ �������� (��/��/����) ";
		cin >> vote[i].Birthday.day >> vote[i].Birthday.mounth >> vote[i].Birthday.year;
	}
	for (int i = 0; i < 5; i++)
	{
		if (vote[i].Birthday.year < 2003)
			cout << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " ����� ����������\n";
		else
		{
			if (vote[i].Birthday.year == 2003)
			{
				if (vote[i].Birthday.mounth < 9)
					cout << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " ����� ����������\n";
				else
				{
					if (vote[i].Birthday.mounth == 9)
					{
						if(vote[i].Birthday.day <= now->tm_mday)
							cout << "\n" << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " ����� ����������\n";
						else
							cout << "�������� ��� ������� " << i + 1 << " ������� ��������� ��� ������� � �������\n";
					}
					else
						cout << "�������� ��� ������� " << i + 1 << " ������� ��������� ��� ������� � �������\n";
				}
			}
			else
				cout << "�������� ��� ������� " << i + 1 << " ������� ��������� ��� ������� � �������\n";
		}
	}
}