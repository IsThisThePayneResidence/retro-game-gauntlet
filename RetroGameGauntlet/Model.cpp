/**
 * Project RetroGameGauntlet
 * @author QCoder
 * @version 0.1 Dev
 */

#include <QFile>
#include <QVector>
#include <QDebug>
#include <QClipboard>
#include <cstdio>
#include <ctime>
#include "RetroGameGauntlet.h"
#include "Model.h"



/**
 * Model implementation
 */

Model::Model(QStringList _platform, QObject* _parent):
    QObject(_parent)
{
    this->setAssignment();

    srand(time(nullptr));
    //for(QString s : platformAssignment.keys())
    //    platformsList.push_back(s);

    //this->platformsList = _platform;
}


/**
 * @return Season*
 */
/*
Season* Model::season()
{
    return this->currentSeason;
}
*/

/**
 * @param Season* _season
 * @return void
 */
/*
void Model::setSeason(Season* _season)
{
    if(this->currentSeason)
        delete this->currentSeason;
    this->currentSeason = nullptr;
    if(_season)
        this->currentSeason = _season;
    emit seasonSet(this->currentSeason);
}
*/

/**
 * @param QString _platform
 * @return void
 */
void Model::rollGame(QString _platform)
{
    this->setPlatform(_platform);
    QVector<QString> gms;
    QFile games(platformAssignment.value(_platform));
    if(!games.open(QIODevice::ReadOnly))
        qDebug() << "Error opening platform file!";
    while(!games.atEnd())
        gms.append(QString::fromStdString(games.readLine().toStdString()));
    QString gameName = gms[rand() % gms.size()];
    emit gameRolled(gameName);
    setGame(gameName);
}

void Model::setGame(QString _game)
{
    this->currentGame = _game;
    emit gameSet(this->currentGame);
}

void Model::copyToClipboard(QString _text)
{
    RetroGameGauntlet::app()->clipboard()->clear();
    RetroGameGauntlet::app()->clipboard()->setText(_text);
}

void Model::setPlatform(QString _platform)
{
    this->currentPlatform = _platform;
    emit platformChanged(this->currentPlatform);
}

/*
void Model::setHistory(QTableModel* _history)
{
    seasonHistory = _history;
    emit historyChanged(seasonHistory);
}

void Model::setSeasonHistory()
{
    //for(Game* g : season()->games())

}

void Model::setChallengeHistory()
{

}
*/

/**
 * @return QStringList
 */
/*
QTableModel* Model::history()
{
    return seasonHistory;
}
*/
/**
 * @return QStringList
 */
QStringList Model::platforms()
{
    return platformsList;
}

QString Model::game()
{
    return this->currentGame;
}

QString Model::platform()
{
    return this->currentPlatform;
}


/**
 * @param QStringList
 * @return void
 */
void Model::setPlatforms(QStringList _platforms)
{
    platformsList = _platforms;
    emit platformsSet(platformsList);
}
/*
void Model::save()
{
    if(!this->saveState())
        qWarning("Saving proccess has failed");
    emit saved();
}

void Model::load()
{
    if(!this->loadState())
        qWarning("Loading proccess has failed");
    emit loaded();
}
*/
/**
 * @return void
 */
/*
bool Model::saveState()
{
    QFile saveFile("challenge.json");
    QJsonArray seasons;
    QJsonObject season;
    if(saveFile.exists())
    {
        if (!saveFile.open(QIODevice::ReadOnly))
        {
            qWarning("Couldn't open save file.");
            return false;
        }
        QByteArray data = saveFile.readAll();
        seasons = QJsonDocument::fromJson(data).array();
        saveFile.close();
    }
    this->currentSeason->jsonWrite(season);
    seasons.append(season);
    QJsonDocument saveDoc(seasons);
    if (!saveFile.open(QIODevice::Truncate))
    {
        qWarning("Couldn't open save file.");
        return false;
    }
    saveFile.write(saveDoc.toJson());
    return true;
}
*/
/**
 * @return bool
 */
/*
bool Model::loadState()
{
    QFile saveFile("challenge.json");

    if(saveFile.exists())
    {
        if (!saveFile.open(QIODevice::ReadOnly))
        {
            qWarning("Couldn't open save file.");
            return false;
        }
        QByteArray data = saveFile.readAll();
        QJsonArray seasons = QJsonDocument::fromJson(data).array();
        if(!seasons.isEmpty())
        {
            QJsonObject season = seasons.at(seasons.size() - 1).toObject();
            currentSeason = new Season(season, this);
        }
        else
            currentSeason = new Season(1, QList<Game*>(), 0, this);
    }
    else
        currentSeason = new Season(1, QList<Game*>(), 0, this);
    return true;
}

void Model::jsonWrite(QJsonObject& _json)
{
    this->currentSeason->jsonWrite(_json);
    emit wroteToJson(_json);
}

void Model::jsonRead(QJsonObject& _json)
{
    this->currentSeason->jsonRead(_json);
    emit readFromJson(_json);
}
*/
void Model::setAssignment()
{
    platformAssignment["Famicom/NES"] = "systems/list_nes.dat";
    platformAssignment["GameBoy/GameBoy Color"] = "systems/list_gb.dat";
    platformAssignment["Master System/GameGear"] = "systems/list_sms_gg.dat";
    platformAssignment["MegaDrive/Genesis"] = "systems/list_smd.dat";
    platformAssignment["Super Famicom/SNES"] = "systems/list_snes.dat";
    platformAssignment["TurboGrafx"] = "systems/list_tg16.dat";
    platformAssignment["GameBoy Advance"] = "systems/list_gba.dat";
    platformAssignment["DOS"] = "systems/list_dos.dat";
    platformAssignment["MSX/MSX2"] = "systems/list_msx_msx2.dat";
    platformAssignment["C64/Amiga"] = "systems/list_c64_amiga.dat";
    platformAssignment["PS/N64"] = "systems/list_psx_n64.dat";

    platformsList << "Famicom/NES" << "GameBoy/GameBoy Color" << "Master System/GameGear" << "MegaDrive/Genesis"
                  << "Super Famicom/SNES" << "TurboGrafx" << "GameBoy Advance" << "DOS" << "MSX/MSX2"
                  << "C64/Amiga" << "PS/N64";

    emit assignmentSet();
}

QMap<QString, QString> Model::platformAssignment;
