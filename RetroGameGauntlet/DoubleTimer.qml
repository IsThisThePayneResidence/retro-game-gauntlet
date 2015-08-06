import QtQuick 2.0
Item
{
    id: itmRoot
    property int triggerTime: 0
    function load(_duration, _triggerTime, _increment)
    {
        timerCutsceneLength.interval = _duration;
        timerDelay.interval = _triggerTime;
        timerDelay.start();
        if(triggerTime == 0)
        {
            triggerTime = _triggerTime;
        }
        triggerTime += _increment;
        timerDelay.interval = triggerTime;
        timerCutsceneLength.start();
    }

    Timer
    {
        id: timerCutsceneLength
        interval: 0;
        running: false;
        repeat: false
        onTriggered:
        {
            timerDelay.stop();
            stop();
            triggerTime = 0;
        }
    }
    Timer
    {
        id: timerDelay
        interval: itmRoot.triggerTime;
        running: false;
        repeat: true;
        onTriggered:
        {
            rggModel.rollGame(rggModel.rggPlatform);
        }
    }
}

