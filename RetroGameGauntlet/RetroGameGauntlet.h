/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#ifndef _RETROGAMEGAUNTLET_H
#define _RETROGAMEGAUNTLET_H

#include <QApplication>

class Model;
class Controller;

class RetroGameGauntlet: public QApplication
{
    Q_OBJECT

protected:
    Model* mdl;
    Controller* contr;

public: 
	
	/**
	 * @param _argc
	 * @param _argv
	 * @param _organization
	 * @param _application
	 */
    RetroGameGauntlet(int _argc, char** _argv, QString _organization, QString _application);
	
	Model* model();
	
	/**
	 * @param _mdl
	 */
	void setModel(Model* _mdl);
	
    static RetroGameGauntlet* app();
	
    Controller* controller();
	
	/**
	 * @param _contr
	 */
	void setController(Controller* _contr);
	
    int exec();

};

#endif //_RETROGAMEGAUNTLET_H
