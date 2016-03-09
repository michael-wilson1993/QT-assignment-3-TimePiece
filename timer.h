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
void setupObjects();
signals:
	void backToMain(const char &name);

public slots:
	void animationTick(const int &info);
	void timerReturn(const int &info);

private slots:
	void closeWin();
	void start_s();
	void pause_s();
	void reset_s();


private:
	void updateTime();

QTClock	*clockTick, *animTick;
QPushButton *start_b, *pause_b, *reset_b, *back_b;
Canvas *painter; 
int hour, minutes, seconds;
bool paused;

};