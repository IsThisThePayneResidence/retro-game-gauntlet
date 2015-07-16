/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */

#include <QQuickView>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQuickItem>
#include <QQmlEngine>
#include <QDir>
#include "Model.h"
#include "Controller.h"


/**
 * Controller implementation
 */


/**
 * @param _mdl
 * @return void
 */
Controller::Controller(Model* _mdl, QString _viewPath, QObject* _parent):
    QObject(_parent)
{
    if(_mdl)
        mdl = _mdl;
    if(!_viewPath.isEmpty())
        qmlView = new QQuickView(QUrl(_viewPath));
    qmlView->rootContext()->setContextProperty("rggController", this);
    qmlView->rootContext()->setContextProperty("rggModel", mdl);
    qmlView->engine()->rootContext()->setContextProperty("rggExePath", QDir::currentPath());
}

void Controller::setModel(Model* _mdl)
{
    if(_mdl)
        mdl = _mdl;
}

/**
 * @return Model*
 */
Model* Controller::model()
{
    return mdl;
}

QString Controller::path()
{
    return QDir::currentPath();
}

/**
 * @return QQuickView*
 */
QQuickView* Controller::view()
{
    return qmlView;
}

/**
 * @param QQuickView* _view
 * @return void
 */
void Controller::setView(QQuickView* _view)
{
    if(_view)
        qmlView = _view;
}

/**
 * @return void
 */
void Controller::setConnections()
{
    QObject* object = qmlView->rootObject()->findChild<QObject*>("tvSetMain");
    //QObject::connect(this, SIGNAL(viewLoaded()), object, SLOT(start()));
}

/**
 * @return void
 */
void Controller::showView()
{
    qmlView->setFlags(Qt::MSWindowsFixedSizeDialogHint | Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint);

    emit viewLoaded();
    qmlView->show();
}

Controller::~Controller()
{
    //if(qmlView)
    //    delete qmlView;
}

void Controller::setPath(QString _path)
{
    exePath = _path;
}
