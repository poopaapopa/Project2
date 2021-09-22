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
		cout << "Введите свою фамилию ";
		cin >> vote[i].name;
		cout << "Введите своё имя ";
		cin >> vote[i].surname;
		cout << "Введите своё отчество ";
		cin >> vote[i].parronymic;
		cout << "Введите дату своего рождения (дд/мм/гггг) ";
		cin >> vote[i].Birthday.day >> vote[i].Birthday.mounth >> vote[i].Birthday.year;
	}
	for (int i = 0; i < 5; i++)
	{
		if (vote[i].Birthday.year < 2003)
			cout << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " может голосовать\n";
		else
		{
			if (vote[i].Birthday.year == 2003)
			{
				if (vote[i].Birthday.mounth < 9)
					cout << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " может голосовать\n";
				else
				{
					if (vote[i].Birthday.mounth == 9)
					{
						if(vote[i].Birthday.day <= now->tm_mday)
							cout << "\n" << vote[i].name << " " << vote[i].surname << " " << vote[i].parronymic << " " << vote[i].Birthday.day << " " << vote[i].Birthday.mounth << " " << vote[i].Birthday.year << " может голосовать\n";
						else
							cout << "Кандидат под номером " << i + 1 << " слишком маленький для участия в выборах\n";
					}
					else
						cout << "Кандидат под номером " << i + 1 << " слишком маленький для участия в выборах\n";
				}
			}
			else
				cout << "Кандидат под номером " << i + 1 << " слишком маленький для участия в выборах\n";
		}
	}
}