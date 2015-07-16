/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */


#ifndef _MODEL_H
#define _MODEL_H
#include <QMap>
#include <QObject>
#include <QStringList>

class Model: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList rggPlatforms READ platforms WRITE setPlatforms NOTIFY platformsSet)
    Q_PROPERTY(QString rggGame READ game WRITE setGame NOTIFY gameSet)

private:
    QStringList platformsList;
    QString currentGame;
    static QMap<QString, QString> platformAssignment;

public:

    Model(QStringList _platform, QObject* _parent = nullptr);
	
    QStringList platforms();

    QString game();

public slots:

    /**
     * @param QStringList
     */
    void setPlatforms(QStringList _platforms);

    void setAssignment();

    /**
     * @param QString _platform
     */
    Q_INVOKABLE void rollGame(QString _platform);

    Q_INVOKABLE void setGame(QString _game);

    Q_INVOKABLE void copyToClipboard(QString _text);

signals:

    /**
     * @param QStringList
     */
    Q_INVOKABLE void platformsSet(QStringList& _platforms);

    void assignmentSet();

    /**
     * @param QString _platform
     */
    void gameRolled(QString& _game);

    void gameSet(QString& _game);
};

#endif //_MODEL_H
