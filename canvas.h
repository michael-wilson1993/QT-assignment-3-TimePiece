#pragma once

#include "QTObject.h"
#include <QBrush>
#include <QColor>
#include <string>
#include <QWidget>
#include <iostream>
#include <vector>


class Canvas : public QWidget
{
 Q_OBJECT

public:

 Canvas(QWidget *parent = 0);

 public slots:
   /*
   - void updatePaint();
   - this is a slot that will update the player and the it will repaint the canvas...
   */
   void updatePaint();
   


   void updateTime(int h,int m, int s) {hour=h;minutes=m;seconds=s;}; // updates the time
   void insertObject(QTObject obj) {objects.push_back(obj);};


  protected:
    /*
     - void paintEvent();
     - this will paint all the objects onto the canvas
    */
     void paintEvent(QPaintEvent *);
  private:
    std::vector< QTObject > objects;
    int hour, minutes, seconds;
    QRect *hourW, *minuteW, *secondW;

};
