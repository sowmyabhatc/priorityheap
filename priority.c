#include <assert.h>
#include <stddef.h>
#include "scheduler.h"
#include <stdio.h>



Process process_new (uint32_t pid, uint32_t at, uint32_t et,uint32_t priority)
{
    Process p = { pid, at, et,priority,9, 0, 0};

    return p;
}

static void _swap_(Process *data1,Process *data2){
Process temp;
temp=*data1;
*data1=*data2;
*data2=temp;
}

static void _heapify_(Process data[],uint32_t len,uint32_t parent){  //index of the parent
assert(len>0 && len<HEAP_MAX_SIZE && parent>0);
uint32_t child=2*parent; //location of left child

while(child<=len){
    if(child+1 <=len){  //notedown the index of max child
        if(data[child+1].priority>data[child].priority){ //if value of right child >left child
            ++child;   //we increment child index to right child
        }
    }
    if(data[parent].priority>=data[child].priority){  //if value of parent is greater than data of max child
        break;
    }
    _swap_(&data[parent],&data[child]);  //else swap value
    parent=child;
    child=2*parent;
}

}

static void _test_Heap_(Process data[],uint32_t len){

for(uint32_t child=len; child>1; --child){
    assert(data[child].priority<=data[child/2].priority); //aserts if value of child <value of parent
}
}

Heap*  heap_test(Heap *heap){
assert(heap->size >0 && heap->size < HEAP_MAX_SIZE);
_test_Heap_(heap->data,heap->size);
return heap;

}



uint32_t heap_size(Heap *heap){
assert(heap->size >0 && heap->size < HEAP_MAX_SIZE);
return(heap->size);
}

Heap* heap_sort(Heap *heap){
assert(heap->size >0 && heap->size < HEAP_MAX_SIZE);
uint32_t idx=heap->size;
for(idx=heap->size; idx>1 ;idx--){  //idx-- bcz after every swap we are going to remove the terminal node from the next step.
    _swap_(&heap->data[idx],&heap->data[1]);
    _heapify_(heap->data,idx-1,1); // after swapping heap property will be lost only at the root node hence donot give len/2
}
return heap;
}

Heap  heap_new(Process data[],uint32_t len){
assert(len>0 && len<HEAP_MAX_SIZE );

Heap heap;

for(uint32_t idx=len/2;idx>0; --idx){

    _heapify_(data,len,idx);
}
heap.size=len;
memcpy(heap.data,data,(len+1)*sizeof(Process)); //first parameter is the destination,second para is the source,third para is the length or how many elements we want to store
_test_Heap_(heap.data,heap.size);

return heap;
}


//insert a new element into the heap
Heap*   heap_insert(Heap *heap,Process *p){
assert(heap->size >0 && heap->size < HEAP_MAX_SIZE);
uint32_t idx=heap->size+1;
heap->data[idx]=*p;
for(uint32_t i=idx/2; i>1 ;--i){
_heapify_(heap->data,idx,i);
}
++heap->size;
return heap;

}



//extract max element from the heap

int32_t heap_extract_max(Heap *heap){
assert(heap->size >0 && heap->size < HEAP_MAX_SIZE);
Process max=heap->data[1];
Process last=heap->data[heap->size];
heap->data[1]=last;
heap->size= heap->size-1;
_heapify_(heap->data,heap->size,1);


return max.pid;

}


//get maxmimum element from the heap

int32_t heap_get_max(Heap *heap){
return (heap->data[1].pid);
}


static void _schedule_(Heap *heap)
{
    static uint32_t cur_time = 0;
    //uint32_t wt_time, t_time;

    heap->data->wait_time = cur_time - heap->data->a_time;
    cur_time += heap->data->e_time;
    heap->data->tat_time  = cur_time - heap->data->a_time;
    assert(heap->data->e_time<=heap->data->deadline);

}

void fcfs_algorithm(Heap *heap)
{
    //while (q->count > 0)
    //{
        _schedule_(heap);
        heap_extract_max(heap);
        //printf ("pid: %d\twait time: %d\tTAT: %d\n",res->pid,res->wt,res->tat);
    //}

}
