/*
	- Michael Wilson
	- getTime.h
	- Human Computer Interaction
	- prof: Wendy Osborn
	- march 11/16
*/




#pragma once

#include <iostream>
#include <cmath>
#include <vector>

	//QT
#include <QLineEdit>
#include <QDialog>
#include <QtGui>
#include <QMainWindow>
#include <QList>
#include <QTimer>

// QT classes needed for GUI
class QLabel;
class QPushButton;
class QGridgeLayout;
class QComboBox;
class QLineEdit;
class QString;

class getTime: public QDialog
{
	Q_OBJECT
public:
	// constructor
	getTime(bool GetCTime, QDialog *parent = 0);
	// destructor
	~getTime();
signals:
	// closeGetTimeWin is a slot to close the window and tell the main window to destroy this one
	void closeGetTimeWin();
	// sendClass sends a class name, hour, minutes, and seconds
	void sendClass(const QString &name,const int &h, const int &m, const int &s);
	// sendTime sends ths the time in hours, minutes, and seconds
	void sendTime(const int &h, const int &m, const int &s);

public slots:
	// sendclass slot is to emit the sendClass SIGNAL
	void sendClassSlot();
	// sendTimeslot is the slot to emit sendTime SIGNAL
	void sendTimeSlot();
	// clesGetTime will close and delete the getTime window
	void closeGetTime();
	// tripHourFlag is a slot the determines if an hour was selected
	void tripHourFlag(const QString & text);
	// tripMinuteFlag is a slot that determines if a minute time was selected
	void tripMinuteFlag(const QString & text);
	// tripSecondFlag is a slot that determines if a second time was selected
	void tripSecondFlag(const QString & text);


private:
	// helper function to convert string to int
	int stringToInt(QString changer);
	// intToString is a helper function to convert int to string
	QString IntToString(int changer);
	// isClass determines if this class will include a class name to insert
	bool isClass;
	// classType is a QLineEdit that you can type your class name into
	QLineEdit *classType;
	// all these labels are self explanitory, the names is the name of the label and  _l indicates its a label
	QLabel *class_l, *hour_l, *minute_l, *second_l;
	// QComboBox is to get the time from there coorisponding name
	QComboBox *hour_cb, *minute_cb, *second_cb;
	// QPushButtons to return to the main menu or to set the time
	QPushButton *mainMenu_b, *setTime_b;
	// these bools determine if you send information back to the main window, if false send a 0 in its place.
	bool hour_flag, minute_flag, second_flag;


};