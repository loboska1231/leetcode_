#include <iostream>

using namespace std;
struct NODE
{
	int value;
	NODE* next;

	NODE(int _data)
	{
		value = _data;
		next = nullptr;
	};
	//инициализация вида 1
};
struct LinkedList
{
	NODE* head;

	LinkedList() : head(nullptr) {};

	//инициализация вида 2

	bool is_mt()
	{
		bool k;
		if (head == NULL) return k = true;
		else return k = false;
	}

	// условие пуст ли лист

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

	// вывод елементов

	void head_print()
	{
		cout << "Value = " << head->value << endl;
		cout << "Next  = " << head->next << endl;
		cout << "______________________" << endl;
	}

	//вывод главного елемента 


	void add_bot(int _k)
	{
		for(int c =1;c<=_k;c++)
		{
			NODE* newNode = new NODE(c);
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
	}

	

	// удаление елемента по заданому номеру

	void removeEvryN(int n)
	{
		if (is_mt()) {
			cout << "Список пуст." << endl;
			return;
		}

		NODE* current = head;
		NODE* prev = nullptr;
		int index = 1;

		while (head->next != nullptr) {
			for (int i = 1; i < n; i++) {
				prev = current;
				current = current->next;
				if (current == nullptr) {
					current = head;
				}
			}

			cout << "removed: " << current->value << endl;

			prev->next = current->next;
			delete current;
			current = prev->next;

			if (current == nullptr) {
				current = head;
			}
		
		}
		head = current;
	}
	

	//удаление каждого елемента кратного числу _N

	void remove_full()
	{
		while (head != nullptr)
		{
			NODE* temp = head;
			head = head->next;
			temp = nullptr;
		}
	}

	// удаление всех елементов из листа

};
int main()
{
	LinkedList exz, copy_exz;
	int t{ 1 };
	while (t != 0)
	{
		system("CLS");
		cout << "############################## |" << endl;
		cout << "1 - add elements               |" << endl;		
		cout << "2 - remove every N element     |" << endl;
		cout << "3 - remove full                |" << endl;		
		cout << "0 - leave                      | " << endl;
		cout << "############################## |" << endl;
		cout << "the nodes:                     \n"; exz.print();
		cout << "______________________________ " << endl;
		cout << "Write the number to use command : ";

		int i,n;

		cin >> t;
		if (t == 1)
		{
			cout << "Write the number : ";
			cin >> i;
			exz.add_bot(i);
		}		
		else if (t == 2)
		{
			cout << "Write the period n : ";
			cin >> n;
			exz.removeEvryN(n);
		}
		else if (t == 3)
		{
			cout << "full remove...";
			exz.remove_full();
		}
		else if (t == 0)
		{
			cout << "Leaving the program... ";
			return 0;
		}
		system("pause");
	}
}