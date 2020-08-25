
#include "ClockCalendar.h"

/*

period day 0 = madrugada;
           1 = manha;
           2 = tarde;
           4 = noite;
*/ 

ClockCalendar::ClockCalendar(void){
        setDay(30);
        setMonth(11);
        setYear(2018);
        setHr(9);
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
           //if( 0 < t.clockcalendar[3] <6){t.dayPeriod[0] = 0;}else if(6 < t.clockcalendar[3]<12){t.dayPeriod[0] = 1;}else if(12<t.clockcalendar[3]<18){t.dayPeriod[0]=2;}else if(18<t.clockcalendar[3]<24){t.dayPeriod[0]=3;}//
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