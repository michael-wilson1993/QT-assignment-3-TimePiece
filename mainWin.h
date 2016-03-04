#pragma once
#include "GlobalHeader.h"
#include "QTClock.h"
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
	void getTick(const int &info);

private:
	//buttons leading to thier specific features
	// timer: creates a timer widget
	// stopWatch: creates a stop watch widget
	// Clock: creates a world clock widget
	// homework: creates a homework widget
	// after widget is created main window will be hidden and after returning it will unhide
QPushButton *timer, *stopWatch, *Clock, *homework;


QTClock *QClock;


};