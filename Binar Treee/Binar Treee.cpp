
#include "stdafx.h"
#include <iostream>
#include <conio.h>
using namespace std;


class Tree
{
private:
	Tree * r;
	Tree* l;
	int lvl;
	int field;
public:
	
	Tree():r(NULL), l(NULL) 
	{
		field = 0;
	}
	

	
	void set(int s)
	{
		if (field == 0)
		{
			field = s;
			return;
		}
		if (field>=s)
		{
			if(r==NULL)r = new Tree();	
			r->set(s);
			return;
		}
		if (field < s)
		{
			if(l == NULL)l = new Tree();
			l->set(s);
			return;
		}
	
	}
	
	void show()
	{
		if (r != NULL)
		{
			r->show();
			cout << field << " ";
		}
		else 
		{
			cout << field << " ";
		}
		if (l != NULL)
		{
			l->show();
			
		}
		
	}
	void add()
	{
		if (r == NULL) { r = new Tree; r->lvl = lvl+1; return; }
		else { if (l == NULL) { l = new Tree; l->lvl = lvl + 1; return; } }
		if (rand()%2) r->add();
		else l->add();
		return;
	}
	Tree* chek()
	{
		if (r == NULL)return r;
		if (l == NULL)return l ;
		else return NULL;
	}
	
	int kol(int s)
	{
		static int pam=0;
		if (s == lvl)
		{
			pam++;
		}
		else
		{
			if (r != NULL)r->kol(s);
			if (l != NULL)l->kol(s);
		}
		return pam;
	
	}
};

class String
{
private:
	char* str;
public:
	String(const char S[])
	{
		int size;
		size = strlen(S);
		str = new char[size];
		for (int i = 0; i < size; i++)
		{
			str[i] = S[i];
		}
	}
	String()
	{
		str = '\0';
	}
	String(const String& S)
	{
		int size = strlen(S.str);
		str = new char[size];
			for (int i = 0; i < size; i++)
			{
				str[i] = S.str[i];
			}
	}
	char operator[] (int i)
	{
		if(i<strlen(str))
		return str[i];
		else {
			cout << "eror";
			return 0;
			}
	}
	void show()
	{
		cout << str;
	}
	~String()
	{
		delete[] str;
	}
	friend ostream& operator<< (ostream& s, String ga);
};
ostream& operator<< (ostream& s,String ga)
{
}
int main()
{
	Tree start;
	vector<int> aga = {1,2,5,9,6,3,4,8,52,23,12,15,48};
	for (int i=0;i< aga.size();i++)
	{
		start.set(aga[i]);
	}
	start.show();
	_getch();
    return 0;
}

