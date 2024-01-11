#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	setlocale(LC_ALL, "rus");
	int sum{ 0 }, i, j, n = 0, a[20][20];// a[20][20] - выделение памяти под матрицу
	int count = 0;
	int t = 1;
	while (t != 0)
	{
		system("CLS");
		cout << "1 -ввод" << endl;
		cout << "2 -ряд К ревен столбу К" << endl;
		cout << "3 -сумма чисел главной диагонали" << endl;
		cout << "0 - выйти" << endl;
		cout << "Матрица а размера NxN (максимальный размер 20 на 20) " << endl << endl;
		for (i = 0; i < n; i++)
		{			
			for (j = 0; j < n; j++)	cout << a[i][j] << " ";					
			cout << endl;
		}
		cout << endl;
		
		cout << "Введите команду :: " << endl; cin >> t;		
		if (t == 1)
		{
			cout << "n строк(и столбцев ) :: "; cin >> n;			
				cout << "Введите элементы матрицы a :: " << endl;
				for (i = 0; i < n; i++)
					for (j = 0; j < n; j++)
					{
						cout << "a" << "[" << i + 1 << "]" << "[" << j + 1 << "] = ";
						cin >> a[i][j];
					}
			
		}		
		else if (t == 2)
		{
			vector<int>b = {};
			int count_equal{ 0 };
			for (int k = 0; k < n; k++)			
				for (i = 0; i < n; i++)
					if (a[i][k] == a[k][i])
					{						
						count_equal++;
						if(count_equal == n)
						{
							b.push_back(k+1);// к+1 что бы было легче понимать какой номер ряда и столбца совпали
							count_equal = 0;
						}
					}
					else count_equal = 0;							    
			if (b.size() != 0)
			{
				cout << "vector b где совпали числа в номерах k" << endl;
				for (int o = 0; o < b.size() ; o++) cout << b[o] << "\t";
				
				cout << endl;
			}
			else cout << "vector b пуст " << endl;
			
		}
		else if (t == 3)
		{
			if (n > 0)
			{
				sum = 0;
				for (i = 0; i < n; i++)	sum += a[i][i];
				cout << "сумма чисел гланой диагонали :: " << sum << endl;
			}
			else cout << "не могу посчитать пустую матрицу"<<endl;
		}
		else if (t == 0) break;
		system("pause");
	}
}
/*
 test 1
 1 1 1
 1 1 1
 1 1 1
 
 b = 1 2 3 
 sum = 3 

 test 2 
 0 1 2
 1 2 3
 2 3 4

 b = 1 2 3 
 sum = 6

 test 3
 9 8 0
 3 3 0
 0 0 0
 b = 3 
 sum = 12

 test 4 
 5 4 3 2 1
 4 3 2 1 0
 3 2 1 0 -1
 2 1 0 -1 -2
 1 0 -1 -2 -3
 b = 1 2 3 4 5
 sum = 5

 test 5 
 1 
 b = 1
 sum = 1

 test 6 
 1 0
 1 0
 vector is empty
 sum = 1

 test 7
 3 0 1
 0 0 6
 2 6 1 
 b = 2
 sum = 9

 test 8 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  0 0 0 0 0 0 0 
  b = 1 2 3 4 5 6 7
  sum = 0

  test 9
  | NULL | - > размер <0
  нет - > нельзя ввести элементы в матрицу чей размер меньший чем ноль
  vector is empty
  не могу посчитать пустую матрицу

*/