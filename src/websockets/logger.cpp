#include "logger.h"
#include <QDebug>
#include <QStandardPaths>

namespace wloop {

Logger::Logger(const QString &fileName, const QString &extension,
               const bool showDateTimePerLine, const bool dateTimeInFileName,
               QObject *parent) : m_showDate(showDateTimePerLine), QObject(parent){
    if (dateTimeInFileName) {
        QString path = QStandardPaths::standardLocations(QStandardPaths::DocumentsLocation)[0] + "/Github/";
        //QString path = "/Users/Ash/Documents/Github/";
        m_fileName = path + fileName + "-" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss")
                + "." + extension;
        qDebug() << m_fileName;
    } else {
        m_fileName = fileName + "." + extension;
    }

    if (file.fileName().isEmpty()) {
       file.setFileName(m_fileName);
    }
    if (file.open(QIODevice::WriteOnly))
        qDebug() << "File opened sucessfully";
    else
        qDebug() << "Couldn't open file";
}

bool Logger::write(const QString &value) {
    qDebug() << Q_FUNC_INFO;
    QString text = value;
    if (m_showDate)
        text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") +
                "- " + text + "\n";
    else
        text = text + "\n";
    if (-1 == file.write(text.toUtf8()))
    {
        qDebug() << "false";
        return false;
    }
    else
        return true;
}

bool Logger::destruct()
{
    qDebug() << Q_FUNC_INFO;
    bool x =  file.commit();
    qDebug() << x;
    return x;
}

QString Logger::getFileName(){
    return file.fileName();
}

void Logger::setshowDateTimePerLine(const bool value) {
    m_showDate = value;
}
}
