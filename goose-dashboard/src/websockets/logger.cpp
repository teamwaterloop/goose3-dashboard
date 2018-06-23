#include "logger.h"
#include <QDebug>

namespace wloop {

Logger::Logger(const QString &fileName, const QString &extension,
               const bool showDateTimePerLine, const bool dateTimeInFileName,
               QObject *parent) : m_showDate(showDateTimePerLine), QObject(parent){
    if (dateTimeInFileName) {
        m_fileName = fileName + "-" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ")
                + "." + extension;
    } else {
        m_fileName = fileName + "." + extension;
    }

    if (!fileName.isEmpty()) {
       file.setFileName(m_fileName);
    }
    file.open(QIODevice::WriteOnly | QIODevice::Text);
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

void Logger::destruct()
{
    qDebug() << Q_FUNC_INFO;
    file.commit();
}

QString Logger::getFileName(){
    return file.fileName();
}

void Logger::setshowDateTimePerLine(const bool value) {
    m_showDate = value;
}


}
