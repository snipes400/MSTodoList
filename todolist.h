#ifndef TODOLIST_H
#define TODOLIST_H

#include <map>
#include <QAbstractListModel>

class TodoItem;

class TodoList : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles{
        TodoItemRole = Qt::UserRole + 1
    };



private:
    //std::map<int, TodoItem> m_todoList;
    QList<TodoItem*> m_todoItems;

public:
    int rowCount(const QModelIndex &parent=QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole) override;


    void addItem(TodoItem* item);


    void removeItem(const QModelIndex &index);
    //TodoItem& getItem(int id);

};

#endif // TODOLIST_H
