#ifndef TASK_H
#define TASK_H

#include "libtaskio_global.h"
#include <QString>
#include <QJsonObject>


class TASKIO_EXPORT Task
{
public:
    Task(QString title, QString text);
    Task(QJsonObject json_obj);
    Task(const Task &task);

    void changeTitle(QString new_title);

    void changeText(QString new_text);

    void setOverdue(bool new_overdue);

    void setCompleted(bool new_completed);

    void setImportance(bool new_importance);

    QString getTitle();

    QString getText();

    bool getOverdue();

    bool getCompleted();

    bool getImportance();

    QJsonObject getJSONData();

    friend bool operator==(const Task &a, const Task &b) {
        return a.title == b.title;
    }

private:
    QString title;

    QString text;

    // Задача просрочена
    bool is_overdue = false;
    // Задачи выполнена
    bool is_completed = false;
    // Задача важная
    bool is_importance = false;
};

#endif // TASK_H
