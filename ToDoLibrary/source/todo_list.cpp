#include "todo_list.hpp"
#include <iostream>

namespace td
{
	ToDoList::ToDoList() 
	{

	}
	
	ToDoList::~ToDoList() 
	{

	}

	unsigned int ToDoList::NumberOfToDoItems() const noexcept
	{
		return m_ToDos.size();	
	}

	boost::optional<item_id> ToDoList::AddToDo(std::string Text)
	{
		ToDo td;
		td.Text = Text;

		boost::uuids::random_generator gen;
		auto item_id_ = gen();

		m_ToDos.insert(std::make_pair<item_id, ToDo>(std::move(item_id_), std::move(td)));

		return item_id_;
	}

	void ToDoList::RemoveToDo(const item_id& id)
	{
		auto it = m_ToDos.find(id);
		if( it == m_ToDos.end() )
		{
			std::cout << "zu entfernendes todo nicht gefunden" << std::endl;
			//for( const auto& it : m_ToDos )
			//{
			//	std::cout << it.first << "=" << it.second.Text << std::endl;
			//}
		}

		if(m_ToDos.erase(id) < 1)
		{
			std::cout << "nothing ereased" << std::endl;
		}
	}

	std::vector<item_id> ToDoList::GetToDoItems()
	{
		std::vector<item_id> items;
				
		for( const auto& todo : m_ToDos )	
		{
			items.push_back(todo.first);
		}

		return items;
	}
}