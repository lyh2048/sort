#include "my_sort.h"
#include <stdio.h>
#include <stdlib.h>

#define N 10
#define MAX_VAL 100
#define BUCKET_SIZE 5

int main() {
    int* nums = generate_array(N, MAX_VAL);
    debug_array(nums, N);
    // 冒泡排序
    bubble_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 选择排序
    selection_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 插入排序
    insert_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 希尔排序
    shell_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 归并排序
    merge_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 快速排序
    quick_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 堆排序
    heap_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 计数排序
    count_sort(nums, N);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 桶排序
    bucket_sort(nums, N, BUCKET_SIZE);
    debug_array(nums, N);
    shuffle_array(nums, N);
    // 基数排序
    radix_sort(nums, N);
    debug_array(nums, N);
}