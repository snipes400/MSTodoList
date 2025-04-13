#ifndef TODOLIST_H
#define TODOLIST_H

#include <map>

class TodoItem;

class TodoList
{
private:
    std::map<int, TodoItem> m_todoList;

public:
    void addItem(TodoItem& item);
    void removeItem(int id);
    TodoItem& getItem(int id);

};

#endif // TODOLIST_H
