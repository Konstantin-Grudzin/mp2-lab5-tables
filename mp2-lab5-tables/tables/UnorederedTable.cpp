#include "UnorederedTable.h"

void UnorderedTable::add(std::string name, Polynom pal)
{
	Elementt tmp; tmp.name = name; tmp.polynom = pal;
	table.push_back(tmp);
	backlog(1);
}

void UnorderedTable::erase(std::string name)
{
	std::vector<Elementt> v;
	for (int i = 0; i < table.size(); ++i)
	{
		if (table[i].name == name) continue;
		v.push_back(table[i]);
	}
	table.assign(begin(v), end(v));
	backlog(table.size() + 1);
}

void UnorderedTable::clear()
{
	backlog(table.size());
	for (int i = 0; i < table.size(); ++i)
	{
		table[i].polynom.clear();
	}
	table.clear();
}

void UnorderedTable::print(std::string name)
{
	int i = 0;
	for (; i < table.size(); ++i)
	{
		if (table[i].name == name)
		{
			std::cout << table[i].name << ": " << table[i].polynom<<"\n";
			backlog(i + 1);
			return;
		}
	}
	std::cout << "This element doesn't exist\n";
	backlog(i+1);
}

void UnorderedTable::print_all()
{
	int i = 0;
	for (; i < table.size(); ++i)
	{
		std::cout << table[i].name << " " << table[i].polynom<<"\n";
	}
	backlog(i + 1);
}

Polynom UnorderedTable::get_polynom(std::string name)
{
	int i = 0;
	for (; i < table.size(); ++i)
	{
		if (table[i].name == name)
		{
			backlog(i + 1);
			return table[i].polynom;
		}
	}
	throw "This element doesn't exist!";
}

bool UnorderedTable::find(std::string name)
{
	int i = 0;
	for (; i < table.size(); ++i)
	{
		if (table[i].name == name)
		{
			backlog(i + 1);
			return 1;
		}
	}
	backlog(i + 1);
	return 0;
}