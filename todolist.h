#ifndef TODOLIST_H
#define TODOLIST_H

#include <map>

class TodoItem;

class TodoList
{
private:
    std::map<int, TodoItem> m_todoList;

};

#endif // TODOLIST_H
