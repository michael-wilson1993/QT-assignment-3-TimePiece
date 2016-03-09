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
   hourW = new QRect(801,601,99,100);
   minuteW = new QRect(551,601,199,100);
   secondW = new QRect(201,600,299,100);
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
   const QColor color(0,0,255);
   paint.setPen(QPen(color, 2, Qt::SolidLine));
   paint.fillRect(100,100,200,200,color);
   //paint.fillRect(minuteW, color);
   //paint.fillRect(secondW, color);


   //****Draws the shapes****
   for(int x = 0; x < objects.size(); x++)
   {
      if(!objects[x].text) // if it is not a text string
      {
         //makes a new brush with the colour of the object
         QColor color(objects[x].red,objects[x].green,objects[x].blue);

         paint.setPen(QPen(color, 2, Qt::SolidLine));

         // draws a line through all the coordinates
         for(int y = 0; y < objects[x].shapes.size()-1; y++)
         {
            paint.drawLine(objects[x].shapes[y].x, objects[x].shapes[y].y,
                          objects[x].shapes[y+1].x, objects[x].shapes[y+1].y);
         }
         //if the end and start of the vertices are connected, draw a line between them
         if(objects[x].connect)
            paint.drawLine(objects[x].shapes[0].x, objects[x].shapes[0].y,
                           objects[x].shapes[  objects[x].shapes.size()-1  ].x, objects[x].shapes[  objects[x].shapes.size()-1  ].y);
      }
      else
      {
         paint.drawText(objects[x].shapes[0].x, objects[x].shapes[0].y, objects[x].textString);
      }
   }


  
   //****Draws the water****

}




