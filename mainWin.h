#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
#include "timer.h"
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

public slots:
	//recieves information from the QTClock every second.
	void getTick(const int &info);
	// information sent back from a widget telling the main it show itself or hide itself.
	void showMain(const bool &show);

private:
	//buttons leading to thier specific features
	// timer: creates a timer widget
	// stopWatch: creates a stop watch widget
	// Clock: creates a world clock widget
	// homework: creates a homework widget
	// after widget is created main window will be hidden and after returning it will unhide
QPushButton *timer_b, *stopWatch_b, *Clock_b, *homework_b;

timer *timer_w;



};