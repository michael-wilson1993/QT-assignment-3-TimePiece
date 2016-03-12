 #include "stopWatch.h"

stopWatch::stopWatch(QWidget *parent) : QDialog(parent)
{

	painter = new Canvas(this);
	

	paused = true;
	// creates a QFont with size 16 and style is arial
	QFont font("Arial", 16); 
	//sets up the four buttons with there names and fonts
	mainMenu_b = new QPushButton("Main Menu");
	mainMenu_b->setFont(font);

	start_b = new QPushButton("start");
	start_b->setFont(font);

	setTime_b = new QPushButton("set time");
	setTime_b->setFont(font);

	pause_b = new QPushButton("pause");
	pause_b->setFont(font);

	// init time...
	hour = 0;
	minute = 0; 
	second = 0;

	//set up timer
	timer = new QTClock();



	// creates a grid for the widget
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(painter, 0,0,6,8);

	gridLayout->addWidget( setTime_b, 5,0,1,2);
	gridLayout->addWidget( start_b, 5,2,1,2);
	gridLayout->addWidget( pause_b, 5,4,1,2);
	gridLayout->addWidget( mainMenu_b, 5,6,1,2);

	gridLayout->addWidget( mainMenu_b, 5,5,1,1);
	setLayout(gridLayout);

	// resizing the window
	resize(1100,700); 

	//connections
	connect(mainMenu_b, SIGNAL(clicked()), this, SLOT(closeWin()));
	connect(start_b, SIGNAL(clicked()), this, SLOT(startTimer()));
	connect(setTime_b, SIGNAL(clicked()), this, SLOT(openGetTimeWin()));
	connect(pause_b, SIGNAL(clicked()), this, SLOT(stopTimer()));
	connect(timer, SIGNAL(tick(const int &)), this, SLOT(tick(const int &)));

	setupObjects();

}

stopWatch::~stopWatch()
{

}

void stopWatch::closeWin()
{
	const char temp = 's';
	emit backToMain(temp);
}

int stopWatch::stringToInt(std::string changer)
{
	int ret;
	for(int x = 0; x < changer.size();x++)
	{
		ret *= 10;
		ret += (changer.at(x)-48);
	}
	return ret;
}

QString stopWatch::IntToString(int changer)
{
	QString ret = "", tempS = "";
	int temp;
	while(changer != 0)
	{
		temp = changer%10;
		changer /= 10;
		tempS += (temp + 48);
	}
	for(int x = tempS.size()-1; x >= 0; x--)
		ret += tempS.at(x);
	return ret;
}

void stopWatch::getTimeSlot(const int &hh, const int &mm, const int &ss)
{
	hour = hh;
	minute =mm;
	second = ss;
	delete timeGetter;

}

void stopWatch::openGetTimeWin()
{
	timeGetter = new getTime(false, this);
	timeGetter->show();
	connect(timeGetter, SIGNAL(closeGetTimeWin()), this, SLOT(closeGetTime()));
	connect(timeGetter, SIGNAL(sendTime(const int &, const int &, const int &)), this, SLOT(getTimeSlot(const int &, const int &, const int &)));
}

void stopWatch::tick(const int &time)
{
	if(!paused)
	{
		if(second > 0)
		{
			second--;
		}
		else if(second == 0)
		{
			if(minute > 0)
			{
				minute--;
				second = 60;
			}
			else if(hour > 0)
			{
				hour--;
				minute = 59;
				second = 60;
			}
			else 
			{
				timesUp = true;
				paused = true;
			}
		}
	}
	painter->updateTime(hour, minute, second);
}

void stopWatch::closeGetTime()
{
	delete timeGetter;
}

void stopWatch::setupObjects()
{
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

void stopWatch::startTimer()
{
	paused = false;
}


void stopWatch::stopTimer()
{
	paused = true;
}