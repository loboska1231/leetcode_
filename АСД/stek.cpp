#include <iostream>
using namespace std;
struct NODE
{
	int value;
	NODE* next;

	NODE(int _data) : value(_data), next(nullptr) {};	
	//инициализация вида 1
};
struct MyStack
{
	NODE* head;
	MyStack() : head(nullptr) {};

	bool is_mt()
	{
		bool k;
		if (head == NULL) return k = true;
		else return k = false;
	}

	void print()
	{
		if (is_mt()) return;
		NODE* print = head;
		while (print)
		{
			cout << print->value << " ";
			print = print->next;
		}
		cout << endl;
	}

	void push(int _data)
	{
		NODE* newNode = new NODE(_data);
		if (!head) {
			head = newNode;
		}
		else
		{
			NODE* ct_NODE = head;
			while (ct_NODE->next)
			{
				ct_NODE = ct_NODE->next;
			}
			ct_NODE->next = newNode;
		}
	}

	void pop()
	{
		if (is_mt()) {
			cout << "Stack is empty, cannot pop." << endl;
			return;
		}

		NODE* current = head;
		NODE* previous = nullptr;

		while (current->next)
		{
			previous = current;
			current = current->next;
		}

		if (previous) {
			delete current;
			previous->next = nullptr;
		}
		else {
			// Если у нас всего один элемент в стеке
			delete head;
			head = nullptr;
		}
	}

	void remove_full()
	{
		while (head != nullptr)
		{
			NODE* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void swapF_L()
	{
		if (is_mt() || head->next == nullptr) 
		{
			cout << "not enough elements" << endl;
			return;
		}
		NODE* last = head;
		NODE* secondlast = nullptr;		
		while ( last->next)
		{
			secondlast = last;
			last = last->next;
		}		
		swap(head->value, last->value);
	}
	// была проблема в том что я не дописывал часть ->value 
	void reverse()
	{
		if (is_mt() || head->next == nullptr)
		{
			cout << "not enough elements" << endl;
			return;
		}
		NODE*prev = nullptr;
		NODE* next = nullptr;
		NODE* current = head;
		while (current)
		{
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	bool belong(int _data)
	{
		NODE* current = head;
		int c = false;
		while (current)
		{
			if (current->value == _data) c=  true;
			current = current->next;
		}
		return c;		
	}
};
int main()
{
	MyStack exz;
	int t{ 1 };
	while (t != 0)
	{
		system("CLS");
		cout << "############################## |" << endl;
		cout << "1 - push element           |" << endl;
		cout << "2 - pop element            |" << endl;
		cout << "3 - pop full               |" << endl;
		cout << "4 - swap f-t and l-t       |" << endl;
		cout << "5 - reverse                |" << endl;
		cout << "6 - belong the element             |" << endl;		
		cout << "0 - leave                      | " << endl;
		cout << "############################## |" << endl;
		cout << "the nodes:                     \n"; exz.print();
		cout << "______________________________ " << endl;
		cout << "Write the number to use command : ";

		int i;

		cin >> t;
		
	    if (t == 1)
		{
			cout << "Write the number that you want to add : ";
			cin >> i;
			exz.push(i);
		}
		
		else if (t == 2)
		{
			cout << "pop the  element  ";

			exz.pop();
		}
		
		else if (t == 3)
		{
			cout << "Full remove  ";
			exz.remove_full();
		}
	
		else if (t == 4)
		{
			cout << "swapping..." << endl;
			exz.swapF_L();
		}

		else if (t == 5)
		{
			cout << "reversing..." << endl;
			exz.reverse();
		}

		else if (t == 6)
		{
			cout << "wat a number???" << endl;
			int k; cin >> k;
			cout << "is belong to... " << endl;
			if (exz.belong(k)) cout << "yes" << endl;
			else cout << "no" << endl;
		}

		else if (t == 0)
		{
			cout << "Leaving the program... ";
			return 0;
		}
		system("pause");
	}

}
//6 операций
//1 добавить в конец !
//2 удалить последний!
//3 поменять первый и последний елемент!
//4 развернуть стек 1-9 -> 9-1!
//5 принадлежность к стеку
// 6 очистка
// постоянный вывод
