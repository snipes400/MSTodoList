#include "todoitem.h"

ToDoItem::ToDoItem() :
    ToDoItem("", "", 0)
{}

ToDoItem::ToDoItem(std::string name, std::string desc, int color)
    : m_done(false), m_name(name), m_desc(desc), m_color(color)
{
    static int nextId = 0;

    m_id = ++nextId;
}

int ToDoItem::id() const
{
    return m_id;
}

std::string ToDoItem::name() const
{
    return m_name;
}

void ToDoItem::setName(const std::string &newName)
{
    m_name = newName;
}

std::string ToDoItem::desc() const
{
    return m_desc;
}

void ToDoItem::setDesc(const std::string &newDesc)
{
    m_desc = newDesc;
}

void ToDoItem::setDone(bool newDone)
{
    m_done = newDone;
}

bool ToDoItem::done() const
{
    return m_done;
}

