/*Создать проект Academy, в которм реализовать классы Student, Teacher и Graduate (Дипломник)
   Подумать, как сюда применить наследование.*/

#include<iostream>
using namespace std;

class Person
{
	char* name;
	char* FamilyName;
public:
	char* get_name() const
	{
		return name;
	}
	char* get_FamilyName() const
	{
		return FamilyName;
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
	explicit Person() :name(new char[50]{}), FamilyName(new char[50]{})
	{
		cout << "Default Constructor Person:\t" << this << endl;
	}
	Person(const char str1[], const char str2[]) :Person()
	{
		for (int i = 0; str1[i]; i++)
		{
			this->name[i] = str1[i];
		}
		for (int i = 0; str2[i]; i++)
		{
			this->FamilyName[i] = str2[i];
		}
		cout << "Constructor Person:\t" << this << endl;
	}
	~Person()
	{
		delete[] this->name;
		delete[] this->FamilyName;
		cout << "Destructor Person:\t" << this << endl;
	}
	void Print() const
	{
		cout << "Name: " << name << endl;
		cout << "Surname: " << FamilyName << endl;
	}

};

class Student:public Person
{
	int course; // курс от 1 до 5
	int rate; // рейтинг от 0 до 100
public:	
	int get_course() const
	{
		return course;
	}
	int get_rate() const
	{
		return rate;
	}
	void set_course(const int course)
	{
		if (course <= 1) this->course = 1;
		else if (course >= 5) this->course = 5;
		else this->course = course;
	}
	void set_rate(const int rate)
	{
		if (rate <= 0) this->rate = 0;
		else if (rate >= 100) this->rate = 100;
		else this->rate = rate;
	}

	Student():Person()
	{	
		set_course(1);
		set_rate(0);
		cout << "Default Constructor Student:\t" << this << endl;
	}
	
	Student(const int course, const int rate)
	{
		set_course(course);
		set_rate(rate);
		cout << "Constructor Student:\t" << this << endl;
	}
	~Student()
	{
		cout << "Destructor Student:\t" << this << endl;
	}
	void Print() const
	{
		Person::Print();
		cout << "Course: " << course << endl;
		cout << "Rate: " << rate << endl;
	}
	void operator=(const Person& other)
	{
		this->set_name(other.get_name());
		this->set_FamilyName(other.get_FamilyName());
	}
};
class Teacher :public Person
{
	char* lesson;
public:
	char* get_lesson() const
	{
		return lesson;
	}	
	void set_lesson(const char lesson[])
	{
		for (int i = 0; this->lesson[i]; i++)
		{
			this->lesson[i] = '\0';
		}
		for (int i = 0; lesson[i]; i++)
		{
			this->lesson[i] = lesson[i];
		}
	}
	Teacher() :Person()
	{
		this->lesson = new char[200]{};
		cout << "Default Constructor Teacher:\t" << this << endl;
	}

	Teacher(const char str[]):Teacher()
	{
		for (int i = 0; str[i]; i++)
		{
			this->lesson[i] = str[i];
		}
		cout << "Constructor Teacher:\t" << this << endl;
	}
	~Teacher()
	{
		delete[] lesson;
		cout << "Destructor Teacher:\t" << this << endl;
	}
	void Print() const
	{
		Person::Print();
		cout << "Lesson: " << lesson << endl;
		
	}
	void operator=(const Person& other)
	{
		this->set_name(other.get_name());
		this->set_FamilyName(other.get_FamilyName());
	}
};

class Graduate :public Student
{
	char* diplom; // наименование дипломной работы
	int result;  // процент завершенности дипломной работы от 0 до 100
public:
	char* get_diplom() const
	{
		return diplom;
	}
	int get_result() const
	{
		return result;
	}
	void set_diplom(const char diplom[])
	{
		for (int i = 0; this->diplom[i]; i++)
		{
			this->diplom[i] = '\0';
		}
		for (int i = 0; diplom[i]; i++)
		{
			this->diplom[i] = diplom[i];
		}
	}
	void set_result(const int result)
	{
		if (result <= 0) this->result = 0;
		else if (result >= 100) this->result = 100;
		else this->result = result;
	}
	Graduate() :Student()
	{
		this->diplom = new char[200]{};
		this->result = 0;
		this->set_course(5);
		cout << "Default Constructor Graduate:\t" << this << endl;
	}

	Graduate(const char str[], const int result) :Graduate()
	{
		for (int i = 0; str[i]; i++)
		{
			this->diplom[i] = str[i];
		}
		this->set_result(result);
		cout << "Constructor Graduate:\t" << this << endl;
	}
	~Graduate()
	{
		delete[] diplom;
		cout << "Destructor Graduate:\t" << this << endl;
	}
	void Print() const
	{
		Student::Print();
		cout << "Тема дипломной работы: " << diplom << endl;
		cout << "Процент завершенности дипл. работы: " << result << endl;

	}
	void operator=(const Student& other)
	{
		this->set_name(other.get_name());
		this->set_FamilyName(other.get_FamilyName());
		this->set_rate(other.get_rate());
	}
};

void main()
{
	setlocale(LC_ALL, "");
	int x,y;
	char* str1 = new char[50]{};
	char* str2 = new char[50]{};
	char* str3 = new char[200]{};
	char* str4 = new char[200]{};
	cout << "Введите данные студента: " << endl;
	cout << "Имя: "; cin >> str1;
	cout << "Фамилия: "; cin >> str2;
	Person First(str1, str2); 
	cout << "Курс (от 1 до 5): "; cin >> x;	
	cout << "Рейтинг (от 0 до 100): "; cin >> y;
	Student Second(x,y);
	Second = First;
	Second.Print();
	cout << endl;
	cout << "Введите данные преподавателя: " << endl;
	cout << "Имя: "; cin >> str1;
	cout << "Фамилия: "; cin >> str2;
	Person Third(str1, str2);
	cout << "Учебный предмет: "; cin >> str3;
	Teacher Fourth(str3);
	Fourth = Third;
	Fourth.Print();
	cout << endl;
	cout << "Введите данные дипломника: " << endl;
	cout << "Имя: "; cin >> str1;
	cout << "Фамилия: "; cin >> str2;
	Person Fifth(str1, str2);
	cout << "Рейтинг (от 0 до 100): "; cin >> y;
	Student Sixth(5, y);
	Sixth = Fifth;
	cout << "Введите тему дипломной работы: "; cin >> str4;
	cout << "Введите процент выполнения дипломной работы: "; cin >> x;
	Graduate Seventh(str4, x);
	Seventh = Sixth;
	Seventh.Print();

	/*Vasia.set_name(str2);            //Проверка set-методов
	Vasia.set_FamilyName(str1);
	Vasia.Print();*/                
	delete[] str1;
	delete[] str2;
	delete[] str3;
	delete[] str4;
}