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
    QVector<QString> gms;
    QFile games(platformAssignment.value(_platform));
    if(!games.open(QIODevice::ReadOnly))
        qDebug() << "Error opening platform file!";
    while(!games.atEnd())
        gms.append(QString::fromStdString(games.readLine().toStdString()));
    srand(time(0));
    //int end = qrand() % 20 + 50;
    //for(int i = 0; i < end; i++)
    //{
        QString gameName = gms[rand() % gms.size()];
        //currentSeason->addGame(new Game(gameName, _platform));
        emit gameRolled(gameName);
        setGame(gameName);
    //}
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
    platformAssignment["Master System"] = "systems/list_sms.dat";
    platformAssignment["GameGear"] = "systems/list_gg.dat";
    platformAssignment["MegaDrive/Genesis"] = "systems/list_smd.dat";
    platformAssignment["Super Famicom/SNES"] = "systems/list_snes.dat";
    platformAssignment["NeoGeo Pocket"] = "systems/list_ngp.dat";
    platformAssignment["TurboGrafx"] = "systems/list_tg16.dat";
    platformAssignment["WonderSwan"] = "systems/list_ws.dat";
    platformAssignment["NeoGeo"] = "systems/list_ngo.dat";
    platformAssignment["GameBoy Advance"] = "systems/list_gba.dat";
    platformAssignment["DOS"] = "systems/list_dos.dat";
    platformAssignment["ZX Spectrum"] = "systems/list_zx.dat";
    platformAssignment["MSX"] = "systems/list_msx.dat";
    platformAssignment["MSX2"] = "systems/list_msx2.dat";
    platformAssignment["Commodore 64"] = "systems/list_c64.dat";
    platformAssignment["Commodore Amiga"] = "systems/list_amg.dat";
    platformAssignment["Sega Saturn"] = "systems/list_ss.dat";
    platformAssignment["PlayStation"] = "systems/list_psx.dat";
    platformAssignment["Nintendo 64"] = "systems/list_n64.dat";
    platformAssignment["Dreamcast"] = "systems/list_dc.dat";
    platformAssignment["PlayStation 2"] = "systems/list_ps2.dat";
    platformAssignment["Gamecube"] = "systems/list_gc.dat";
    platformAssignment["PSP"] = "systems/list_psp.dat";
    platformAssignment["Nintendo DS"] = "systems/list_ds.dat";
    platformAssignment["Wii"] = "systems/list_wii.dat";
    platformsList << "Famicom/NES" << "GameBoy/GameBoy Color" << "Master System" << "GameGear" << "MegaDrive/Genesis"
                  << "Super Famicom/SNES" << "NeoGeo Pocket" << "TurboGrafx" << "WonderSwan" << "NeoGeo" << "GameBoy Advance"
                  << "DOS" << "ZX Spectrum" << "MSX" << "MSX2" << "Commodore 64" << "Dreamcast" << "PlayStation 2" << "Gamecube"
                  << "PSP" << "Nintendo DS" << "Wii";
    emit assignmentSet();
}

QMap<QString, QString> Model::platformAssignment;
