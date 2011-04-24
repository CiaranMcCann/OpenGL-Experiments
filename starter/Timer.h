#pragma once
#pragma comment(lib,"winmm")
#include <Mmsystem.h>
//code taken from http://nehe.gamedev.net/data/lessons/lesson.asp?lesson=21
// thanks to Jeff Molofee 

class Timer
{
  __int64       frequency;							// Timer Frequency
  float         resolution;							// Timer Resolution
  unsigned long mm_timer_start;							// Multimedia Timer Start Value
  unsigned long mm_timer_elapsed;						// Multimedia Timer Elapsed Time
  bool		performance_timer;						// Using The Performance Timer?
  __int64       performance_timer_start;					// Performance Timer Start Value
  __int64       performance_timer_elapsed;					// Performance Timer Elapsed Time


public:
    Timer(void);
public:
    ~Timer(void);
public:
    int Init(void);
public:
    float getTime(void);
};
