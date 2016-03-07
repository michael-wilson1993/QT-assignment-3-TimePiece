#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
#include "canvas.h"



// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;
class timer: public QWidget
{
	Q_OBJECT
public:
timer();
~timer();

private:


QTClock	clock;
QPushButton *start_b, *pause_b, *reset_b;
Canvas *painter; 

};