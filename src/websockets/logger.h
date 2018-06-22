#ifndef LOGGER_H
#define LOGGER_H

#include <QObject>
#include <QPlainTextEdit>
#include <QSaveFile>
#include <QTextStream>
#include <QDateTime>

namespace wloop {

class Logger : public QObject
{
    Q_OBJECT
public:
    explicit Logger(QObject *parent, QString fileName = "./test.txt");
    ~Logger();
    void setShowDateTime(bool value);

private:
    QSaveFile *file;
    //QPlainTextEdit *m_editor;
    bool m_showDate;

signals:

public slots:
    void write_to_log(const QString &value);

};

} //end namespace
#endif // LOGGER_H
