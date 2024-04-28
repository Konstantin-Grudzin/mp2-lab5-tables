#include <gtest.h>
#include "UnorederedTable.h"

TEST(unordered_table, can_create_table)
{
	ASSERT_NO_THROW(UnorderedTable table);
}

TEST(unordered_table, can_add_polynom)
{
	UnorderedTable table;
	ASSERT_NO_THROW(table.add("AAA",Polynom()));
}

TEST(unordered_table, added_polynom_exist)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	EXPECT_EQ(table.find("AAA"), 1);
}

TEST(unordered_table, can_erase_polynom)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(unordered_table, erased_polynom_doesnt_exist_in_table)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	table.erase("AAA");
	EXPECT_NE(table.find("AAA"), 1);
}

TEST(unordered_table, can_erase_nonexisting_element)
{
	UnorderedTable table;
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(unordered_table, can_print_element)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print("AAA"));
}

TEST(unordered_table, can_print_all_elements)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print_all());
}

TEST(unoredred_table, can_get_polynom)
{
	UnorderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.get_polynom("AAA"));
}

TEST(unoredred_table, cant_get_non_existing_polynom)
{
	UnorderedTable table;
	ASSERT_ANY_THROW(table.get_polynom("AAA"));
}