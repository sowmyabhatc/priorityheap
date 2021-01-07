#ifndef SCHEDULER_H_INCLUDED
#define SCHEDULER_H_INCLUDED

#define HEAP_MAX_SIZE 32

#include <stdint.h>
typedef struct _process_ Process;
struct _process_ {
    uint32_t pid;
    uint32_t a_time;
    uint32_t e_time;
    uint32_t priority;
    uint32_t deadline;
    uint32_t wait_time;
    uint32_t tat_time;

};

typedef struct _heap_ Heap;
struct _heap_{
uint32_t size;
Process  data[HEAP_MAX_SIZE];
};

Process  process_new(uint32_t pid, uint32_t at, uint32_t et,uint32_t priority);
Heap    heap_new(Process *p,uint32_t len); //Build a max heap
Heap*   heap_sort(Heap *heap);
Heap*   heap_insert(Heap *heap,Process *p);
Heap*   heap_test(Heap *heap);
int32_t heap_get_max(Heap *heap);
int32_t heap_extract_max(Heap *heap);
uint32_t heap_size(Heap *heap);


void fcfs_algorithm(Heap *heap);
#endif // SCHEDULER_H_INCLUDED

