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

};

#endif // TODOITEM_H
