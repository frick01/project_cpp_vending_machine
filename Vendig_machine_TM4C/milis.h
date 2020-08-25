#ifndef MILIS_H_INCLUDED
#define MILIS_H_INCLUDED

#include"timer.h"
#include <unistd.h>
#include <stdint.h>

 void int_Handler(void);
 uint32_t milis();
 unsigned int kernelTick;

void clock_st(void)
{

  uint32_t ticks = start_timer(1, int_Handler);

  // cout<<" TICKS: "<<ticks<<endl;
}

uint32_t milis(void)
{
    return kernelTick;

}

void int_Handler(void)
{
 kernelTick++;
}


#endif // MILIS_H_INCLUDED
