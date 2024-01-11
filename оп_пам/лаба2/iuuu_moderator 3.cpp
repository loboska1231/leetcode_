#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int a, b, x{ 0 };
	cout << " Введите а(a > 0) = "; cin >> a;
	cout << "Введите b (b<a) = "; cin >> b;
	double calc{ 1 };
	if (b > a || b<a || a <= 0)  cout << "Не подходит к условию";

	else if (b == 0  && a == 1) {
		cout << "x= " << x <<endl;
		cout << b <<"^"<< x << " <= " << a << endl;
	}
	
	else if (b == 1) cout << "Нельзя посчитать - цикличное умножение";

	else if (calc <= a) 
    {
		do
		{
			calc *= b;
			x++;
		} while (calc * b <= a);
		cout << "x= " << x << endl;
		cout << b << "^" << x <<" --- ("<<calc<<")" << " <= " << a;
	}
}

/*
test 1
a = 29
b = 3
result true x = 3 

test 2
a = 33
b = 2

result true x = 5

test 3
a = 4
b = 5

result --- Не подходит к условию ---

test 4
a = 243
b = 3

result  true x = 5

test 5
a= 1
b= 0
result true 0^0 = 1

test 6
a= 1
b= -123
result  -123^0 =-1
*/
