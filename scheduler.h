#ifndef SCHEDULER_HEADER
#define SCHEDULER_HEADER


void scheduler_init(void);

void scheduler_register_task( void(*task)(void));

unsigned int scheduler_get_pc(void);

void scheduler_enter(void);

void scheduler_switch_task(void);

void scheduler_yield(void);

#endif
