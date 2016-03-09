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
	gridLayout->addWidget(painter, 0,0,6,8);
	gridLayout->addWidget(start_b, 5,0,1,2);
	gridLayout->addWidget(pause_b, 5,2,1,2);
	gridLayout->addWidget(reset_b, 5,4,1,2);
	gridLayout->addWidget( back_b, 5,6,1,2);
	setLayout(gridLayout);

	// resizing the window
	resize(1100,700); 

	// connections
	connect(back_b, SIGNAL(clicked()), this , SLOT(closeWin()));
	clockTick = new QTClock(false, 1000, this);
	connect(clockTick, SIGNAL(tick(const int &)), this, SLOT(timerReturn(const int &)));
	connect(start_b, SIGNAL(clicked()), this, SLOT(start_s()));
	connect(pause_b, SIGNAL(clicked()), this, SLOT(pause_s()));
	connect(reset_b, SIGNAL(clicked()), this, SLOT(reset_s()));

	QTObject secondsGlass(0,0,0,false,false);
	secondsGlass.nextCoor(800,280);
	secondsGlass.nextCoor(800,600);
	secondsGlass.nextCoor(900,600);
	secondsGlass.nextCoor(900,280);
	painter->insertObject(secondsGlass);
	QTObject secondTitle(0,0,0,false,false,"seconds", 820, 615);
	painter->insertObject(secondTitle);


	QTObject MinutesGlass(0,0,0,false,false);
	MinutesGlass.nextCoor(550,280);
	MinutesGlass.nextCoor(550,600);
	MinutesGlass.nextCoor(750,600);
	MinutesGlass.nextCoor(750,280);
	painter->insertObject(MinutesGlass);
	QTObject minutesTitle(0,0,0,false,false,"minutes", 620, 615);
	painter->insertObject(minutesTitle);

	QTObject hourGlass(0,0,0,false,false);
	hourGlass.nextCoor(200,280);
	hourGlass.nextCoor(200,600);
	hourGlass.nextCoor(500,600);
	hourGlass.nextCoor(500,280);
	painter->insertObject(hourGlass);
	QTObject hoursTitle(0,0,0,false,false,"hours", 330, 615);
	painter->insertObject(hoursTitle);


	std::vector< QTObject > lines;
	for(int x = 0; x < 6; x++)
	{
		lines.push_back(QTObject(0,0,0,false,false));
		lines[lines.size()-1].nextCoor(810,550 - (x*50));
		lines[lines.size()-1].nextCoor(830,550 - (x*50));

		lines.push_back(QTObject(0,0,0,false,false));
		lines[lines.size()-1].nextCoor(560,550 - (x*50));
		lines[lines.size()-1].nextCoor(610,550 - (x*50));

		lines.push_back(QTObject(0,0,0,false,false));
		lines[lines.size()-1].nextCoor(210,550 - (x*50));
		lines[lines.size()-1].nextCoor(310,550 - (x*50));

		lines.push_back(QTObject(0,0,0,false,false));
		lines[lines.size()-1].nextCoor(210,575 - (x*50));
		lines[lines.size()-1].nextCoor(290,575 - (x*50));
	}

	for(int x = 0; x < lines.size();x++)
	{
		painter->insertObject(lines[x]);
	}

	std::vector< QTObject > measure;

	measure.push_back(QTObject(0,0,0,false,false,"10",840, 555));
	measure.push_back(QTObject(0,0,0,false,false,"20",840, 505));
	measure.push_back(QTObject(0,0,0,false,false,"30",840, 455));
	measure.push_back(QTObject(0,0,0,false,false,"40",840, 405));
	measure.push_back(QTObject(0,0,0,false,false,"50",840, 355));
	measure.push_back(QTObject(0,0,0,false,false,"60",840, 305));

	measure.push_back(QTObject(0,0,0,false,false,"10",620, 555));
	measure.push_back(QTObject(0,0,0,false,false,"20",620, 505));
	measure.push_back(QTObject(0,0,0,false,false,"30",620, 455));
	measure.push_back(QTObject(0,0,0,false,false,"40",620, 405));
	measure.push_back(QTObject(0,0,0,false,false,"50",620, 355));
	measure.push_back(QTObject(0,0,0,false,false,"60",620, 305));

	measure.push_back(QTObject(0,0,0,false,false,"2",320, 555));
	measure.push_back(QTObject(0,0,0,false,false,"4",320, 505));
	measure.push_back(QTObject(0,0,0,false,false,"6",320, 455));
	measure.push_back(QTObject(0,0,0,false,false,"8",320, 405));
	measure.push_back(QTObject(0,0,0,false,false,"10",320, 355));
	measure.push_back(QTObject(0,0,0,false,false,"12",320, 305));

	measure.push_back(QTObject(0,0,0,false,false,"1",300, 580));
	measure.push_back(QTObject(0,0,0,false,false,"3",300, 530));
	measure.push_back(QTObject(0,0,0,false,false,"5",300, 480));
	measure.push_back(QTObject(0,0,0,false,false,"7",300, 430));
	measure.push_back(QTObject(0,0,0,false,false,"9",300, 380));
	measure.push_back(QTObject(0,0,0,false,false,"11",300, 330));

	for(int x = 0; x < measure.size();x++)
	{
		painter->insertObject(measure[x]);
	}

}

timer::~timer()
{
	std::cerr << "timer.h : deleted lots"<< std::endl;
	//delete clockTick;
	//delete animTick;
	delete start_b;
	delete pause_b;
	delete reset_b;
	delete back_b;
	//delete painter;
	std::cerr << "timer.h : deleted lots - success "<< std::endl;
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
	painter->updateTime(hour, minutes, seconds);
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