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
	getTime(bool GetCTime, QDialog *parent = 0);
	~getTime();
signals:
	void closeGetTimeWin();
	void sendClass(const QString &name,const int &h, const int &m, const int &s);
	void sendTime(const int &h, const int &m, const int &s);

public slots:
	void sendClassSlot();
	void sendTimeSlot();
	void closeGetTime();
	void tripHourFlag(const QString & text);
	void tripMinuteFlag(const QString & text);
	void tripSecondFlag(const QString & text);


private:
	int stringToInt(QString changer);
	QString IntToString(int changer);
	bool isClass;

	QLineEdit *classType;
	QLabel *class_l, *hour_l, *minute_l, *second_l;
	QComboBox *hour_cb, *minute_cb, *second_cb;
	QPushButton *mainMenu_b, *setTime_b;
	bool hour_flag, minute_flag, second_flag;


};