#pragma once
#include "Table.h"

struct LinkElem
{
	std::string name;
	Polynom polynom;
	LinkElem* next;
	LinkElem(std::string _name, Polynom pal, LinkElem* _nxt = 0)
	{
		name = _name;
		polynom = pal;
		next = _nxt;
	}
	void clear()
	{
		polynom.clear();
	}
};

// по умолчанию - 1000
class HashTable : public virtual Table
{

private:
	std::string name_of_table="HashTable";
	int size;
	std::vector<LinkElem*> table;
	int GetHash(std::string& name);
	int DelLink(LinkElem* tmp)
	{
		if (tmp == 0) return 0;
		int ans=DelLink(tmp->next)+1;
		tmp->clear();
		delete tmp;
		return ans;
	}
	std::pair<bool,int> PrintLink(LinkElem* tmp, std::string& name);
	int Aprint(LinkElem* tmp);
public:
	HashTable(int s = 1000):size(s){table.resize(s);}
	void add(std::string name, Polynom val) override;
	void erase(std::string name) override;
	void clear() override;
	void print(std::string name) override;
	void print_all() override;
	Polynom get_polynom(std::string name) override;
	bool find(std::string name) override;
	std::string GetName() override
	{
		return name_of_table;
	}
};

