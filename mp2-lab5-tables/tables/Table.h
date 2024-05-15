#pragma once

#include "polynom.h"



class  Table 
{
	std::string name_of_table;
protected:
	void backlog(int i)
	{
		std::string name = GetName();
		std::cout<<name<<": "<< "\nIt took " << i << " operations\n";
	}
	
public:
	virtual void add(std::string name, Polynom val) = 0;
	virtual void erase(std::string name) = 0;
	virtual void clear() = 0;
	virtual void print(std::string name) = 0;
	virtual void print_all() = 0;
	virtual Polynom get_polynom(std::string name) = 0;
	virtual bool find(std::string name) = 0; 
	virtual std::string GetName() { return name_of_table; }
};



