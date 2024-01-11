#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

struct pers {

	string name;
	string surname;
	string secondname;
	string data1;
	string data2;
	string data3;
	
	public: 
		string sex ;
	
	void Print() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		
		cout << "ФИО = " << surname<<" " <<name<< " " << secondname<<  "\n";
		
		cout << "Дата рождения  = " << data1 <<":" << data2 <<":" << data3 << "\n";
		cout << "Пол = " << sex<<"\n"; 
	
		cout << "------------------------------------------------" << "\n";
	}
	void add() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Имя = ";
		cin >> name;
		cout << "Фамилия = ";
		cin >> surname;
		cout << "Отчество = ";
		cin >> secondname;
		cout << " Ваша дата рождения (дд:мм:гггг) "<<endl;
		cout << "День = "; cin >> data1;
		cout << "Месяц= "; cin >> data2;
		cout << "Год= "; cin >> data3;
		cout << "Ваш пол (М, Ж) = "; cin >> sex;

		if (sex == "М") {
			cout << "Ваш пол = Мужской "<<endl;
			sex = "М";
		};
		if (sex == "Ж") {
			cout << "Ваш пол = Женский "<<endl;
			sex = "Ж";
		}
	}
};

struct hub {


	
	pers gr[30];
	int count = 0;
	int M{};
	int n = count;
	int i = 0;
	void gr_Print() {
		
		for (int i = 0; i < count; i++) {
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-" << endl;
			cout << "[" << i << "]" << endl;
			gr[i].Print();
		}
	}
	void gr_Add() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);

		
		cout << "Напишите кол-во елементов = ";
		cin >> M;
		for (i = n; i < n + M; i++)
		{
			cout << "________________________________________" << endl;
			gr[i].add();
			count++;
		}
	}
	
	void sort_gr() {
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		cout << "Список мужчин:" << endl;

		for (i = 0; i < count; i++) {
			if (gr[i].sex == "М") {
				cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
				cout << "[" << i << "]" << endl;
				gr[i].Print();
			}
		}
		
	}

	

	
};

int main() {
	hub exz1;
		
		int t(1);
	while (t != 0)
	{
		SetConsoleCP(1251);
		SetConsoleOutputCP(1251);
		system("CLS");
		cout << "Выберите команду:"<<endl;
		cout << "1 - Добавить" << endl; 
		cout << "2 - Показать" << endl; 
		cout << "3 - Сортировать по указке в задании" << endl; 
		cout << "0 - Выйти" << endl; 
		cout << "Номер  = ";
		cin >> t;

			if (t == 1) {
				exz1.gr_Add();

			};
			if (t == 2) {
				exz1.gr_Print();

			};
			if (t == 3) {	
				exz1.sort_gr();
			}
			system("pause");
	}
}