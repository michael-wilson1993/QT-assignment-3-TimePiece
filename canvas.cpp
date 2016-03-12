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
Canvas::Canvas( QWidget *parent)
{
   DropBelow = true;
   secondsW = new WRect(801,601,99,0);
   minutesW = new WRect(551,601,199,0);
   hourW = new WRect(201,600,299,0);
   animClock = new QTClock(false, 10, this);
   connect(animClock, SIGNAL(tick(const int &)), this, SLOT(animTick(const int &)));

   if(DropBelow)
   {
      hourDrop = new QTObject(801,601,99, false, false, "g", 350,0);
      minuteDrop = new QTObject(801,601,99, false, false, "g", 650,0);
      secondDrop = new QTObject(801,601,99, false, false, "g", 850,0);
   }
   else
   {
      hourDrop = new QTObject(801,601,99, false, false, "g", 350,2200);
      minuteDrop = new QTObject(801,601,99, false, false, "g", 650,2200);
      secondDrop = new QTObject(801,601,99, false, false, "g", 850,2200);
   }
   


   drawHD = false;
   drawMD = false;
   drawSD = false;
   initDrops = false;
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

      //****Draws the water****
   paint.setBrush( QBrush( color, Qt::SolidPattern ));
   paint.setPen(QPen(color, 2, Qt::SolidLine));

   if(drawHD)
   {
      paint.drawEllipse(QPointF(hourDrop->shapes[0].x,hourDrop->shapes[0].y), 5, 10);
   }
   if(drawMD)
   {
      paint.drawEllipse(QPointF(minuteDrop->shapes[0].x,minuteDrop->shapes[0].y), 5, 10);
   }
   if(drawSD)
   {
      paint.drawEllipse(QPointF(secondDrop->shapes[0].x,secondDrop->shapes[0].y), 5, 10);
   }

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


  


}




void Canvas::updateTime(int h,int m, int s)
{
   bool a=false,b=false,c=false;
   secondsW->h = s*-5;
   minutesW->h = m*-5;
   hourW->h = h*-25;


   if(initDrops)
   {
      if(s != second)
         c=true;
      if(m != minute)
         b=true;
      if(h!= hour)
         a=true;
   }
   std::cerr << "hour \n" << hour << " " << h << "\n";
   hour = h;
   minute = m;
   second= s;
   if (!initDrops)
      initDrops = true;
   drop(a,b,c);
   update();
}

void Canvas::drop(bool h, bool m, bool s)
{
   std::cerr << "\n\n" << DropBelow << "\n\n";
   if(DropBelow)
   {
      if(h)
         hourDrop->shapes[0].y =600;
      if(m)
         minuteDrop->shapes[0].y =600;
      if(s)
         secondDrop->shapes[0].y =600;
   }
   else
   {
      if(h)
         hourDrop->shapes[0].y =10;
      if(m)
         minuteDrop->shapes[0].y =10;
      if(s)
         secondDrop->shapes[0].y =10;
   }
}

void Canvas::animTick(const int &info)
{
   const int speed = 6;
   if(DropBelow)
   {
      if(hourDrop->shapes[0].y > 550&& hourDrop->shapes[0].y < 2220)
      {
         hourDrop->shapes[0].y+=speed;  
         drawHD = true;
      }
      else
      {
         drawHD = false;
         hourDrop->shapes[0].y = 0;
      }
      if(minuteDrop->shapes[0].y >550&& minuteDrop->shapes[0].y < 2220)
      {
         minuteDrop->shapes[0].y+=speed;  
         drawMD = true;
      }
      else
      {
         drawMD = false;
         minuteDrop->shapes[0].y = 0;
      }
      if(secondDrop->shapes[0].y >550 && secondDrop->shapes[0].y < 2220)
      {
         drawSD = true;
         secondDrop->shapes[0].y+=speed;  
      }
      else
      {
         drawSD = false;
         secondDrop->shapes[0].y = 0;
      }
   }
   else // if we are dropping from the top of the map...
   {
      if(hourDrop->shapes[0].y < 580)
      {
         hourDrop->shapes[0].y+=speed;  
         drawHD = true;
      }
      else
      {
         drawHD = false;
         hourDrop->shapes[0].y = 2200;
      }
      if(minuteDrop->shapes[0].y < 580)
      {
         minuteDrop->shapes[0].y+=speed;  
         drawMD = true;
      }
      else
      {
         drawMD = false;
         minuteDrop->shapes[0].y = 2200;
      }
      if(secondDrop->shapes[0].y < 580)
      {
         drawSD = true;
         secondDrop->shapes[0].y+=speed;  
      }
      else
      {
         drawSD = false;
         secondDrop->shapes[0].y = 2200;
      }
   }

   update();
}