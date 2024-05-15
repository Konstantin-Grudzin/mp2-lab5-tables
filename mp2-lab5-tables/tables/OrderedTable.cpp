#include "OrderedTable.h"

std::pair<int, int> OrderedTable::find_position(std::string name)
{
	if (table.empty())
		return { -1,1 };
	int op = 0;
	int left = 0, right = table.size();
	while (right - left > 1)
	{
		int mid = (left + right) >> 1;
		op++;
		if (table[mid].name <= name)
			left = mid;
		else
			right = mid;
	}
	return { left,op };
}

void OrderedTable::add(std::string name, Polynom poly)
{
	Element vl; vl.name = name; vl.polynom = poly;
	std::pair<int, int> tmp = find_position(name);
	int pos = tmp.first, op = tmp.second;


	if (pos == -1)
	{
		table.push_back(vl);
		backlog(1);
		return;
	}
	if (table[pos].name == name)
		throw "Name is already exist!";

	std::vector<Element> new_table;
	for (int i = 0; i < table.size(); ++i)
	{
		new_table.push_back(table[i]);
		if (i == pos)
		{
			new_table.push_back(vl);
		}
	}
	table.assign(begin(new_table), end(new_table));
	backlog(table.size() + op);
}

void OrderedTable::erase(std::string name)
{
	std::pair<int, int> tmp = find_position(name);
	int pos = tmp.first, op = tmp.second;
	if (pos == -1 || table[pos].name != name)
	{
		backlog(op);
		return;
	}
	else
	{
		std::vector<Element> new_table;
		for (int i = 0; i < table.size(); ++i)
		{
			if (i != pos)
			{
				new_table.push_back(table[i]);
			}
		}
		table.assign(begin(new_table), end(new_table));
		backlog(table.size() + op + 1);
	}
}

void OrderedTable::clear()
{
	backlog(table.size());
	for (int i = 0; i < table.size(); ++i)
	{
		table[i].polynom.clear();
	}
	table.clear();
}


void OrderedTable::print_all()
{
	for (int i = 0; i < table.size(); ++i)
	{
		std::cout << table[i].name << ": " << table[i].polynom << "\n";
	}
	backlog(table.size());
}

void OrderedTable::print(std::string name)
{
	std::pair<int, int> tmp = find_position(name);
	int pos = tmp.first, op = tmp.second;
	if (pos == -1 || table[pos].name != name)
	{
		std::cout << "This element doesn't exist\n";
	}
	else
	{
		std::cout << table[pos].name << ": " << table[pos].polynom << "\n";
	}
	backlog(op?op:1);
}

Polynom  OrderedTable::get_polynom(std::string name)
{
	std::pair<int, int> tmp = find_position(name);
	int pos = tmp.first, op = tmp.second;
	if (pos == -1 || table[pos].name != name)
	{
		throw "This element doesn't exist\n";
		backlog(op);
	}
	else
	{
		backlog(op);
		return table[pos].polynom;
	}
}

bool  OrderedTable::find(std::string name)
{
	std::pair<int, int> tmp = find_position(name);
	int pos = tmp.first, op = tmp.second;
	if (pos == -1 || table[pos].name != name)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}