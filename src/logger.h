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
    explicit Logger(const QString &fileName, QObject *parent = nullptr);
    ~Logger();
    void setShowDateTime(bool value);
    QString getFileName();

private:
    QSaveFile file;
    bool m_showDate;

signals:

public slots:
    bool write(const QString &value);

};

#endif // LOGGER_H
