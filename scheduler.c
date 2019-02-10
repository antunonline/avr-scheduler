#include "scheduler.h"

char scheduler_task_buffer[150] = {22,24,26};

void scheduler_switch_task(void){
    asm volatile(
                "push r16\n"
                "push r17\n"
                "ldi r16, hi8(scheduler_task_buffer)\n"
                "ldi r17, lo8(scheduler_task_buffer)\n"
                "push r25\n"
                "push r26\n"
                "movw x, r16\n"
                "st X+, r0\n"
                "st X+, r1\n"
                "st X+, r2\n"
                "st X+, r3\n"
                "st X+, r4\n"
                "st X+, r5\n"
                "st X+, r6\n"
                "st X+, r7\n"
                "st X+, r8\n"
                );
}
