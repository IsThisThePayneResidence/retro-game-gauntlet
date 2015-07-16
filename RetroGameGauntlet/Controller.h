/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#ifndef _CONTROLLER_H
#define _CONTROLLER_H

#include "QObject.h"

class Model;
class QQuickView;

class Controller: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString rggExePath READ path WRITE setPath NOTIFY pathChanged)
protected:
    Model* mdl;
    QQuickView* qmlView;
    QString exePath;

public: 
    Controller(Model* _mdl, QString _viewPath, QObject* _parent = nullptr);
	
	/**
	 * @param _mdl
	 */
	void setModel(Model* _mdl);
	
	Model* model();

    QString path();
	
	QQuickView* view();
	
	/**
	 * @param QQuickView* _view
	 */
    void setView(QQuickView* _view);
	
	void setConnections();
	
	void showView();

    ~Controller();

signals:

    void viewLoaded();

    void pathChanged(QString& _path);

public slots:

    void setPath(QString _path);


};

#endif //_CONTROLLER_H
