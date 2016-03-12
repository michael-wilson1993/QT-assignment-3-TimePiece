/*
	- Michael Wilson
	- mainWin.h
	- Human Computer Interaction
	- prof: Wendy Osborn
	- march 11/16
*/

#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
#include "timer.h"
#include "clockW.h"
#include "stopWatch.h"

#include <string>
#include <iostream>

class CInsert;
class QLabel;
class QPushButton;
class QTableWidget;
class QListWidget;
class QListWidgetItem;
class QTableView;


class mainWin: public QMainWindow
{
Q_OBJECT
public:
	//constructor
	mainWin();
	~mainWin();
public slots:
	//recieves information from the QTClock every second.
	void getTick(const int &info);
	// information sent back from a widget telling the main it show itself or hide itself.
	void showMain(const char &name);
	// slots to open the windows corrisponding to there names.
	void openTimer();
	void openStopWatch();
	void openWorldClock();
	void openHomeworkHelper();

private:
	//buttons leading to thier specific features
	// timer: creates a timer widget
	// stopWatch: creates a stop watch widget
	// Clock: creates a world clock widget
	// homework: creates a homework widget
	// after widget is created main window will be hidden and after returning it will unhide
QPushButton *timer_b, *stopWatch_b, *Clock_b, *homework_b, *close_b;

timer *timer_w;
clockW *clock_w;
stopWatch *stopwatch_w;



};