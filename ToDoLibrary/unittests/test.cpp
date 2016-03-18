#include <iostream>

#include <gtest/gtest.h>

#include "main.h"
#include "todo_list.hpp"

TEST(sample_test_case, sample_test)
{
    EXPECT_EQ(1, 1);
}

TEST(second_test_cast, second_simple_test)
{
	EXPECT_NE(2, 3);
}

TEST(one_test, simple_one_test)
{
	int one = get_one();
	EXPECT_EQ(one, 1);
}


TEST(two_test, simple_two_test)
{
	int two = get_two();
	EXPECT_EQ(two, 2);
}

TEST(zz, yy)
{
	td::ToDoList tdl;

	EXPECT_EQ(tdl.NumberOfToDoItems(), static_cast<unsigned int>(0));
}

