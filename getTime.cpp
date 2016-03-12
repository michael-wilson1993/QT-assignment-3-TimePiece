#include "getTime.h"

getTime::getTime(bool GetCTime, QDialog *parent) : QDialog(parent)
{
	// setting up pop up windows properties
	setWindowFlags(Qt::FramelessWindowHint | Qt::Popup);
	setStyleSheet("background-color: grey;");
	// is class is a value that determines weather we are grabbing a class name or not
	isClass = GetCTime;
	//resizing the window
	resize(400,200); 
	// initializing default time to 0
	hour_flag = false; 
	minute_flag = false;
	second_flag = false;
	// creates a QFont with size 16 and style is arial
	QFont font("Arial", 16); 
	//sets up the four buttons with there names and fonts
	mainMenu_b = new QPushButton("Main Menu");
	setTime_b = new QPushButton("set time");
	hour_l = new QLabel("hour:");
	minute_l = new QLabel("minute:");
	second_l = new QLabel("second:");
	class_l = new QLabel("class:");
	setTime_b->setFont(font);
	class_l->setFont(font);
	hour_l->setFont(font);
	minute_l->setFont(font);
	second_l->setFont(font);
	mainMenu_b->setFont(font);

	// creating the new Qline edit to get the class name
	classType = new QLineEdit();

	//sets up the combo boxes
	hour_cb = new QComboBox();
	for(int x = 0; x < 13; x++)
		hour_cb->addItem(IntToString(x));
	

	minute_cb = new QComboBox();
	second_cb = new QComboBox();
	for(int x = 0; x < 60;x++)
	{
		minute_cb->addItem(IntToString(x));
		second_cb->addItem(IntToString(x));
	}


	// creates a grid for the widget
	// if true creates a window with QLineedit 
	// else only time no Qline edit
	if(GetCTime)
	{
		QGridLayout *gridLayout = new QGridLayout;
		gridLayout->addWidget(classType, 0,1, 1,2);
		gridLayout->addWidget( class_l,  0,0,1,1);
		gridLayout->addWidget( hour_l,   1,0,1,1);
		gridLayout->addWidget( minute_l, 2,0,1,1);
		gridLayout->addWidget( second_l, 3,0,1,1);
		gridLayout->addWidget( hour_cb, 1,1,1,2);
		gridLayout->addWidget( minute_cb, 2,1,1,2);
		gridLayout->addWidget( second_cb, 3,1,1,2);
		gridLayout->addWidget( setTime_b, 4,0,1,2);
		gridLayout->addWidget( mainMenu_b, 4,2,1,1);
		setLayout(gridLayout);
		connect(setTime_b, SIGNAL(clicked()), this, SLOT(sendClassSlot()));
	}
	else
	{
		QGridLayout *gridLayout = new QGridLayout;
		gridLayout->addWidget( hour_l,   0,0,1,1);
		gridLayout->addWidget( minute_l, 1,0,1,1);
		gridLayout->addWidget( second_l, 2,0,1,1);
		gridLayout->addWidget( hour_cb, 0,1,1,2);
		gridLayout->addWidget( minute_cb, 1,1,1,2);
		gridLayout->addWidget( second_cb, 2,1,1,2);
		gridLayout->addWidget( setTime_b, 3,0,1,2);
		gridLayout->addWidget( mainMenu_b, 3,2,1,1);
		setLayout(gridLayout);
		connect(setTime_b, SIGNAL(clicked()), this, SLOT(sendTimeSlot()));
	}
	//all the connections
	connect(mainMenu_b, SIGNAL(clicked()), this, SLOT(closeGetTime()));
	connect(hour_cb,SIGNAL(currentIndexChanged(const QString & )), this,SLOT(tripHourFlag(const QString & )));
	connect(minute_cb,SIGNAL(currentIndexChanged(const QString & )), this, SLOT(tripMinuteFlag(const QString & )));
	connect(second_cb,SIGNAL(currentIndexChanged(const QString & )), this, SLOT(tripSecondFlag(const QString & )));

}

getTime::~getTime()
{
	std::cerr << "getTime.h: deleted\n";
	delete classType;
	delete class_l;
	delete hour_l;
	delete minute_l;
	delete second_l;
	delete hour_cb;
	delete minute_cb;
	delete second_cb;
	delete mainMenu_b;
	delete setTime_b;
	std::cerr << "getTime.h: deleted success\n";
}

int getTime::stringToInt(QString changer)
{
	std::string temp = changer.toStdString();
	int ret;
	for(int x = 0; x < temp.size();x++)
	{
		ret *= 10;
		ret += (temp.at(x)-48);
	}
	return ret;
}

QString getTime::IntToString(int changer)
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

void getTime::sendClassSlot()
{
	const QString n = classType->displayText();
	const int h = stringToInt(hour_cb->currentText());
	const int m = stringToInt(minute_cb->currentText());
	const int s = stringToInt(second_cb->currentText());
	emit sendClass(n ,h ,m ,s);
}

void getTime::sendTimeSlot()
{
	int h,m,s;
	if(hour_flag)
		 h = stringToInt(hour_cb->currentText());
	else
		 h = 0;
	if(minute_flag)
		 m = stringToInt(minute_cb->currentText());
	else
		 m = 0;
	if(second_flag)
		 s = stringToInt(second_cb->currentText());
	else
		 s = 0;
	emit sendTime(h ,m ,s);
}
void getTime::closeGetTime()
{
	emit closeGetTimeWin();
}

void getTime::tripHourFlag(const QString & text)
{
	hour_flag = true;
}
void getTime::tripMinuteFlag(const QString & text)
{
	minute_flag = true;
}
void getTime::tripSecondFlag(const QString & text)
{
	second_flag = true;
}