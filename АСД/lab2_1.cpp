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

	void add(int _data)
	{
		NODE* currentNode = new NODE(_data);
		currentNode->value = _data;
		currentNode->next = head;
		head = currentNode;
	}

	// функция добавления елемента в начало

	void add_after(int _data, int _N)
	{
		NODE* current = head;
		for (int i = 1; i < _N && current; i++)
		{
			current = current->next;
		}
		if (current)
		{
			NODE* newNode = new NODE(_data);
			newNode->next = current->next;
			current->next = newNode;
		}
	}

	//функция добавления елемента ПОСЛЕ НОМЕРА
	//тоесть сначало вводиться елемент, а затем номер

	void add_bot(int _data)
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

	//функция добавления елемента в конец
	void move_n(int _N, int _X)
	{
		if (head == nullptr || _N <= 0 || _X <= 0) return;

		NODE* current = head;
		NODE* prev = nullptr;
		int count = 1;

		while (current != nullptr && count < _N)
		{
			prev = current;
			current = current->next;
			count++;
		}

		if (current == nullptr) return;


		if (prev != nullptr) prev->next = current->next;
		else head = current->next;

		count = 0;
		NODE* temp = head;
		prev = nullptr;

		while (count < _X && temp != nullptr) {
			prev = temp;
			temp = temp->next;
			count++;
		}

		if (prev != nullptr) prev->next = current;
		else head = current;

        current->next = temp;
	}

	//перемещение елмента с номером какое-то кол-во раз

	void remove()
	{
		if (is_mt()) return;
		NODE* top = head;
		head = top->next;
		top = nullptr;

	}

	//удаление первого елемента 

	void removeN(int _N)
	{
		if (head == nullptr || _N <= 0) return;

		NODE* curr = head;
		NODE* prev = nullptr;
		int count{ 1 };

		while (curr != nullptr && count < _N)
		{
			prev = curr;
			curr = curr->next;
			count++;
		}
		if (curr == nullptr)
		{
			cout << "element" << _N << "doesn't exist";
			return;
		}
		else if (prev != nullptr) prev->next = curr->next;
		else head = curr->next;

		curr = nullptr;
	}

	// удаление елемента по заданому номеру

	void removeEvryN(int _N)
	{
		if (head == nullptr || _N <= 0) return;

		NODE* curr = head;
		NODE* prev = nullptr;
		int count{ 1 };

		while (curr != nullptr)
		{
			if (count % _N == 0)
			{
				if (prev != nullptr) prev->next = curr->next;
				else head = curr->next;
				NODE* tmp = curr;
				curr = curr->next;
				tmp = nullptr;
			}
			else
			{
				prev = curr;
				curr = curr->next;
			}
			count++;
		}
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

	void sort_max_min()
	{
		bool swapped;
		NODE* ptr;
		NODE* lptr = nullptr;

		if (head == nullptr)return;

		do
		{
			swapped = false;
			ptr = head;
			while (ptr->next != lptr)
			{
				if (ptr->value < ptr->next->value)
				{
					swap(ptr->value, ptr->next->value);
					swapped = true;
					// buble sort 
					//сравнивание двух значений и смена их местами, если соответствует условию
					// довольно медленная для болих объёмов данных
				}
				ptr = ptr->next;
			}
			lptr = ptr;
		} while (swapped);
	}
	//сортировка от большего->меньшего

	LinkedList* copy()
	{
		LinkedList* newList = new LinkedList();
		NODE* current = head;

		while (current != nullptr)
		{
			newList->add_bot(current->value);
			current = current->next;
		}
		return newList;
	}

	// полная копия листа 

	LinkedList common_list(LinkedList secondList)
	{
		LinkedList list_common;
		NODE* curr = head;
		while (curr != nullptr)
		{
			NODE* curr_common = secondList.head;
			while (curr_common != nullptr)
			{
				if (curr->value == curr_common->value)
				{
					list_common.add(curr->value);

				}
				curr_common = curr_common->next;
			}
			curr = curr->next;
		}
		return list_common;
	}

	// создание листа с общими елементами
	// из 1 листа и его копии

	void Plus_2_lists(LinkedList& secondList)
	{
		if (head == nullptr)
		{
			head = secondList.head;
			secondList.head = nullptr;
		}
		else
		{
			NODE* curr = head;
			while (curr->next != nullptr) curr = curr->next;

			curr->next = secondList.head;
			secondList.head = nullptr;
		}
	}
	// объединение двух списков ( оригинала и копии )

};
int main()
{
	LinkedList exz, copy_exz;
	int t{ 1 };
	while (t != 0)
	{
		system("CLS");
		cout << "############################## |" << endl;
		cout << "1 - add element to top of list |" << endl;
		cout << "2 - add element to bot of list |" << endl;
		cout << "3 - add element after element  |" << endl;
		cout << "4 - move element N-times       |" << endl;
		cout << "5 - print head of list         |" << endl;
		cout << "6 - remove element             |" << endl;
		cout << "7 - remove the N element       |" << endl;
		cout << "8 - remove every N element     |" << endl;
		cout << "9 - remove full                |" << endl;
		cout << "10 - sort from max to min      |" << endl;
		cout << "11 - copy list                 |" << endl;
		cout << "12 - make list with common     |" << endl;
		cout << "13 - plus 2 lists              |" << endl;
		cout << "0 - leave                      | " << endl;
		cout << "############################## |" << endl;
		cout << "the nodes:                     \n"; exz.print();
		cout << "the copy nodes:                 \n"; copy_exz.print();
		cout << "______________________________ " << endl;
		cout << "Write the number to use command : ";

		int i;

		cin >> t;
		if (t == 1)
		{
			cout << "Write the number that you want to add in top : ";
			cin >> i;
			exz.add(i);
		}
		else if (t == 2)
		{
			cout << "Write the number that you want to add in bot : ";
			cin >> i;
			exz.add_bot(i);
		}
		else if (t == 3)
		{
			int n;
			cout << "Write the number and number that you want to add  : ";
			cin >> i >> n;
			exz.add_after(i, n);
		}
		else if (t == 4)
		{
			int n, x;
			cout << "moving number of element: ";
			cin >> n;
			cout << " x times: ";

			cin >> x;
			exz.move_n(n, x);
		}
		else if (t == 5)
		{
			cout << "Print head : ";
			exz.head_print();
		}
		else if (t == 6)
		{
			cout << "remove the top element : ";

			exz.remove();
		}
		else if (t == 7)
		{
			cout << "Write the number that you want to remove : ";
			cin >> i;
			exz.removeN(i);
		}
		else if (t == 8)
		{
			cout << "Write the number that you want to remove : ";
			cin >> i;
			exz.removeEvryN(i);
		}
		else if (t == 9)
		{
			cout << "Full remove  ";
			exz.remove_full();
		}
		else if (t == 10)
		{
			cout << "sorting... ";
			exz.sort_max_min();
		}
		else if (t == 11)
		{
			copy_exz = *exz.copy();
			cout << "coping... ";
			exz.copy();
		}
		else if (t == 12)
		{
			LinkedList common_exz = exz.common_list(copy_exz);
			cout << "List with common elements" << endl;
			common_exz.print();
		}
		if (t == 13)
		{
			exz.Plus_2_lists(copy_exz);
			cout << "we have done plus";
		}
		else if (t == 0)
		{
			cout << "Leaving the program... ";
			return 0;
		}
		system("pause");
	}
}