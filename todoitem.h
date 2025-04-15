#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>
#include <QObject>
#include <QProperty>

class TodoItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool done READ getDone WRITE setDone NOTIFY isDoneChanged)
private:
    int m_id;
    bool m_isDone;
    bool m_colorInverted;

    std::string m_name;
    std::string m_desc;
    int m_color; // TODO see if there's a better way to represent color

public:
    TodoItem();
    TodoItem(std::string name, std::string desc, int color);

    int id() const;

    void setDone(bool newDone);
    bool done() const;

    std::string name() const;
    void setName(const std::string &newName);

    std::string desc() const;
    void setDesc(const std::string &newDesc);

    bool colorInverted() const;
    void setColorInverted(bool newColorInverted);

signals:
    void isDoneChanged(bool isDone);
};

#endif // TODOITEM_H
