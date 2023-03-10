#include <QGuiApplication>
#include <QQmlApplicationEngine>

// ANCHOR: book_cpp_include
#include "cxx-qt-gen/my_object.cxxqt.h"
// ANCHOR_END: book_cpp_include

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine, &QQmlApplicationEngine::objectCreated, &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl) QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    qmlRegisterType<MyObject>("com.kdab.cxx_qt.demo", 1, 0, "MyObject");

    engine.load(url);

    return app.exec();
}
