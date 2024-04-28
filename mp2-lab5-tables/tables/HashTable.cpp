#include "HashTable.h"

int HashTable::GetHash(std::string& name)
{
	int base = 2*3*5*7*11+1;
	int ans = 0;
	int k = 1;
	for (int i = 0; i < name.size(); ++i,k=(k*base)%size)
	{
		ans = ((ans + (name[i]) * base) % size + size)%size;
	}
	return (ans % size + size) % size;
}

void HashTable::add(std::string name, Polynom pal)
{
	int key = ((GetHash(name)%size)+size)%size;
	int op = 1;
	if (table[key] == nullptr)
	{
		table[key] = new LinkElem(name,pal);	
	}
	else
	{
		LinkElem* tmp = table[key];
		while (tmp->next != 0)
		{
			tmp = tmp->next;
			op++;
		}
		tmp->next = new LinkElem(name, pal);
	}
	backlog(op);
}

void HashTable::erase(std::string name)
{
	int key = GetHash(name);
	LinkElem* head = table[key];
	if (head == 0) return;
	int op = 1;
	if (head->name == name)
	{
		LinkElem* snd = head->next;
		head->clear();
		delete head;
		table[key] = snd;
		backlog(op);
	}
	else
	{
		LinkElem* fst = head;
		while (fst->next!=0 && fst->next->name != name)
		{
			fst = fst->next;
			op++;
		}
		if (fst->next == 0) return;
		LinkElem* snd = fst->next;
		LinkElem* thrd = fst->next->next;
		snd->clear();
		delete snd;
		fst->next = thrd;
		backlog(op);
	}
}

void HashTable::clear()
{
	int op = 0;
	for (int i = 0; i < table.size(); ++i)
	{
		op += DelLink(table[i]);
	}
	backlog(op);
}

std::pair<bool,int> HashTable::PrintLink(LinkElem* tmp,std::string& name)
{
	if (tmp == 0) return { 0,0 };
	if (tmp->name == name)
	{
		std::cout << name << " " << tmp->polynom<<"\n";
		return { 1,1 };
	}
	std::pair<bool, int> ttmp = PrintLink(tmp->next, name);
	return { ttmp.first,ttmp.second + 1 };
}

void HashTable::print(std::string name)
{
	int key = GetHash(name);
	auto op = PrintLink(table[key], name);
	if (!op.first)
		std::cout << "Element doesn't exist";
	backlog(op.second? op.second :1);
}

int HashTable::Aprint(LinkElem* tmp)
{
	if (tmp == 0) return 0;
	std::cout << tmp->name << " " << tmp->polynom<<"\n";
	return Aprint(tmp->next) + 1;
}

void HashTable::print_all()
{
	int op = 0;
	for (int i = 0; i < size; ++i)
	{
		op+=Aprint(table[i]);
	}
	backlog(op);
}

Polynom HashTable::get_polynom(std::string name)
{
	int key = GetHash(name);
	LinkElem* fst = table[key];
	while (fst != 0 && fst->name != name)
	{
		fst = fst->next;
	}
	if (fst == 0)
		throw "Element doesn't exist";
	else
	{
		return fst->polynom;
	}
}

bool HashTable::find(std::string name)
{
	int key = GetHash(name);
	LinkElem* fst = table[key];
	while (fst != 0 && fst->name != name)
	{
		fst = fst->next;
	}
	if (fst == 0)
		return 0;
	else
	{
		return 1;
	}
}