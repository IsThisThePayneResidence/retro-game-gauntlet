/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#include <QString>
#include "RetroGameGauntlet.h"
#include "Controller.h"
#include "Model.h"


/**
 * RetroGameGauntlet implementation
 */


/**
 * @param _argc
 * @param _argv
 * @param _organization
 * @param _application
 */
RetroGameGauntlet::RetroGameGauntlet(int _argc, char** _argv, QString _organization, QString _application):
    QApplication(_argc, _argv)
{

}

/**
 * @return Model*
 */
Model* RetroGameGauntlet::model() {
    return mdl;
}

/**
 * @param _mdl
 * @return void
 */
void RetroGameGauntlet::setModel(Model* _mdl) {
    mdl = _mdl;
}

/**
 * @return RetroGameGauntlet*
 */
RetroGameGauntlet* RetroGameGauntlet::app()
{
    return (RetroGameGauntlet*)qApp;
}

Controller *RetroGameGauntlet::controller()
{
    return contr;
}

/**
 * @param _contr
 * @return void
 */
void RetroGameGauntlet::setController(Controller* _contr)
{
    contr = _contr;
}

/**
 * @return int
 */
int RetroGameGauntlet::exec()
{
    this->mdl = new Model(QStringList(), this);
    this->contr = new Controller(this->mdl, "qrc:/main.qml", this);
    this->contr->setConnections();
    this->contr->showView();
    return QApplication::exec();
}
