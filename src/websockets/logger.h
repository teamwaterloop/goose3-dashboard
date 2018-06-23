#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QSaveFile>
#include <QString>

namespace wloop {

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(const QString &fileName, const QString &extension = "csv",
                    const bool showDateTimePerLine = false, const bool dateTimeInFileName = true,
                    QObject *parent = nullptr);
    void setshowDateTimePerLine(const bool value);
    QString getFileName();
    bool write(const QString &value);


private:
    QSaveFile file;
    bool m_showDate;
    QString m_fileName;

signals:
    void onClose();

public slots:
    bool destruct();
};
}

#endif // LOGGER_H

