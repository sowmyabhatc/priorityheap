#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "scheduler.h"
/*
void test_sort(Process data[],uint32_t len)
{
    uint32_t idx;
    for(idx=1; idx<len;++idx){
        assert(data[idx].priority<=data[idx+1].priority);
    }
}
*/
void fcfs_scheduler()
{



    Process p0=  process_new(0,0,0,0);
    Process p1 = process_new(1,0,5,4);
    Process p2 = process_new(2,2,8,3);
    Process p3 = process_new(3,4,2,2);
    Process p4 = process_new(4,4,4,1);


    Process data[]={p0,p1,p2,p3,p4};
    Heap heap=heap_new(data,4);
    assert(heap_size(&heap) ==4);
    heap_test(&heap);
    //assert(heap_extract_max(&heap) == 1);

    fcfs_algorithm(&heap);


    assert(heap_extract_max(&heap) == 1);
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



}

int main()
{
    fcfs_scheduler();

    return 0;
}




