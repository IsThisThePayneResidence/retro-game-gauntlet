import QtQuick 2.0

Text
{
    id: txtTrue
    objectName: "txtTrue"
    horizontalAlignment: Text.AlignHCenter
    verticalAlignment: Text.AlignVCenter
    wrapMode: Text.WrapAtWordBoundaryOrAnywhere
    Text
    {
        id: txtRed
        objectName: "txtRed"
        color: "red"
        text: txtTrue.text
        horizontalAlignment: parent.horizontalAlignment
        verticalAlignment: parent.verticalAlignment
        //anchors.fill: parent
        font: parent.font
        x: - 2
        y: - 2
        height: parent.height
        width: parent.width
        opacity: 0.4
        wrapMode: parent.wrapMode
    }
    Text
    {
        id: txtGreen
        objectName: "txtGreen"
        color: "green"
        text: txtTrue.text
        horizontalAlignment: parent.horizontalAlignment
        verticalAlignment: parent.verticalAlignment
        //anchors.fill: parent
        font: parent.font
        x: - 2
        y: 2
        height: parent.height
        width: parent.width
        opacity: 0.4
        wrapMode: parent.wrapMode
    }
    Text
    {
        id: txtBlue
        objectName: "txtBlue"
        color: "blue"
        text: txtTrue.text
        horizontalAlignment: parent.horizontalAlignment
        verticalAlignment: parent.verticalAlignment
        //anchors.fill: parent
        font: parent.font
        x: 2
        y: 2
        height: parent.height
        width: parent.width
        opacity: 0.4
        wrapMode: parent.wrapMode
    }
    Text
    {
        id: txtMain
        objectName: "txtMain"
        color: parent.color
        text: txtTrue.text
        //anchors.fill: parent
        font: parent.font
        wrapMode: parent.wrapMode
        horizontalAlignment: parent.horizontalAlignment
        verticalAlignment: parent.verticalAlignment
        height: parent.height
        width: parent.width
    }

}

