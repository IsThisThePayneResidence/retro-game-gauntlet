#include <QApplication>
#include <QQmlApplicationEngine>
#include <RetroGameGauntlet.h>

int main(int argc, char *argv[])
{
    RetroGameGauntlet rgg(argc, argv, "QCoder", "RetroGameGauntlet [Cake special]");
    return rgg.exec();
    //QApplication app(argc, argv);

    //QQmlApplicationEngine engine;
    //engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //return app.exec();
}
