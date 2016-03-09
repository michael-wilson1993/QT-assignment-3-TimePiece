#include "clockW.h"

clockW::clockW(QWidget *parent) : QDialog(parent)
{

	
	painter = new Canvas(this);

	// creates a QFont with size 16 and style is arial
	QFont font("Arial", 16); 
	//sets up the four buttons with there names and fonts
	mainMenu_b = new QPushButton("start");
	mainMenu_b->setFont(font);


	// creates a grid for the widget
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(painter, 0,0,6,6);

	gridLayout->addWidget( mainMenu_b, 5,1,1,4);
	setLayout(gridLayout);

	// resizing the window
	resize(1100,700); 

	updateTick = new QTClock(false, 1000, this);
	connect(updateTick, SIGNAL(tick(const int &)), this, SLOT(timerReturn(const int &)));
}
clockW::~clockW()
{
	std::cerr << "ClockW.h : deleted painter"<< std::endl;
	delete mainMenu_b;
	delete updateTick;
	delete painter;
	std::cerr << "clockW.h : deleted painter - success "<< std::endl;
}


// got this function from "http://code.runnable.com/U2DKRsrlaUEEYt4f/get-the-current-local-time-with-ctime-for-c%2B%2B"
// to get the machines current time
void clockW::updateTime()
{
	struct tm *localTime;
	time( &ClockTime );                   // Get the current time
  	localTime = localtime( &ClockTime );  // Convert the current time to the local time
  	hour = localTime->tm_hour;
  	if(hour > 12)
  		hour -= 12;
  	
  	minutes = localTime->tm_min;
  	seconds = localTime->tm_sec;

}

void clockW::timerReturn(const int &info)
{
	updateTime();
	std::cerr << hour << ":" << minutes << ":" << seconds << "\n\n";

}

void clockW::animationTick(const int &info)
{

}

void clockW::closeWin()
{

}