#ifndef stateMachine_included
#define stateMachine_included

extern char state;
extern int state_counter_two;

void state_advance();

void state_one();

void state_two();

void state_two_zero();
void state_two_one();
void state_two_two();
void state_two_three();

void state_three();

void state_four();

void sm_fast_clock();
void sm_slow_clock();
void sm_update_led();

#endif
