/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */

#include <QJsonArray>
#include <QJsonObject>
#include "Season.h"
#include "Game.h"

/**
 * Season implementation
 */

/**
 * @param QJsonObject& _json
 */
Season::Season(QJsonObject& _json, QObject *_parent):
    QObject(_parent)
{
    this->jsonRead(_json);
}

/**
 * @param _id
 * @param _history
 * @param _currentGameIndex
 */
Season::Season(unsigned int _id, QList<Game*> _history, unsigned int _currentGameIndex, QObject *_parent):
    QObject(_parent)
{
    this->id = _id;
    this->history = _history;
    this->currentGameIndex = _currentGameIndex;
}

/**
 * @param Game* _game
 * @return void
 */
void Season::addGame(Game* _game)
{
    this->history.append(_game);
    emit gameAdded(_game);
}

/**
 * @param unsigned int _index
 * @return Game*
 */
Game* Season::game(unsigned int _index)
{
    return _index < this->history.size() ? history[_index] : nullptr;
}

/**
 * @return Game*
 */
Game* Season::currentGame()
{
    return this->currentGameIndex < this->history.size() ? history[this->currentGameIndex] : nullptr;;
}

/**
 * @return QList<Game*>
 */
QList<Game*> Season::games()
{
    return this->history;
}

/**
 * @param QJsonObject& _json
 * @return void
 */
void Season::jsonWrite(QJsonObject& _json)
{
    QJsonArray games;
    for(Game* g : this->history)
    {
        QJsonObject game;
        g->jsonWrite(game);
        games.append(game);
    }
    _json["id"] = int(this->id);
    _json["currentIndex"] = int(this->currentGameIndex);
    _json["games"] = games;
    emit wroteToJson(_json);
}

/**
 * @param QJsonObject& _json
 * @return void
 */
void Season::jsonRead(QJsonObject& _json)
{
    this->id = _json["id"].toInt();
    this->currentGameIndex = _json["currentIndex"].toInt();
    qDeleteAll(this->history);
    QJsonArray games = _json["games"].toArray();
    for(int i = 0; i < games.size(); i++)
    {
        QJsonObject game = games[i].toObject();
        this->history.append(new Game(game, this));
    }
    emit readFromJson(_json);
}

Season::~Season()
{
    if(!this->history.isEmpty())
        qDeleteAll(this->history);
}
