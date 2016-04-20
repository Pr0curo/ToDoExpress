#pragma once

#include <iostream>
#include <vector>

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/uuid_generators.hpp>

#include <boost/optional.hpp>

#include <unordered_map>
#include <map>
#include <boost/functional/hash.hpp>

namespace std
{

template<>
struct hash<boost::uuids::uuid>
{
    size_t operator () (const boost::uuids::uuid& uid)
    {
        return boost::hash<boost::uuids::uuid>()(uid);
    }
};

}


namespace td
{
	typedef boost::uuids::uuid item_id;

	class ToDo
	{
	public:
		std::string Text;		
	};
	
	class ToDoList
	{
	public:
		ToDoList();
		~ToDoList();

		unsigned int NumberOfToDoItems() const noexcept;

		boost::optional<item_id> AddToDo(std::string);

		void RemoveToDo(const item_id& id);

		std::vector<item_id> GetToDoItems();
		
		bool SetToDoText(item_id id, const std::string& text)
		{
			auto todo_item = m_ToDos.find(id);
			if(todo_item == m_ToDos.end())
			{
				return false;
			}
			
			todo_item->second.Text = text;
			
			return true;			
		}
		
		boost::optional<std::string> GetToDoText(item_id id) const
		{
			auto todo_item = m_ToDos.find(id);
			if(todo_item == m_ToDos.end())
			{
				return boost::none;
			}
			
			return todo_item->second.Text;	
		}
		
		bool IsIdValid(item_id id) const
		{
			auto todo_item = m_ToDos.find(id);
			if( todo_item == m_ToDos.end() )
			{
				return false;
			}
			
			return true;
		}

	private:
		std::map<item_id, ToDo> m_ToDos;
	};
} // namespace td;