#include <iostream>
using namespace std;
int main()
{
    const int size = 6;
    int array[size]{};
    int i ,j, k;  
    int t = 1;
    while (t != 0)
    {
        system("CLS");
        cout << "1 - add elements" << endl;
        cout << "2 - odd numbers" << endl;
        cout << "3 - sum after minimum" << endl;
        cout << "4 - swap halfs" << endl;
        cout << "0 - leave" << endl;
        cout << "---------------------------------"<<endl;
        cout << "the CONST size of array = " << size << endl;
        cout << "tha array" << endl;
        for (k = 0; k < size; k++) cout << array[k] << "  ";
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "write the command" << endl;
        cin >> t;
        if (t == 1)
        {
            int c{ 0 }, u;
            cout << "write the elements" << endl; 
            while(c<size)
            {              
                cin >> u;
                array[c] = u;
                c++;
            }
        }
        if (t == 2)
        {
            int count{ 0 };
            for (k = 0; k < size; k += 2)
            {             
                if (array[k] % 2 != 0)
                {
                    cout << "Odd number on odd position =  " << array[k] << endl;
                    cout << "[" << k + 1 << "]" << endl;
                    count++;
                }
                else if (array[k] == 0)
                {
                    cout << " On odd position have zero " << endl;
                    cout << "[" << k + 1 << "]" << endl;
                }
                else
                {
                    cout << " On odd position have even number " << endl;
                    cout << "[" << k + 1 << "]" << endl;
                }
            }
            cout << "Count of odd = " << count << endl;           
        }
        else if (t == 3)
        {
            int minIndex{ 0 };
            for (i = 1; i < size; i++)
            {
                if (array[i] < array[minIndex])minIndex = i;
            }
            cout << "Minimum = " << array[minIndex] << endl;
            int sum{ 0 };
            if (minIndex == size-1) 
            {
                cout << "the last element" << endl; 
                sum = 0;// 0-9 size 10
            }
            else
            {               
                for (j = minIndex + 1; j < size; j++)
                {
                    sum += array[j];
                }
            }
            cout << "Sum = " << sum << endl;
        }
        else if (t == 4)
        {           
             int startSwapN = size / 2; // 4  
             for (i = 0; i < startSwapN / 2; i++)
             {
                swap(array[i], array[startSwapN - i - 1]);// разворачивает числа первой половины массива
                /* int temp = array[i];
                 array[i] = array[startSwapN - i - 1];
                 array[startSwapN - i - 1] = temp;*/ // 1 2 3 4 \  5 6 7 8 9
                // 4 3 2 1 
             }
                       
             for (i = 0; i < (size - startSwapN) / 2; i++)
             {
                swap(array[startSwapN + i], array[size - i - 1]);//разворачивает вторую половину массива 
                /*int temp = array[startSwapN+i];
                 array[startSwapN+i] = array[size- i - 1];
                 array[size - i - 1] = temp; */
                //  
             }
                       
             for (i = 0; i < size / 2; i++)
             {
                swap(array[i], array[size - i - 1]);// меняет местами первый(+1) и последний элемент(-1) пока не дойдет до startSwapN/2
                /* int temp = array[i];
                 array[i] = array[size - i - 1];
                 array[size - i - 1] = temp; */
             }
        }
       
        else if (t == 0) return 0;
        system("pause");
    }
}
/*
array {1,2,3,4,5,6,7,8,9,10}
odd numbers = 5
minIndex = 1
sum = 54
swap 6  7  8  9  10  1  2  3  4  5

array {1,2,3,-4,5,6,7,8,9,10}
odd numbers = 5
minIndex =-4
sum = 35
swap   6 7 8 9 10 1 2 3 -4 5 

array {1,0,1,0,1,0,10,0,1,0}
odd numbers = 4
minIndex =0
sum = 13
swap 0  1  0  1  0  1  0  1  0  1

array { 1 2 3 4 5 6 7 }
odd numbers = 4
sum 44
swap 4 5 6 7 1 2 3 

array { 1 2 3 4 5 6 7 8 9 }
odd numbers = 3
minIndex = 1
sum = 9
swap    5 6 7 8 9 1 2 3 4
*/

