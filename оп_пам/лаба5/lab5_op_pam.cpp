#include <iostream>
using namespace std;
//14 variant

int find_max(int* mass, int size)
{
    int max = mass[0];
    for (int i = 1; i < size; i++)
    {
        if (max < mass[i])max = mass[i];
    }
    return max;
}
void print_vec(int* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << mass[i] << "  ";
    }
    cout << endl;
}
void square_v(int* mass, int size)
{
    for (int i = 0; i < size; i++)
    {
        mass[i] = mass[i] * mass[i];
    }
}

int find_min_of_max(int* mass1, int *mass2, int* mass3,int size)
{
    // нету разницы при объявлении переменных 
    int max_of_v[3] = { find_max(mass1, size), find_max(mass2, size), find_max(mass3, size) };
    int min = max_of_v[0];
    for (int i = 1; i < 3; i++)
    {
        if (max_of_v[0] > max_of_v[i])
        {
            min = max_of_v[i];
        }
    }
    return min;
}
int main()
{
    const int size{ 3 }; 
    int v1[size] = { -3,-2,-1};
    int v2[size] = {1,1,1};
    int v3[size] = {1,1,1};
    // можно було створити змінні
    cout << "vector 1    :: "; print_vec(v1, size);
    cout << "max of v1 = " << find_max(v1, size)<<endl;
    cout << "vector 2    :: "; print_vec(v2, size);
    cout << "max of v2 = " << find_max(v2, size)<<endl;
    cout << "vector 3    :: "; print_vec(v3, size);
    cout << "max of v3 = " << find_max(v3, size)<<endl;
    cout << "min of max's :: " << find_min_of_max(v1,v2,v3,size)<< endl;
    cout << "_________________________________" << endl;
    cout << "calculating... (squaring the vector) " << endl;
    square_v(v1, size); 
    square_v(v2, size);
    square_v(v3, size);
    cout << "_________________________________"<<endl;
    cout << "vector 1    :: "; print_vec(v1, size);
    cout << "max of v1 = " << find_max(v1, size)<<endl;
    cout << "vector 2    :: "; print_vec(v2, size);
    cout << "max of v2 = " << find_max(v2, size)<<endl;
    cout << "vector 3    :: "; print_vec(v3, size);
    cout << "max of v3 = " << find_max(v3, size)<<endl;
    cout << "min of max's :: " << find_min_of_max(v1, v2, v3, size) << endl;
}

/*
test 1 
input
size = 4
    v1 = { 6,5,4,1 };
    v2 = {33,2,2,5};
    v3 = {3,1,0,0,};

    output
v1       :: 6  5  4  1
max of v = 6
v2       :: 33  2  2  5
max of v = 33
v3       :: 3  1  0  0
max of v = 3
min of max's :: 3
_________________________________
v1       :: 36  25  16  1
max of v = 36
v2       :: 1089  4  4  25
max of v = 1089
v3       :: 9  1  0  0
max of v = 9
min of max's :: 9


test 2 
input
size = 2
    v1 = { 1,1 };
    v2 = {2,0};
    v3 = {0,3};

    output
    v1       :: 1  1
max of v = 1
v2       :: 2  0
max of v = 2
v3       :: 0  3
max of v = 3
min of max's :: 1
_________________________________
v1       :: 1  1
max of v = 1
v2       :: 4  0
max of v = 4
v3       :: 0  9
max of v = 9
min of max's :: 1

test 3 
input 
size =  1
    v1 = {11};
    v2 = {0};
    v3 = {11};
output
v1       :: 11
max of v = 11
v2       :: 0
max of v = 0
v3       :: 11
max of v = 11
min of max's :: 0
_________________________________
v1       :: 121
max of v = 121
v2       :: 0
max of v = 0
v3       :: 121
max of v = 121
min of max's :: 0

test 4 
input
size =  1
    v1 = {0};
    v2 = {0};
    v3 = {0};
output
v1       :: 0
max of v = 0
v2       :: 0
max of v = 0
v3       :: 0
max of v = 0
min of max's :: 0
_________________________________
v1       :: 0
max of v = 0
v2       :: 0
max of v = 0
v3       :: 0
max of v = 0
min of max's :: 0
*/