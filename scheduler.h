#ifndef SCHEDULER_HEADER
#define SCHEDULER_HEADER

extern unsigned char scheduler_task_buffer[150];

#define scheduler_yield() asm("jmp scheduler_switch_task\n")

void scheduler_init(void);

void scheduler_register_task( void(*task)(void));

unsigned int scheduler_get_pc(void);

void scheduler_enter(void);

void scheduler_switch_task(void);

#endif
