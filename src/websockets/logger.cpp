//#include "Logger.h"

//namespace wloop {

//Logger::Logger(QObject *parent, QString fileName) : QObject(parent) {
//    m_showDate = true;
//    if (!fileName.isEmpty()) {
//        file = new QFile;
//        file->setFileName(fileName);
//        file->open(QIODevice::WriteOnly);
//    }
//}

//void Logger::write_to_log(const QString &value) {
//    QString text = value;// + "";
//    if (m_showDate)
//        text = QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss ") + text;
//    //QTextStream out(file);
//    //out.setCodec("UTF-8");
//    if (file != 0) {
//        file->writeData(text, text.length());

//    }
//}

//void Logger::setShowDateTime(bool value) {
//    m_showDate = value;
//}

//Logger::~Logger() {
//    if (file != 0)
//        file->close();
//}

//} //end namespace
