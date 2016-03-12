/*
	- Michael Wilson
	- stopWatch.h
	- Human Computer Interaction
	- prof: Wendy Osborn
	- march 11/16
*/


#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
#include "canvas.h"
#include <QDialog>
#include "getTime.h"

// QT classes needed for GUI
class QTimer;
class Canvas;
class QLabel;
class QPushButton;
class QGridgeLayout;
class QComboBox;
class QLineEdit;
class QString;

class stopWatch : public QDialog
{
	Q_OBJECT
public:
	stopWatch(QWidget *parent = 0);
	~stopWatch();
	void setupObjects();

signals:
	void backToMain(const char &name);


public slots:
	void closeWin();
	void getTimeSlot(const int &hh, const int &mm, const int &ss);
	void openGetTimeWin();
	void tick(const int &time);
	void closeGetTime();
	void startTimer();
	void stopTimer();


private:
	int stringToInt(std::string changer);
	QString IntToString(int changer);



	QTClock *timer;
	QPushButton *mainMenu_b, *start_b, *setTime_b, *pause_b;
	Canvas *painter;
	getTime *timeGetter;

	int hour, minute, second;
	bool paused, timesUp;

};