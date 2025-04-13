#include "todolist.h"
#include "todoitem.h"

void TodoList::addItem(TodoItem& item)
{
    m_todoList.insert({item.id(), item});
}

void TodoList::removeItem(int id)
{
    auto itemToRemove = m_todoList.find(id);
    if(itemToRemove == m_todoList.end())
    {
        // TODO throw execption
    }

    m_todoList.erase(itemToRemove);
}

TodoItem& TodoList::getItem(int id)
{
    return m_todoList.at(id);
}
