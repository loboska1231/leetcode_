#include <iostream>
#include <math.h>
using namespace std;
const int hash_size = 3;
const double A = 0.61803;
int hash_divide(int _key)
{
    return _key % hash_size;
}
int hash_multi(int _key)
{  
    return (int)(hash_size * (_key * A - (int)(_key * A)));
}
int hash_string(string _key_s)
{
    cout << "length s_key = " << _key_s.length()<<endl;
    int sum=0;
    int a = 2;
    int l = _key_s.length();
    for (int i = 0; i < l; i++)
    {
        sum += (int)(_key_s[i])*pow(a,i);
    }
    cout << "sum = " << sum << endl;  
    return (long long )(sum % hash_size);
}
int main()
{ 
    setlocale(LC_ALL, "rus");
    int key=NULL;
    int value=NULL;   
    int t = 1;
    while (1 != 0)
    {
        system("CLS");
        cout << "|-----------------------|" << endl;
        cout << "| 1 - ввести значения   |" << endl;
        cout << "| 2 - функция деления   |" << endl;
        cout << "| 3 - функция умножения |" << endl;
        cout << "| 4 - строчные ключи    |" << endl;
        cout << "|-----------------------|" << endl;
        cout << "Константы A = "<<A <<", hash_size = "<<hash_size<< endl;
        cout << "key(ключ) = "<<key<<endl; 
        cout << "value(значение)  = "<<value<<endl;
        cout << "Введите команду :: "; cin >> t;      
        if (t == 1)
        {
            cout << "key(ключ) = "; cin >> key;
            cout << "value(значение)  = "; cin >> value;
        }
        else if (t == 2)
        {
            cout << "Результат функции деления :: " << hash_divide(key) << endl;
        }
        else if (t == 3)
        {
            cout << "Результат функции умножения :: " << hash_multi(key) << endl;
        }
        else if (t == 4)
        {
            cout << "Тут нужен ключи типа string" << endl;
            string s_key;
            string s_value;
            cout << "Введите s_key(ключ типа string) :: "; cin >> s_key;
            cout << "Введите s_value(значение типа string) :: "; cin >> s_value;
            cout << "Результат фунцкии строчных ключей :: " << hash_string(s_key) << endl;
        }
        system("pause");
    }
}
