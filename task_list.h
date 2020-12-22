#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "libtaskio_global.h"
#include "task.h"
#include <QString>
#include <QHash>


class TASKIO_EXPORT TaskList
{
public:
    TaskList();
    ~TaskList();

    void addTask(QString title, QString text);

    void changeTask(QString title);

    void removeTask(QString title);

    QStringList getListTitle();

    Task* getTask(QString title);

private:
    QString __json__ = "tasks.json";

    QHash <QString, Task*> list;

    void loadList();

    void saveList();
};

#endif // TASK_LIST_H
