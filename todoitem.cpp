#include "todoitem.h"

ToDoItem::ToDoItem(std::string name, std::string desc, int color)
    : m_done(false), m_name(name), m_desc(desc), m_color(color)
{
    static int nextId = 0;

    m_id = ++nextId;
}

ToDoItem::ToDoItem() :
    ToDoItem("", "", 0)
{}

