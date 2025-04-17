#include "todolist.h"
#include "todoitem.h"


void TodoList::addItem(TodoItem* item)
{
    //m_todoList.insert({item.id(), item});
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_todoItems.append(item);
    endInsertRows();
}

void TodoList::removeItem(const QModelIndex &index)
{
    m_todoItems.remove(index.row());
}
/*
TodoItem& TodoList::getItem(int id)
{
    return m_todoList.at(id);
}
*/

int TodoList::rowCount(const QModelIndex &parent) const
{
    return m_todoItems.count();
}

QHash<int, QByteArray> TodoList::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[TodoItemRole] = "TodoItem";
    return roles;
}

QVariant TodoList::data(const QModelIndex &index, int role) const
{
    auto todoItem = m_todoItems.at(index.row());
    return QVariant::fromValue(todoItem);
}

bool TodoList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //auto todoItem = m_todoItems.at(index.row());

    auto newTodoItem = qvariant_cast<TodoItem*>(value);
    if(!newTodoItem) {
        return false;
    }

    m_todoItems[index.row()] = newTodoItem;

    return true;
}



