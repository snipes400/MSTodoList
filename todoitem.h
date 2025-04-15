#ifndef TODOITEM_H
#define TODOITEM_H

#include <string>
#include <QObject>
#include <QProperty>

class TodoItem : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool done READ done WRITE setDone NOTIFY isDoneChanged)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
private:
    int m_id;
    bool m_isDone;
    bool m_colorInverted;

    QString m_title;
    std::string m_desc;
    int m_color; // TODO see if there's a better way to represent color

public:
    TodoItem();
    TodoItem(QString title, std::string desc, int color);

    int id() const;

    void setDone(bool newDone);
    bool done() const;

    QString title() const;
    void setTitle(const QString &newTitle);

    std::string desc() const;
    void setDesc(const std::string &newDesc);

    bool colorInverted() const;
    void setColorInverted(bool newColorInverted);

signals:
    void isDoneChanged(bool isDone);
    void titleChanged(QString name);
};

#endif // TODOITEM_H
