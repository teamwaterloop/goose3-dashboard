#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtWidgets>

int main(int argc, char *argv[])
{
    /**
     * https://bugreports.qt.io/browse/QTBUG-64697?focusedCommentId=380295&page=com.atlassian.jira.plugin.system.issuetabpanels%3Acomment-tabpanel#comment-380295
     *
     * All QML apps crash on Intel UHD Grpahics 620
     * Confirmed on Windows 10, with Qt 5.10.1 MSVC 2017 */
    QCoreApplication::setAttribute(Qt::AA_DisableShaderDiskCache);

#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
