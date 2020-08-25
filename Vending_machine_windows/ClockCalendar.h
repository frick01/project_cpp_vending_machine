
#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <time.h>
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
      friend void operator++ (ClockCalendar&);
  };
