#define USE_MAIN_SECOND // �������������
#include <iostream>

#ifdef USE_MAIN_SECOND
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");
	double x,y,u;
	
	cout << "������� x :"; cin >> x;// ���� ��������� ����� �� �
	cout << "������� y :"; cin >> y;// ���� ��������� ����� �� �
	

	/*
	y<=e^x
	y<=e^-x
	y>=x^2
	*/
	if (y <= exp(x) && y <= exp(-x) && y >= x * x) {// ������� ������� 
		cout << "��, ��� �����������";// ����� ����������� �������
		u = x + y;
		 
	}
	else {
		cout << "���, �� �����������";// �� ����������� �������
		u = x - y;
		
	}
	cout << "\n u=" << u;

}
#endif
/*
test 1
x=0
y=2
result - false; -2

test 2
x=0
y=1
result - true;1

test 3
x=1
y=2
result - false;-1

test 4
x=0.5
y=0.5
result - true;1

test 5 
x=-0.7
y=0.4
result - false; -1.1

test 6 
x=0.7
y=0.5
result - false; 0.2

test 7
x=0.7
y=0.495
result - true; 1.195
*/