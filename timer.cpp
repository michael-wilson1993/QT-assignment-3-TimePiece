#include "timer.h"

timer::timer()
{

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

	// creates a grid for the widget
	QGridLayout *gridLayout = new QGridLayout;
	gridLayout->addWidget(painter, 0,0,4,4);
	gridLayout->addWidget(start_b, 5,0,1,2);
	gridLayout->addWidget(pause_b, 5,2,1,2);
	gridLayout->addWidget(reset_b, 5,4,1,2);
	setLayout(gridLayout);

	// resizing the window
	resize(1100,700); 

}

timer::~timer()
{

}

