#ifndef MY_SORT_H
#define MY_SORT_H

typedef long long ll;

// 打印数组
void debug_array(int nums[], int n);
// 随机产生一个长度为n的数组
int* generate_array(int n, int max_val);
// 打乱数组元素
void shuffle_array(int nums[], int n);
// 冒泡排序
void bubble_sort(int nums[], int n);
// 选择排序
void selection_sort(int nums[], int n);
// 插入排序
void insert_sort(int nums[], int n);
// 希尔排序
void shell_sort(int nums[], int n);
// 归并排序
void merge_sort(int nums[], int n);
// 快速排序
void quick_sort(int nums[], int n);
// 堆排序
void heap_sort(int nums[], int n);
// 计数排序
void count_sort(int nums[], int n);
// 桶排序
void bucket_sort(int nums[], int n, int bucket_size);
// 基数排序
void radix_sort(int nums[], int n);

#endif