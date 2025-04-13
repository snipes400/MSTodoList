#include "todoitem.h"

TodoItem::TodoItem() :
    TodoItem("", "", 0)
{}

TodoItem::TodoItem(std::string name, std::string desc, int color)
    : m_done(false), m_name(name), m_desc(desc), m_color(color)
{
    static int nextId = 0;

    m_id = ++nextId;
}

int TodoItem::id() const
{
    return m_id;
}

std::string TodoItem::name() const
{
    return m_name;
}

void TodoItem::setName(const std::string &newName)
{
    m_name = newName;
}

std::string TodoItem::desc() const
{
    return m_desc;
}

void TodoItem::setDesc(const std::string &newDesc)
{
    m_desc = newDesc;
}

void TodoItem::setDone(bool newDone)
{
    m_done = newDone;
}

bool TodoItem::done() const
{
    return m_done;
}

