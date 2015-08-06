function Timer(_parent)
{
    return Qt.createQmlObject("import QtQuick 2.0; Timer {}", _parent);
}

function delay(_delayTime, _parent)
{
    var timer = new Timer(_parent);
    timer.interval = _delayTime;
    timer.repeat = false;
    timer.start();
}

function delayAndExecute(_delayTime, _parent, _cb)
{
    var timer = new Timer(_parent);
    timer.interval = _delayTime;
    timer.repeat = false;
    timer.triggered.connect(_cb);
    timer.start();
}
/*
function doubleTimer(_duration, _triggerTime, _triggerAction, _endAction, _parent)
{

    var innerTimer = new Timer(_parent);
    innerTimer.interval = _triggerTime;
    innerTimer.repeat = true;
    innerTimer.triggered.connect(_triggerAction);

    innerTimer.triggered.connect(function() { innerTimer.interval += 100; } );

    var durableTimer = new Timer(_parent);
    durableTimer.interval = _duration;
    durableTimer.repeat = false;
    durableTimer.triggered.connect(function() { innerTimer.repeat = false; } );
    durableTimer.triggered.connect(_endAction);

    innerTimer.start();
    durableTimer.start();
}
*/
