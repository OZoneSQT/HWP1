/*
 * stopwatch.h
 *
 * Created: 10/03/2023 08.39.26
 *  Author: skrue
 */ 


#ifndef STOPWATCH_H_
#define STOPWATCH_H_

#include <avr/io.h>
#include <stdint.h>
#include "delayTimer.h"

void init_stopwatch(uint8_t ms);

void start_stopwatch();
void reset_stopwatch();
void pause_stopwatch();



#endif /* STOPWATCH_H_ */