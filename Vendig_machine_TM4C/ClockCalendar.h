#ifndef CLOCKCALENDAR_H_INCLUDED
#define CLOCKCALENDAR_H_INCLUDED

#include <iostream>
#include <stdlib.h>
//#include <time.h>
using namespace std;

class ClockCalendar {
      int clockcalendar[6];  // [ dia, m�s, ano, hora, minuto, segundo ]

   public:
      ClockCalendar(void);
      void setDay(int);
      void setMonth(int);
      void setYear(int);
      void setHr(int);
      void setMin(int);
      void setSeg(int);
      int * getClockCalendar(void);
      int * dayPeriod; 
      friend void operator++ (ClockCalendar&);
      
  };


#endif