#pragma once


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


  protected:
    /*
     - void paintEvent();
     - this will paint all the objects onto the canvas
    */
     void paintEvent(QPaintEvent *);
  private:

};
