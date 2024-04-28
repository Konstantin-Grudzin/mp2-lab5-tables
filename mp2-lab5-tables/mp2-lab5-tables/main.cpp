#include "node.h"
#include "Polynom.h"
#include "Table.h"
#include "OrderedTable.h"
#include "HashTable.h"
#include "UnorederedTable.h"



Table** Tables;

void wait()
{
	char c;
	do
	{
		std::cout << "\nInput #, when you ready to continue";
		std::cin >> c;
	} while (c != '#');
}

void Get_Polynom(Polynom& tmp)
{
	std::cout << "How much monoms do you have?\n";
	int size; std::cin >> size;
	List<Monom> t1;
	for (int i = 0; i < size; ++i)
	{
		std::cout << "Input coefficient:";
		double coeff; std::cin >> coeff;
		std::cout << "Input powers of x,y,z (without spaces and less than 9!):";
		int pow; std::cin >> pow;
		while (pow >= 1000)
		{
			std::cout << "\nWrong input!";
			std::cin >> pow;
		}
		Monom mon(coeff, pow);
		t1.push_back(mon);
	}
	Polynom t2(t1);
	t2.prep();
	std::cout << "Your monom is:" << " " << t2 << std::endl;
	tmp = t2;
	wait();
}


void Add()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	while (Tables[1]->find(name))
	{
		std::cout << "Table with this name is exist!";
		std::cin >> name;
	}
	Polynom polynom;
	Get_Polynom(polynom);
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->add(name, polynom);
	}
	wait();
}

void Erase()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->erase(name);
	}
	wait();
}

void Print()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->print(name);
	}
	wait();
}

void PrintAll()
{
	for (int i = 0; i < 3; ++i)
	{
		Tables[i]->print_all();
	}
	wait();
}

void Find()
{
	std::string name;
	std::cout << "Input name:";
	std::cin >> name;
	for (int i = 0; i < 3; ++i)
	{
		std::cout<<Tables[i]->find(name)<<"\n";
	}
	wait();
}

void Actions_with_polynom()
{
	std::cout << "The polinoms you have:";
	Tables[0]->print_all();
	std::cout << "\nType name of two polynoms which ones you what to sum/multiply\n";
	std::string name1, name2;
	std::cin >> name1 >> name2;
	while (!Tables[1]->find(name1) || !Tables[1]->find(name2))
	{
		std::cout << "Wrong Input!\n";
		std::cin >> name1 >> name2;
	}
	Polynom t1 = Tables[1]->get_polynom(name1);
	Polynom t2 = Tables[1]->get_polynom(name2);
	std::cout << "Input what you want to do(+/* another symbol will be interpreted as *):";
	char c; std::cin >> c;
	Polynom tmp;
	if (c == '+')
	{
		tmp = t1 + t2;
	}
	else
	{
		tmp = t1 * t2;
	}
	std::cout << "Your polynom is: " << tmp<<"\nYou want to save it? (Y/N another symbol = N)";
	std::cin>>c;
	if (c == 'Y')
	{
		std::string name;
		std::cout << "Input name:";
		std::cin >> name;
		while (Tables[1]->find(name))
		{
			std::cout << "Table with this name is exist!";
			std::cin >> name;
		}
		for (int i = 0; i < 3; ++i)
		{
			Tables[i]->add(name,tmp);
		}
	}
	else
		tmp.clear();
}

int main()
{
	Tables = new Table* [3];
	Tables[0] = new UnorderedTable();
	Tables[1] = new OrderedTable();
	Tables[2] = new HashTable();
	while (1)
	{
		system("cls");
		std::cout << "1.Add\n2.Erase\n3.Print\n4.PrintAll\n5.find\n6.Action with polynom\n";
		int option; std::cin >> option;
		if (option == 1)
		{
			Add();
			continue;
		}
		if (option == 2)
		{
			Erase();
			continue;
		}
		if (option == 3)
		{
			Print();
			continue;
		}
		if (option == 4)
		{
			PrintAll();
			continue;
		}
		if (option == 5)
		{
			Find();
			continue;
		}
		if (option == 6)
		{
			Actions_with_polynom();
			continue;
		}
		else
			exit(0);
	}

	
}