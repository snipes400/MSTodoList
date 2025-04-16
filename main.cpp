#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "todoitem.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<TodoItem>("com.todolist", 1, 0, "TodoItem");

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("MPTodo", "Main");

    return app.exec();
}
