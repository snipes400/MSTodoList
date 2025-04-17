#include "todoitem.h"

TodoItem::TodoItem(QObject* parent) :
    TodoItem("", "", 0, parent)
{}

TodoItem::TodoItem(QString title, QString desc, int color, QObject* parent)
    : QObject(parent),
    m_isDone(false), m_title(title), m_desc(desc), m_color(color), m_colorInverted(false)
{
    static int nextId = 0;

    m_id = ++nextId;
}

int TodoItem::id() const
{
    return m_id;
}

QString TodoItem::title() const
{
    return m_title;
}

void TodoItem::setTitle(const QString &newTitle)
{
    if(newTitle != m_title)
    {
        m_title = newTitle;
        emit titleChanged(newTitle);
    }
}

QString TodoItem::desc() const
{
    return m_desc;
}

void TodoItem::setDesc(const QString &newDesc)
{
    if(newDesc != m_desc)
    {
        m_desc = newDesc;
        emit descChanged(newDesc);
    }

}

void TodoItem::setDone(bool newDone)
{
    if(newDone != m_isDone)
    {
        m_isDone = newDone;
        emit isDoneChanged(newDone);
    }
}

bool TodoItem::done() const
{
    return m_isDone;
}

bool TodoItem::colorInverted() const
{
    return m_colorInverted;
}

void TodoItem::setColorInverted(bool newColorInverted)
{
    m_colorInverted = newColorInverted;
}
