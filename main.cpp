#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QObject>
#include <QPointer>
#include <QDebug>

#include "algorithmrunner.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    QObject *item  = engine.rootObjects().first();    

    AlgorithmRunner algorithmRunner;  
    algorithmRunner.setIncorrectGuessesTextField(item->findChild<QObject*>("incorrectGuessesTextField"));
    algorithmRunner.setComputedBoundTextField(item->findChild<QObject*>("computedBoundTextField"));

    QObject::connect(item , SIGNAL(flipCoinsSignal(int, int)),
                     &algorithmRunner, SLOT(flipCoinsNTimes(int,int)));

    return app.exec();
}

