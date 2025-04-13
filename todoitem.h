#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>

class ToDoItem
{
private:
    int m_id;
    bool m_done;

    std::string m_name;
    std::string m_desc;
    int m_color; // TODO see if there's a better way to represent color

public:
    ToDoItem();
    ToDoItem(std::string name, std::string desc, int color);

    int id() const;

    void setDone(bool newDone);
    bool done() const;

    std::string name() const;
    void setName(const std::string &newName);

    std::string desc() const;
    void setDesc(const std::string &newDesc);
};

#endif // TODOITEM_H
