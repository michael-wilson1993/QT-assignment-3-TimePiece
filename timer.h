#pragma once

#include "GlobalHeader.h"
#include "QTClock.h"
#include "canvas.h"
#include <QDialog>


// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;


class timer: public QDialog
{
	Q_OBJECT
public:
timer(QWidget *parent = 0);
~timer();

private:


QTClock	clock;
QPushButton *start_b, *pause_b, *reset_b, *back_b;
Canvas *painter; 

};