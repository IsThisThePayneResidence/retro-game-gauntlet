/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */
#include <QObject>
#include <QTimer>
#include <QString>
#include <QDate>
#include <QTime>
#include <QJsonObject>
#include <QVariant>
#include "Game.h"

/**
 * Game implementation
 */

/**
 * @param QJsonObject& _json
 */
Game::Game(QJsonObject& _json, QObject *_parent):
    QObject(_parent)
{
    this->jsonRead(_json);
}

/**
 * @param _name
 * @param _system
 * @param _datePicked
 * @param _runTime
 * @param _state
 * @param _description
 */
Game::Game(QString _name, QString _system, QDate _datePicked, QTime _runTime, GAME_STATE _state, QString _description, QObject* _parent):
    QObject(_parent)
{
    this->gameName = _name;
    this->gameSystem = _system;
    this->gameDatePicked = _datePicked;
    this->gameRunTime.setRaw(_runTime.msec());
    this->gameState = _state;
    this->gameDescription = _description;
}

/**
 * @param QString _name
 * @return void
 */
void Game::setName(QString _name)
{
    gameName = _name;
    emit nameSet(gameName);
}

/**
 * @return QString
 */
QString Game::name()
{
    return gameName;
}

/**
 * @param QDate _date
 * @return void
 */
void Game::setDatePicked(QDate _date)
{
    gameDatePicked = _date;
    emit datePickedSet(gameDatePicked);
}

/**
 * @return QDate
 */
QDate Game::datePicked()
{
    return gameDatePicked;
}

/**
 * @param GAME_STATE _gameState
 * @return void
 */
void Game::setGameState(GAME_STATE _gameState)
{
    gameState = _gameState;
    emit gameStateSet(gameState);
}

/**
 * @return [object Object]
 */
GAME_STATE Game::state()
{
    return gameState;
}

/**
 * @return void
 */
void Game::startRun()
{
    gameRunTime.onStart();
    emit runStarted();
}

/**
 * @return QTime
 */
QTime Game::runTime()
{
    QTime res(0, 0);
    res.addMSecs(gameRunTime.raw());
    return res;
}

/**
 * @return void
 */
void Game::pauseRun()
{
    gameRunTime.onPause();
    emit runPaused();
}

/**
 * @return QString
 */
QString Game::system()
{
    return gameSystem;
}

/**
 * @param QString _system
 * @return void
 */
void Game::setSystem(QString _system)
{
    gameSystem = _system;
    emit systemSet(gameSystem);
}

/**
 * @return QString
 */
QString Game::description()
{
    return gameDescription;
}

/**
 * @param QString _desc
 * @return void
 */
void Game::setDesctiption(QString _desc)
{
    gameDescription = _desc;
    emit descriptionSet(gameDescription);
}

/**
 * @param QJsonObject& _json
 * @return void
 */
void Game::jsonWrite(QJsonObject& _json)
{
    _json["system"] = this->gameSystem;
    _json["datePicked"] = this->gameDatePicked.toString();
    _json["description"] = this->gameDescription;
    _json["name"] = this->gameName;
    _json["runTime"] = this->gameRunTime.raw();
    _json["state"] = stateAssignment.key(this->gameState);
    emit wroteToJson(_json);
}

/**
 * @param QJsonObject& _json
 * @return void
 */
void Game::jsonRead(QJsonObject& _json)
{
    this->gameSystem = _json["system"].toString();
    this->gameDatePicked.fromString(_json["datePicked"].toString());
    this->gameDescription = _json["description"].toString();
    this->gameName = _json["name"].toString();
    this->gameRunTime.setRaw(_json["runTime"].toVariant().toLongLong());
    this->gameState = stateAssignment.value(_json["state"].toString());
    readFromJson(_json);
}

QMap<QString, GAME_STATE> Game::stateAssignment;
