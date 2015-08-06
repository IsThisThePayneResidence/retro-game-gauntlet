import QtQuick 2.4
import QtQuick.Controls 1.3

Rectangle
{
    id: rectMain
    objectName: "rectMain"
    width: 1080
    height: 720
    color: "#0d070f"
    radius: 5
    border.color: "#67C8FF"
    border.width: 2
    visible: true

    TvSet
    {
        id: tvSetMain
        objectName: "tvSetMain"
        x: 54
        y: 110
    }

    Image
    {
        id: imgSign
        x: 698
        y: 24
        width: 300
        height: 300
        objectName: "imgSign"
        source: "qrc:/image/Sign.gif"
    }

    ListView
    {
        id: lvVHS
        objectName: "lvVHS"
        spacing: 20
        x: 674
        y: 394
        width: 324
        height: 246
        delegate:
            VHSButton
            {
                id: vhsButtonDelegate
            }
        model: rggModel.rggPlatforms
    }

    Image
    {
        id: imgAuthors
        x: 54
        y: 664
        width: 530
        height: 48
        source: "qrc:/image/Authors.gif"
    }

}
