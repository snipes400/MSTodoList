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
    Q_PROPERTY(QString desc READ desc WRITE setDesc NOTIFY descChanged)

private:
    int m_id;
    bool m_isDone;
    bool m_colorInverted;

    QString m_title;
    QString m_desc;
    int m_color; // TODO see if there's a better way to represent color

public:
    TodoItem();
    TodoItem(QString title, QString desc, int color);

    int id() const;

    void setDone(bool newDone);
    bool done() const;

    QString title() const;
    void setTitle(const QString &newTitle);

    QString desc() const;
    void setDesc(const QString &newDesc);

    bool colorInverted() const;
    void setColorInverted(bool newColorInverted);

signals:
    void isDoneChanged(bool isDone);
    void titleChanged(QString name);
    void descChanged(QString desc);
};

#endif // TODOITEM_H
