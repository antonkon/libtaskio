#include "task.h"

Task::Task(QString title, QString text) :
    title(title), text(text)
{}

Task::Task(const Task &task) :
    title(task.title), text(task.text)
{}

Task::Task(QJsonObject json_obj)
{
    this->title = json_obj["title"].toString();
    this->text = json_obj["text"].toString();
    this->is_overdue = json_obj["is_overdue"].toBool();
    this->is_completed = json_obj["is_completed"].toBool();
}

void Task::changeTitle(QString new_title) {
    this->title = new_title;
}

void Task::changeText(QString new_text) {
    this->text = new_text;
}

void Task::setOverdue(bool new_overdue) {
    this->is_overdue = new_overdue;
}

void Task::setCompleted(bool new_completed) {
    this->is_completed = new_completed;
}

QString Task::getTitle() {
    return this->title;
}

QString Task::getText() {
    return this->text;
}

bool Task::getOverdue() {
    return this->is_overdue;
}

bool Task::getCompleted() {
    return this->is_completed;
}

QJsonObject Task::getJSONData() {
    QJsonObject json_obj;
    json_obj.insert("title", this->title);
    json_obj.insert("text", this->text);
    json_obj.insert("is_overdue", this->is_overdue);
    json_obj.insert("is_completed", this->is_completed);

    return json_obj;
}
