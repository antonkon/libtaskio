#include "task_list.h"

#include <QDir>
#include <QFile>
#include <QCoreApplication>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonValue>
#include <QJsonParseError>
#include <QDebug>


TaskList::TaskList()
{
    loadList();
}

TaskList::~TaskList()
{
    saveList();

    foreach (Task *group, this->list.values()) {
        delete group;
    }
}

void TaskList::loadList() {
    QFile file;
    QJsonParseError error;

    // Задать название файла
    QDir dir = QDir(QCoreApplication::applicationDirPath());

    file.setFileName(dir.path() + "/" + this->__json__);

    // Проверить наличие файла
    if (!file.exists()) return;

    // Прочитать файл
    QString text;
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    text = file.readAll();
    file.close();

    // Преобразование текстовых данных в json формате в документ
    QJsonDocument doc = QJsonDocument::fromJson(text.toUtf8(), &error);
    // Если возникла ошибка выходим
    if (error.error != 0) {
        qDebug() << "Ошибка во время обработки текстового файла: " <<
                    error.errorString() << error.error;
        return;
    }

    // Преобразование документа в объект
    QJsonArray json_root = doc.array();

    // Заполнение списка задач
    foreach (const QJsonValue &item_json, doc.array()) {
        QJsonObject item = item_json.toObject();
        Task *task = new Task(item);
        this->list.insert(task->getTitle(), task);
    }
}

void TaskList::saveList() {
    QJsonArray json_array;
    QStringList name_list = this->list.keys();
    std::reverse(name_list.begin(), name_list.end());

    foreach (QString key, name_list) {
        Task *t = this->list.value(key);
        json_array.push_back(t->getJSONData());
    }

    QJsonDocument doc(json_array);

    QDir dir = QDir(QCoreApplication::applicationDirPath());

    QFile file;
    file.setFileName(dir.path() + "/" +this->__json__);
    file.open(QIODevice::WriteOnly | QIODevice::Text);
    file.write(doc.toJson());
    file.close();
}


void TaskList::addTask(QString title, QString text) {
    Task *task = new Task(title, text);
    this->list.insert(title, task);
}

void TaskList::removeTask(QString name) {
    this->list.remove(name);
}

QStringList TaskList::getListTitle() {
    return this->list.keys();
}

Task* TaskList::getTask(QString title) {
    return this->list.value(title);
}
