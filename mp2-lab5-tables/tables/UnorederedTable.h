#pragma once
#include "Table.h"


struct Elementt
{
	std::string name;
	Polynom polynom;
};

class UnorderedTable :public virtual Table
{
private:
	std::vector<Elementt> table;
public:
	void add(std::string name, Polynom val) override;
	void erase(std::string name) override;
	void clear() override;
	void print(std::string name) override;
	void print_all() override;
	Polynom get_polynom(std::string name) override;
	bool find(std::string name) override;
};

