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
	timer = new QPushButton("timer");
	timer->setFont(font);

	stopWatch = new QPushButton("stop watch");
	stopWatch->setFont(font);

	Clock = new QPushButton("World Clock");
	Clock->setFont(font);

	homework = new QPushButton("homework helper");
	homework->setFont(font);

	// creates a grid for the window
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(timer, 0,0,1,2);
	gridLayout->addWidget(stopWatch, 1,1,1,2);
	gridLayout->addWidget(Clock,2,0,1,2);
	gridLayout->addWidget(homework,3,1,1,2);
	MainWindow->setLayout(gridLayout);


	QClock = new QTClock(this);
	connect(QClock, SIGNAL(tick(int)), this, SLOT(getTick(int)));


}

void mainWin::getTick(const int &info)
{
std::cerr << info << std::endl;
}