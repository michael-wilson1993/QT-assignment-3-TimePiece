#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
#include "canvas.h"
#include <QDialog>

#include <ctime>
#include <iostream>

// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;


class clockW : public QDialog
{
	Q_OBJECT
public:
	clockW(QWidget *parent = 0);
	~clockW();
	void updateTime();
	void setupObjects();

signals:
	void backToMain(const char &name);

public slots:
	void animationTick(const int &info);
	void timerReturn(const int &info);


private slots:
	void closeWin();


private:
	QPushButton *mainMenu_b;
	QTClock *updateTick;
	Canvas *painter;
	int hour, minutes, seconds;
	time_t ClockTime;

};