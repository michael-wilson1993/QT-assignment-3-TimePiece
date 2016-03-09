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
   secondsW = new WRect(801,601,99,0);
   minutesW = new WRect(551,601,199,0);
   hourW = new WRect(201,600,299,0);
}
Canvas::~Canvas()
{
   std::cerr << "canvas.h : deleted hour"<< std::endl;
   delete hourW;
   delete minutesW;
   delete secondsW;
   std::cerr << "canvas.h : deleted hour - success "<< std::endl;
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
   const QColor color(28,183,235);
   paint.setPen(QPen(color, 2, Qt::SolidLine));
   
   paint.fillRect(hourW->x,hourW->y,hourW->w,hourW->h,color);
   paint.fillRect(minutesW->x,minutesW->y,minutesW->w,minutesW->h,color);
   paint.fillRect(secondsW->x,secondsW->y,secondsW->w,secondsW->h,color);



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




void Canvas::updateTime(int h,int m, int s)
{
   secondsW->h = s*-5;
   minutesW->h = m*-5;
   hourW->h = h*-25;
   update();
}