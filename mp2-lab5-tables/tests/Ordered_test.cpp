#include <gtest.h>
#include<OrderedTable.h>

TEST(ordered_table, can_create_table)
{
	ASSERT_NO_THROW(OrderedTable table);
}

TEST(ordered_table, can_add_polynom)
{
	OrderedTable table;
	ASSERT_NO_THROW(table.add("AAA", Polynom()));
}

TEST(ordered_table, added_polynom_exist)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	EXPECT_EQ(table.find("AAA"), 1);
}

TEST(ordered_table, can_erase_polynom)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(ordered_table, erased_polynom_doesnt_exist_in_table)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	table.erase("AAA");
	EXPECT_NE(table.find("AAA"), 1);
}

TEST(ordered_table, can_erase_nonexisting_element)
{
	OrderedTable table;
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(ordered_table, can_print_element)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print("AAA"));
}

TEST(ordered_table, can_print_all_elements)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print_all());
}

TEST(oredered_table, can_get_polynom)
{
	OrderedTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.get_polynom("AAA"));
}

TEST(ordered_table, cant_get_non_existing_polynom)
{
	OrderedTable table;
	ASSERT_ANY_THROW(table.get_polynom("AAA"));
}