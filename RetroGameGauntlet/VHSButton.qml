import QtQuick 2.0

Component
{
    id: comVHS
    Item
    {
        width: imgVHS.width
        height: imgVHS.height
        Image
        {
            id: imgVHS
            objectName: "imgVHS"
            source: "qrc:/image/VHS.gif"
            property string name: modelData
            width: 320
            height: 60
            smooth: true
                Text
                {
                    id: txtVHS

                    objectName: "txtVHS"
                    anchors.fill: parent
                    text: modelData
                    anchors.leftMargin: 64
                    anchors.rightMargin: 58
                    wrapMode: Text.WordWrap

                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter

                    font.pointSize: 16
                    font.italic: true
                    font.family: "Tahoma"
                }
                MouseArea
                {
                    id: maVHS
                    width: parent.width
                    height: parent.height
                    objectName: "maVHS"
                    onClicked:
                    {
                        rggModel.rollGame(imgVHS.name);
                    }
                }
        }
    }
}

