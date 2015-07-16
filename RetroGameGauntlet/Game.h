/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#ifndef _GAME_H
#define _GAME_H
#include "GAME_STATE.h"
#include <QMap>

class QObject;
class QJsonObject;
class QString;
class QDate;
class QTime;
class QTimer;
#include <Stopwatch.h>


class Game: public QObject
{
    Q_OBJECT
private:
    QString gameName;
    QDate gameDatePicked;
    Stopwatch gameRunTime;
    GAME_STATE gameState;
    QString gameSystem;
    QString gameDescription;
    static QMap<QString, GAME_STATE> stateAssignment;

public: 
    /**
     * @param QJsonObject& _json
     */
    Game(QJsonObject& _json, QObject* _parent = nullptr);

    /**
     * @param _name
     * @param _system
     * @param _datePicked
     * @param _runTime
     * @param _state
     * @param _description
     */
    Game(QString _name, QString _system, QDate _datePicked = QDate::currentDate(), QTime _runTime = QTime(0, 0), GAME_STATE _state = GAME_STATE::CURRENT, QString _description = "", QObject* _parent = nullptr);
	
    QString name();
	
	QDate datePicked();

    GAME_STATE state();
	
    QTime runTime();
	
    QString system();
	
    QString description();

public slots:

    void pauseRun();

    void startRun();

    /**
     * @param QString _desc
     */
    void setDesctiption(QString _desc);

    /**
     * @param QJsonObject& _json
     */
    void jsonWrite(QJsonObject& _json);

    /**
     * @param QJsonObject& _json
     */
    void jsonRead(QJsonObject& _json);

    /**
     * @param QDate _date
     */
    void setDatePicked(QDate _date);

    /**
     * @param GAME_STATE _gameState
     */
    void setGameState(GAME_STATE _gameState);

    /**
     * @param QString _system
     */
    void setSystem(QString _system);

    /**
     * @param QString _name
     */
    void setName(QString _name);

signals:

    void runPaused();

    void runStarted();

    void descriptionSet(QString& _desc);

    void wroteToJson(QJsonObject& _json);

    void readFromJson(QJsonObject& _json);

    void datePickedSet(QDate& _date);

    void gameStateSet(GAME_STATE _gameState);

    void systemSet(QString& _sys);

    void nameSet(QString& _name);
};

#endif //_GAME_H
