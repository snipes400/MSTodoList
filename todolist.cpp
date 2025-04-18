#include "todolist.h"
#include "todoitem.h"


void TodoList::addItem(TodoItem* item)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_todoItems.append(item);
    endInsertRows();
}

void TodoList::removeItem(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_todoItems.remove(index);
    endRemoveRows();
}

int TodoList::rowCount(const QModelIndex &parent) const
{
    return m_todoItems.count();
}

QHash<int, QByteArray> TodoList::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[TodoItemRole] = "todoitem";
    return roles;
}

QVariant TodoList::data(const QModelIndex &index, int role) const
{
    auto todoItem = m_todoItems.at(index.row());
    return QVariant::fromValue(todoItem);
}

bool TodoList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    auto newTodoItem = qvariant_cast<TodoItem*>(value);
    if(!newTodoItem) {
        return false;
    }

    m_todoItems[index.row()] = newTodoItem;

    return true;
}



