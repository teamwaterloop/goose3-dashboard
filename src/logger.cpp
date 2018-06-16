#include "logger.h"
#include <QDebug>


Logger::Logger(const QString &fileName, QObject *parent) : QObject(parent), file(){
    m_showDate = true;
    qDebug() << "!fileName.isEmpty() = " << !fileName.isEmpty();
    //QSaveFile file("");
    if (!fileName.isEmpty()) {
       file.setFileName(fileName);
    }

    qDebug() << "fileName = " << fileName;
    qDebug() << "file.fileName() = " << file.fileName();
}

bool Logger::write(const QString &value) {
    QString text = value;
    if (m_showDate)
        text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
    if (!file.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text))
      return false;
    if (-1 == file.write(text.toUtf8()))
      return false;
    return file.commit();
}

QString Logger::getFileName(){
    return file.fileName();
}

void Logger::setShowDateTime(bool value) {
    m_showDate = value;
}

Logger::~Logger() {
    if (file.isOpen()) file.commit();
}
