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


class stopWatch : public QDialog
{
	Q_OBJECT
public:
	stopWatch(QWidget *parent = 0);
	~stopWatch();
private:
	QPushButton *mainMenu_b;
	Canvas *painter;

};