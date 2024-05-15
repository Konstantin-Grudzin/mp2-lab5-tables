#pragma once
#include "Table.h"

struct Element
{
	std::string name;
	Polynom polynom;
};

class OrderedTable : public virtual Table
{
private:
	std::string name_of_table = "OrderedTable";
	std::vector<Element> table;
	std::pair<int, int> find_position(std::string str); //lower_bound by key, if return -1 - vector is empty
public:
	void add(std::string name, Polynom val) override;
	void erase(std::string name) override;//delete first element with this name
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