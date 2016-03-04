#include "QTClock.h"

QTClock::QTClock(QWidget *parent): QWidget(parent)
{
	timer = new QTimer();
	connect(timer, SIGNAL(timeout()), this, SLOT(ClockLoop()));
	timer->start(1000);
	count = 1;

}

void QTClock::ClockLoop()
{
	// counts and sets timer to one second intervals
	timer->start(1000);
	count++;
	emit tick(count);
}

void QTClock::reset()
{
	count = 0;
}
