#include "GlobalHeader.h"
#include "mainWin.h"

mainWin::mainWin()
{

	// creates a mainwindow widget to set the layout to
	QWidget *MainWindow = new QWidget;
    setCentralWidget(MainWindow); 

	// creates a QFont with size 16 and style is arial
	QFont font("Arial", 16); 
	//sets up the four buttons with there names and fonts
	timer_b = new QPushButton("stop watch");
	timer_b->setFont(font);
	timer_b->setMinimumHeight(145);

	stopWatch_b = new QPushButton("timer");
	stopWatch_b->setFont(font);
	stopWatch_b->setMinimumHeight(145);

	Clock_b = new QPushButton("World Clock");
	Clock_b->setFont(font);
	Clock_b->setMinimumHeight(145);

	homework_b = new QPushButton("homework helper");
	homework_b->setFont(font);
	homework_b->setMinimumHeight(145);

	close_b = new QPushButton("close");
	close_b->setFont(font);
	close_b->setMinimumHeight(145);

	// creates a grid for the window
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(timer_b, 0,0,2,2);
	gridLayout->addWidget(stopWatch_b, 2,0,2,2);
	gridLayout->addWidget(Clock_b,4,0,2,2);
	gridLayout->addWidget(close_b,6,0,2,2);
	//gridLayout->addWidget(close_b,8,0,2,2);
	MainWindow->setLayout(gridLayout);


	// connections
	connect(timer_b, SIGNAL(clicked()), this, SLOT(openTimer()));
	connect(Clock_b, SIGNAL(clicked()), this, SLOT(openWorldClock()));
	connect(stopWatch_b, SIGNAL(clicked()), this, SLOT(openStopWatch()));
	connect(close_b, SIGNAL(clicked()), this, SLOT(close()));

	

}
mainWin::~mainWin()
{
	std::cerr << "mainWin.h : deleted timer"<< std::endl;
	delete timer_b;
	delete stopWatch_b;
	delete Clock_b;
	delete homework_b;
	delete close_b;
	std::cerr << "mainWin.h : deleted timer - success " << std::endl;
}

void mainWin::getTick(const int &info)
{
std::cerr << info << std::endl;

}

void mainWin::showMain(const char &name)
{
	if(name == 't' && timer_w != NULL)
		delete timer_w;
	else if(name == 'c' && clock_w != NULL)
		delete clock_w;
	else if(name == 's' && stopwatch_w != NULL)
		delete stopwatch_w;

	//shows the main window again
	show();
}

void mainWin::openTimer()
{
	timer_w = new timer(this);
	timer_w->show();
	connect(timer_w, SIGNAL( backToMain(const char &) ), this, SLOT( showMain(const char &) ));
	hide();
}
void mainWin::openStopWatch()
{
	stopwatch_w = new stopWatch(this);
	stopwatch_w->show();
	connect(stopwatch_w, SIGNAL( backToMain(const char &) ), this, SLOT( showMain(const char &) ));
	hide();
}
void mainWin::openWorldClock()
{
	clock_w = new clockW(this);
	clock_w->show();
	connect(clock_w, SIGNAL( backToMain(const char &) ), this, SLOT( showMain(const char &) ));
	hide();
}
void mainWin::openHomeworkHelper()
{

}