#include <gtest.h>
#include <HashTable.h>


TEST(hash_table, can_create_table)
{
	ASSERT_NO_THROW(HashTable table);
}

TEST(hash_table, can_add_polynom)
{
	HashTable table;
	ASSERT_NO_THROW(table.add("AAA", Polynom()));
}

TEST(hash_table, added_polynom_exist)
{
	HashTable table;
	table.add("AAA", Polynom());
	EXPECT_EQ(table.find("AAA"), 1);
}

TEST(hash_table, can_erase_polynom)
{
	HashTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(hash_table, erased_polynom_doesnt_exist_in_table)
{
	HashTable table;
	table.add("AAA", Polynom());
	table.erase("AAA");
	EXPECT_NE(table.find("AAA"), 1);
}

TEST(hash_table, can_erase_nonexisting_element)
{
	HashTable table;
	ASSERT_NO_THROW(table.erase("AAA"));
}

TEST(hash_table, can_print_element)
{
	HashTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print("AAA"));
}

TEST(hash_table, can_print_all_elements)
{
	HashTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.print_all());
}

TEST(hash_table, can_get_polynom)
{
	HashTable table;
	table.add("AAA", Polynom());
	ASSERT_NO_THROW(table.get_polynom("AAA"));
}

TEST(hash_table, cant_get_non_existing_polynom)
{
	HashTable table;
	ASSERT_ANY_THROW(table.get_polynom("AAA"));
}