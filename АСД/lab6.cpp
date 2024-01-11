#include <iostream>
using namespace std;
struct NODE
{
	int key;
	int value;
	NODE* next;
	NODE() : key(NULL), value(NULL), next(nullptr) {};
	NODE(int _key, int _value) : key(_key), value(_value), next(nullptr) {};
	void printNode()
	{
		cout << "(" << key << ", " << value << ") ";
	}
};

class myHashTable
{
private:
	int size_table;
	NODE** table;	
public:
	myHashTable()
	{
		size_table = 3;
		table = new NODE*[size_table];
		for (int i = 0; i < size_table; i++)
		{
			table[i] = nullptr;
		}
	}

	myHashTable(int _st) // construction with a parametr _st - dinamic size of table 
	{
		size_table = _st;
		table = new NODE * [size_table];
		for (int i = 0; i < size_table; i++)
		{
			table[i] = nullptr;
		}
	}
	void hash_print()
	{
		for (int i = 0; i < size_table ; i++)
		{
			NODE* current = table[i];
			cout << "[" << i << "] : ";
			
			while (current)
			{
				current->printNode();
				current = current->next;
			}
			cout << endl;			
		}
	}
	void hash_add(int _key, int _value)
	{
		int index{ _key % size_table };
		NODE* newNODE = new NODE(_key,_value);
		if (!table[index])
		{
			table[index] = newNODE;
			// index of hash_table dont have elements
		}
		else
		{
			NODE* current = table[index];
			while (current->next)
			{
				current = current->next;
			}
			current->next = newNODE;
			//index of hash_table have element, need to add element in queue
		}
	}
	void hash_delete(int _key)
	{
		int index{ _key % size_table };
		NODE* current = table[index];
		NODE*prev = nullptr;
		while (current)
		{
			if (current->key == _key)
			{
				if (prev) prev->next = current->next;
				else table[index] = current->next;
				return;
			}			
			prev = current;
			current = current->next;
		}		
	}
    bool have_key(int _key)
	{
		int index{ _key % size_table };
		NODE* current = table[index];
		while (current)
		{
			if (current->key == _key) return true;
			current = current->next;
		}		
	}
};
int main()
{
	int guess;
	cout << "Write the size of hash_table with parametr :: "; cin >> guess;
	myHashTable exz1{ guess };	
	myHashTable exz;
	int p_key;
	int p_value;
	int t = 1;
	while (t != 0)
	{
		system("CLS");
		cout <<"1. add elemets"<<endl;
		cout <<"2. delete elements"<<endl;
		cout <<"3. search element by key"<<endl;
		cout <<"0. exit"<<endl;
		cout << "______________hash-table________________" << endl;
		exz.hash_print();
		cout << "________hash-table_with_parametr________" << endl;
		exz1.hash_print();
		cout << "write the command :: "; cin >> t;
		if (t == 1)
		{
			int k;
			cout << "where o add (1 or 2)? :: "; cin >> k;
			if (k == 1)
			{
				cout << "Write the key and value :: ";
				cin >> p_key;
				cin >> p_value;
				exz.hash_add(p_key, p_value);
			}
			else if (k == 2)
			{
				cout << "Write the key and value :: ";
				cin >> p_key;
				cin >> p_value;
				exz1.hash_add(p_key, p_value);
			}
			
		}
		else if (t == 2)
		{
			int k;
			cout << "where delete(1 or 2) ? :: "; cin >> k;
			if (k == 1)
			{
				cout << "Write the key :: "; cin >> p_key;
				exz.hash_delete(p_key);
			}
			else if (k == 2)
			{
				cout << "Write the key :: "; cin >> p_key;
				exz1.hash_delete(p_key);
			}
		}
		else if (t == 3)
		{
			int k;
			cout << "where search(1 or 2) ? :: "; cin >> k;
			if (k == 1)
			{
				cout << "Write the key :: "; cin >> p_key;
				if (exz.have_key(p_key)) cout << "Yes" << endl;
				else cout << "false" << endl;
			}
			else if (k==2)
			{
				cout << "Write the key :: "; cin >> p_key;
				if (exz1.have_key(p_key)) cout << "Yes" << endl;
				else cout << "false" << endl;
			}
		}		
		system("pause");
	}	
}
