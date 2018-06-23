#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QFile>
#include <QDateTime>
#include <QSaveFile>
#include <QString>

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(const QString &fileName, const QString &extension = "csv",
                    const bool showDateTimePerLine = false, const bool dateTimeInFileName = true,
                    QObject *parent = nullptr);
    ~Logger();
    void setshowDateTimePerLine(const bool value);
    QString getFileName();

private:
    QSaveFile *file;
    bool m_showDate;
    QString m_fileName;

signals:

public slots:
    bool write(const QString &value);

};

#endif // LOGGER_H
