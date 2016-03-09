#pragma once

#include "QTObject.h"
#include <QBrush>
#include <QColor>
#include <string>
#include <QWidget>
#include <iostream>
#include <vector>

struct WRect // helper struct that holds four ints that make up a rectangle.
{
  WRect(int xx, int yy, int ww, int hh)
  {
    x = xx;
    y = yy;
    w = ww;
    h = hh;
  };
  int x, y, w, h;
};

class Canvas : public QWidget
{
 Q_OBJECT

public:

  Canvas(QWidget *parent = 0);
  ~Canvas();

 public slots:
   /*
   - void updatePaint();
   - this is a slot that will update the player and the it will repaint the canvas...
   */
   void updatePaint();
   


   void updateTime(int h,int m, int s); // updates the time
   void insertObject(QTObject obj) {objects.push_back(obj);};


  protected:
    /*
     - void paintEvent();
     - this will paint all the objects onto the canvas
    */
     void paintEvent(QPaintEvent *);
  private:
    std::vector< QTObject > objects;
    WRect *hourW, *minutesW, *secondsW;

};
