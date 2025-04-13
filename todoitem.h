#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>

class TodoItem
{
private:
    int m_id;
    bool m_done;
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
};

#endif // TODOITEM_H
