#include "todo_list.hpp"

namespace td
{
	ToDoList::ToDoList() 
	{

	}
	
	ToDoList::~ToDoList() 
	{

	}

	unsigned int ToDoList::NumberOfToDoItems()
	{
		return m_ToDos.size();
	}
}