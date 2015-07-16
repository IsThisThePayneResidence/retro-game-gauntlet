import QtQuick 2.0
import QtMultimedia 5.0
import "fromLocalFile.js" as FileManager
import "ToolTipCreator.js" as ToolTipCreator

Rectangle
{
    id: rectTvSet
    objectName: "rectTvSet"
    width: 530
    height: 530
    color: parent.color

    MouseArea
    {
        id: maCopy
        anchors.fill: parent
        onClicked:
        {
            rggModel.copyToClipboard(rggModel.rggGame);
            ToolTipCreator.create("Copied to clipboard", rectTvSet).show()
        }
    }

    Video
    {
        id: vidNoise
        x: 40
        y: 48
        height: parent.height - 80
        width: parent.width - 80
        objectName: "vidNoise"
        source: FileManager.fromLocalFile("/video/noise.avi")
        autoPlay: true
        autoLoad: true
        onPlaybackStateChanged:
        {
            play();
        }
    }

    Image
    {
        id: imgTvSet
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent
        objectName: "imgTvSet"
        source: "qrc:/image/TvSet.gif"
    }

    VHSText
    {
        id: txtState
        x: 392
        y: 117
        color: "#37db16"
        text: "AV"
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.bold: true
        font.pointSize: 30
        font.family: "Courier"
    }

    VHSText
    {
        id: txtText
        x: 121
        y: 203
        width: 288
        height: 124
        text: rggModel.rggGame
        wrapMode: Text.WrapAtWordBoundaryOrAnywhere
        font.pointSize: 15
        font.family: "Tahoma"
        font.bold: true
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        onTextChanged:
        {
            ToolTipCreator.create("Press LMB on the screen to copy to clipboard", rectTvSet).show()
        }
    }
}

