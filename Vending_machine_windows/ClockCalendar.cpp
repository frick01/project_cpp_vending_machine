
#include "ClockCalendar.h"

ClockCalendar::ClockCalendar(void){
        setDay(30);
        setMonth(11);
        setYear(2018);
        setHr(17);
        setMin(30);
        setSeg(0);
}

void ClockCalendar::setDay(int day){
        clockcalendar[0] = day;
  }

void ClockCalendar::setMonth(int month){
        clockcalendar[1] = month;
  }

void ClockCalendar::setYear(int year){
        clockcalendar[2] = year;
  }

void ClockCalendar::setHr(int nhr){
        clockcalendar[3] = nhr;
  }

void ClockCalendar::setMin(int nmin){
        clockcalendar[4] = nmin;
  }

void ClockCalendar::setSeg(int nseg){
        clockcalendar[5] = nseg;
  }

int * ClockCalendar::getClockCalendar(void){
    return clockcalendar;

}

void operator++ (ClockCalendar& t){
   t.clockcalendar[5]++;
   if(t.clockcalendar[5] == 60){
      t.clockcalendar[5] = 0; t.clockcalendar[4]++;
      if(t.clockcalendar[4] == 60){
         t.clockcalendar[4] = 0; t.clockcalendar[3]++;
	 if(t.clockcalendar[3] == 24){
	    t.clockcalendar[3] = 0; t.clockcalendar[0]++;
            if(t.clockcalendar[0] == 30){
              t.clockcalendar[0] = 1; t.clockcalendar[1]++;
              if(t.clockcalendar[1] == 12){
                t.clockcalendar[1] = 1; t.clockcalendar[2]++;

              }
            }
          }
        }
      }
    }
