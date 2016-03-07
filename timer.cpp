#include "timer.h"

timer::timer(QWidget *parent) : QDialog(parent)
{
	hour = 0;
	minutes = 0;
	seconds = 0;
	paused = true;
	painter = new Canvas(this);

	// creates a QFont with size 16 and style is arial
	QFont font("Arial", 16); 
	//sets up the four buttons with there names and fonts
	start_b = new QPushButton("start");
	start_b->setFont(font);

	pause_b = new QPushButton("pause");
	pause_b->setFont(font);

	reset_b = new QPushButton("reset");
	reset_b->setFont(font);

	back_b = new QPushButton("main Menu");
	back_b->setFont(font);

	// creates a grid for the widget
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(painter, 0,0,6,6);
	gridLayout->addWidget(start_b, 5,0,1,2);
	gridLayout->addWidget(pause_b, 5,2,1,2);
	gridLayout->addWidget(reset_b, 5,4,1,2);
	gridLayout->addWidget( back_b, 5,6,1,2);
	setLayout(gridLayout);

	// resizing the window
	resize(1100,700); 

	// connections
	connect(back_b, SIGNAL(clicked()), this , SLOT(closeWin()));
	clock = new QTClock(false, 1000, this);
	connect(clock, SIGNAL(tick(const int &)), this, SLOT(timerReturn(const int &)));
	connect(start_b, SIGNAL(clicked()), this, SLOT(start_s()));
	connect(pause_b, SIGNAL(clicked()), this, SLOT(pause_s()));
	connect(reset_b, SIGNAL(clicked()), this, SLOT(reset_s()));
}

timer::~timer()
{

}


void timer::closeWin()
{
	const char temp = 't';
	emit backToMain(temp);
}

void timer::animationTick(const int &info)
{
	//update canvas
	//testing output
	std::cerr << info << std::endl;
}

void timer::timerReturn(const int &info)
{
	if(!paused)
		seconds++;
	updateTime();
	std::cerr << hour << ":" << minutes << ":" << seconds << "\n\n";
}


void timer::updateTime()
{
	if(seconds >= 60)
	{
		minutes++;
		seconds = 0;
	}
	if(minutes >= 60)
	{
		hour++;
		minutes = 0;
	}
}
void timer::start_s()
{
	paused = false;
}

void timer::pause_s()
{
	paused = true;
}

void timer::reset_s()
{
	paused = true;
	hour = 0; 
	minutes = 0;
	seconds = 0;
}