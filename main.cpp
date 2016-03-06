#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QObject>
#include <QPointer>
#include <QDebug>

#include "algorithmrunner.h"
/*
class SignalBroker : public QObject{
    Q_OBJECT
public slots:
    void brokerFlipCoins(int &m, int &n){

        qDebug() << "Received " << m << " and " << n;

        // create new Algorithm Runner and set the new values
        //AlgorithmRunner *alg = new AlgorithmRunner(m, n);
        QPointer<AlgorithmRunner> pAlg(new AlgorithmRunner(m, n));

        pAlg->flipCoins();

        qDebug() << "Output = " << pAlg->getP_hat();
    }
};*/

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QQuickView view(QUrl(QStringLiteral("qrc:/main.qml")));
    //QObject *item = (QObject*) view.rootObject();
    QObject *item  = engine.rootObjects().first();

    //SignalBroker signalBroker;
    AlgorithmRunner algorithmRunner;
    QObject::connect(item , SIGNAL(flipCoinsSignal(int, int)),
                     &algorithmRunner, SLOT(flipCoins(int,int)));

    return app.exec();
}

