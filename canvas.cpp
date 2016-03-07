/*
   - author: Michael Wilson
   - prof: 
   - school class: 
   - class: canvas 
   - description **  **
   - Assignment 
*/

#include<QtGui>
#include "canvas.h"

// creates the objects
Canvas::Canvas(QWidget *parent)
{


}

// slot so paint can be updated!
void Canvas::updatePaint()
{  
   update();
}

// draws shapes, paths, start, goal and path when it is found
void Canvas::paintEvent(QPaintEvent *event)
{
   
   QPainter paint(this); 
  
}




