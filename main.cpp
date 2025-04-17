#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "todoitem.h"
#include "todolist.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TodoItem>("com.todo", 1, 0, "TodoItem");
    qmlRegisterType<TodoList>("com.todo", 1, 0, "TodoList");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MPTodo", "Main");

    return app.exec();
}
