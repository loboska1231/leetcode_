//#define USE_MAIN_FIRST // переключатель
#include <iostream>
#include <cmath>
#ifdef USE_MAIN_FIRST// переключатель

using namespace std;

int main() {
	const float pi = 3.14159;// постоянная пи
	setlocale(LC_ALL, "Rus");
	double x,y;
	cout << "Задание 1 \n Введите x :"; // ввод переменной
	cin >> x;
	
	if (x <= 0) {// условие 1 при котором x<0 -->)вывод( 0
		y = 0;
	}
	else if (x <= 1) {//условие 2 при котором 0<x<=1 -->)вывод( x^2 - x
		y = x * x - x;
	}
	else {
		y = x * x - sin(pi * x * x);//условие 3 при котором x>1 -->)вывод( x^2 - sin(pi*x^2)
	}

	cout << "f(" << x << ")=" << y;// вывод значений в виде F(x)=y
}
#endif 

/*
* test 1
x= -1
f(-1) = 0

test 2
x=0.7
f(0.7)=-0.21

test 3
x=2
f(2)=4.00001

*/