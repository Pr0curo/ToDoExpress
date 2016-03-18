#pragma once

#include <vector>

namespace td
{
	class ToDo
	{

	};
	
	class ToDoList
	{
	public:
		ToDoList();
		~ToDoList();

		unsigned int NumberOfToDoItems();

	private:
		std::vector<ToDo> m_ToDos;
	};
} // namespace td;