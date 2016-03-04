#include "GlobalHeader.h"

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);
	mainWin window;
	window.resize(1100,700);
	window.setWindowTitle("time Piece"); 
	window.show();
	return app.exec(); 

}