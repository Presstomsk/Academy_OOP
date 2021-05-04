/*Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate (Дипломник)
   Подумать, как сюда применить наследование.*/

#include<iostream>
using namespace std;

class Student
{
	char* name;
	char* FamilyName;
	int course; // курс от 1 до 5
	int rate; // рейтинг от 0 до 100
public:
	char* get_name() const
	{
		return name;
	}
	char* get_FamilyName() const
	{
		return FamilyName;
	}
	int get_course() const
	{
		return course;
	}
	int get_rate() const
	{
		return rate;
	}
	void set_course(int course)
	{
		if (course <= 1) this->course = 1;
		else if (course >= 5) this->course = 5;
		else this->course = course;
	}
	void set_rate(int rate)
	{
		if (rate <= 0) this->rate = 0;
		else if (rate >= 100) this->rate = 100;
		else this->rate = rate;
	}
	void set_name(const char name[])
	{
		for (int i = 0; this->name[i]; i++)
		{
			this->name[i] = '\0';
		}
		for (int i = 0; name[i]; i++)
		{
			this->name[i] = name[i];
		}
	}
	void set_FamilyName(const char FamilyName[])
	{
		for (int i = 0; this->FamilyName[i]; i++)
		{
			this->FamilyName[i] = '\0';
		}
		for (int i = 0; FamilyName[i]; i++)
		{
			this->FamilyName[i] = FamilyName[i];
		}
	}
	explicit Student():name(new char[50]{}), FamilyName(new char[50]{}), course(1), rate(0)
	{
		cout << "Default Constructor:\t" << this << endl;
	}
	explicit Student(const char str1[], const char str2[]):Student()
	{
		for (int i = 0; str1[i]; i++)
		{
			this->name[i] = str1[i];
		}
		for (int i = 0; str2[i]; i++)
		{
			this->FamilyName[i] = str2[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	~Student()
	{
		delete[] this->name;
		delete[] this->FamilyName;
		cout << "Destructor:\t\t" << this << endl;
	}
	void Print() const
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << FamilyName << endl;
		cout << "Course: " << course << endl;
		cout << "Rate: " << rate << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int x;
	char* str1 = new char[50]{};
	char* str2 = new char[50]{};
	cout << "Введите данные: " << endl;
	cout << "Имя: "; cin >> str1;
	cout << "Фамилия: "; cin >> str2;
	Student Vasia(str1, str2);
	cout << "Курс (от 1 до 5): "; cin >> x;
	Vasia.set_course(x);
	cout << "Рейтинг (от 0 до 100): "; cin >> x;
	Vasia.set_rate(x);
	Vasia.Print();
	/*Vasia.set_name(str2);            //Проверка set-методов
	Vasia.set_FamilyName(str1);
	Vasia.Print();*/                
	delete[] str1;
	delete[] str2;
}