#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

struct elem
{
	string data;
	elem *next;
};
typedef elem* Pelem;

class Hash
{
	Pelem *hashtable;
	int size;
	int full=0;
public:
	Hash() : hashtable(nullptr), size(200), full(0) {}
	int myHash(string);
	void insert_elem(string);
	void create_Hash();
	string reseach(string);
	int Hash_key(string);
};



void Hash::insert_elem(string str)
{
	Pelem p, p0;
	int h = myHash(str);
	p = new elem;
	if (!hashtable[h])
	{
		full++;
		if(full>80*(size/100));
	}
	p0 = hashtable[h];
	hashtable[h] = p;
	p->next = p0;
	p->data = str;
}

void Hash::create_Hash()
{
	hashtable = new elem*[size];
	for (int i = 0; i < size; i++)
	{
		hashtable[i] = nullptr;
	}
	ifstream dict("dict_processed.txt");
	string str;
	while (!dict.eof())
	{
		getline(dict, str);
		if (!dict.eof()) insert_elem(str);
	}
	dict.close();
}





int main()
{
	setlocale(LC_ALL, "rus");
	cout << "Таблица генерируется. Пожалуйста, подождите." << endl;
	Hash table;
	table.create_Hash();
	cout << "Таблица готова. Введите своё предложение:" << endl;
	string sentense;
	getline(cin, sentense);
	string word;
	
	system("pause");
}