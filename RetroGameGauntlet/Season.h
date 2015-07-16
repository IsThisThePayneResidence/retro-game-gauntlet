/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#ifndef _SEASON_H
#define _SEASON_H

#include <QObject>
#include <QList>

class Game;
class QJsonObject;


class Season: public QObject
{
    Q_OBJECT
private:
    unsigned int id;
    QList<Game*> history;
    unsigned int currentGameIndex;

public: 

    /**
     * @param QJsonObject& _json
     */
    Season(QJsonObject& _json, QObject* _parent = nullptr);

    /**
     * @param _id
     * @param _history
     * @param _currentGameIndex
     */
    Season(unsigned int _id, QList<Game*> _history, unsigned int _currentGameIndex, QObject* _parent = nullptr);
	
	/**
	 * @param unsigned int _index
	 */
	Game* game( unsigned int _index);
	
	Game* currentGame();
	
	QList<Game*> games();

    ~Season();

public slots:
	
	/**
	 * @param QJsonObject& _json
	 */
    void jsonWrite(QJsonObject& _json);
	
	/**
	 * @param QJsonObject& _json
	 */
    void jsonRead(QJsonObject& _json);

    /**
     * @param Game* _game
     */
    void addGame(Game* _game);

signals:

    /**
     * @param QJsonObject& _json
     */
    void wroteToJson(QJsonObject& _json);

    /**
     * @param QJsonObject& _json
     */
    void readFromJson(QJsonObject& _json);

    /**
     * @param Game* _game
     */
    void gameAdded(Game* _game);

};

#endif //_SEASON_H
