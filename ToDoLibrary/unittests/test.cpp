#include <iostream>

#include <gtest/gtest.h>

#include "main.h"
#include "todo_list.hpp"

TEST(ZeroInitialisation, SizeIsZero)
{
	td::ToDoList tdl;

    EXPECT_EQ(tdl.NumberOfToDoItems(), static_cast<unsigned int>(0));
}

TEST(ZeroInitialisation, AddToDo)
{
	td::ToDoList tdl;

	auto id = tdl.AddToDo("nothing");

	EXPECT_EQ(tdl.NumberOfToDoItems(), 1);

	EXPECT_TRUE(id);
}

TEST(ZeroInitialisation, DeleteToDo)
{
	td::ToDoList tdl;

	auto id = tdl.AddToDo("nothing");

	EXPECT_TRUE(id);

	tdl.RemoveToDo(*id);

	EXPECT_EQ(tdl.NumberOfToDoItems(), 0);
}


TEST(Item, GetAllItems)
{
	td::ToDoList tdl;

	auto id = tdl.AddToDo("nothing");
	auto items = tdl.GetToDoItems();

	EXPECT_EQ(items.size(), 1);
	EXPECT_EQ(*id, *items.begin());

	auto id2 = tdl.AddToDo("nothing2");
	EXPECT_EQ( tdl.NumberOfToDoItems(), 2 );

	tdl.RemoveToDo(*id);
	EXPECT_EQ( tdl.NumberOfToDoItems(), 1 );

	auto id_list = tdl.GetToDoItems();
	EXPECT_EQ(*id_list.begin(), *id2);

	tdl.RemoveToDo(*id2);
	EXPECT_EQ( tdl.NumberOfToDoItems(), 0 );
}

TEST(Item, Add)
{
	td::ToDoList tdl;
	
	auto id = tdl.AddToDo("nothing1");
	
	tdl.SetToDoText(*id, "text");
	
	EXPECT_EQ(*tdl.GetToDoText(*id), "text");
	EXPECT_NE(*tdl.GetToDoText(*id), "wrong_text");
	
	auto id2 = tdl.AddToDo("nothing2");
	tdl.RemoveToDo(*id2);
	
	EXPECT_EQ(tdl.GetToDoText(*id2), boost::none);
}

TEST(Item, IsValid)
{
	td::ToDoList tdl;
	
	auto id = tdl.AddToDo("nothing1");
	EXPECT_TRUE(tdl.IsIdValid(*id));
	
	tdl.RemoveToDo(*id);
	EXPECT_FALSE(tdl.IsIdValid(*id));	
}