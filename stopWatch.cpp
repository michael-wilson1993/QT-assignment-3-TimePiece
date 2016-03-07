#include "stopWatch.h"

stopWatch::stopWatch(QWidget *parent) : QDialog(parent)
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

}