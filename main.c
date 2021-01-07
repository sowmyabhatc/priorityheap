#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scheduler.h"

void test_sort(Process data[],uint32_t len)
{
    uint32_t idx;
    for(idx=1; idx<len;++idx){
        assert(data[idx].priority<=data[idx+1].priority);
    }
}

void fcfs_scheduler()
{
    Process p0=  process_new(0,0,0,0);
    Process p1 = process_new(1,0,5,1);
    Process p2 = process_new(2,2,8,7);
    Process p3 = process_new(3,4,2,8);
    Process p4 = process_new(4,4,4,6);

    Process data[]={p0,p1,p2};
    Heap heap=heap_new(data,2);
    assert(heap_size(&heap) ==2);


    heap_insert(&heap,&p3);
    heap_insert(&heap,&p4);
    assert(heap_size(&heap) ==4);

    heap_sort(&heap);
    test_sort(heap.data,4);
    heap_test(&heap);
    /*
    fcfs_algorithm(&heap);


    assert(heap.data->pid == 1);
    assert(heap.data->wait_time == 0);
    assert(heap.data->tat_time == 5);

    fcfs_algorithm(&heap);

    assert(heap.data->pid == 2);
    assert(heap.data->wait_time  == 3);
    assert(heap.data->tat_time== 11);

    fcfs_algorithm(&heap);

    assert(heap.data->pid == 3);
    assert(heap.data->wait_time  == 9);
    assert(heap.data->tat_time == 11);

    fcfs_algorithm(&heap);

    assert(heap.data->pid == 4);
    assert(heap.data->wait_time  == 11);
    assert(heap.data->tat_time == 15);

*/

}

int main()
{
    fcfs_scheduler();

    return 0;
}




