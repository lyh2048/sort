#include "my_sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


/**
 * @brief 打印数组内容
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void debug_array(int nums[], int n) {
    printf("----- debug_array -----\n");
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            printf("%d", nums[i]);
        } else {
            printf(" %d", nums[i]);
        }
    }
    printf("\n----- debug_array -----\n\n");
}

/**
 * @brief 随机产生一个长度为n的数组
 * 
 * @param n 数组长度
 * @param max_val 最大值
 * @return int* 数组
 */
int* generate_array(int n, int max_val) {
    srand(time(NULL));
    int * result = (int*)calloc(n, sizeof(int));
    if (max_val == 0) {
        return result;
    }
    for (int i = 0; i < n; i++) {
        result[i] = rand() % max_val;
    }
    return result;
}

/**
 * @brief 打乱数组元素
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void shuffle_array(int nums[], int n) {
    srand(time(NULL));
    while (n) {
        int i = rand() % n;
        n--;
        int tmp = nums[n];
        nums[n] = nums[i];
        nums[i] = tmp;
    }
}

/**
 * @brief 冒泡排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void bubble_sort(int nums[], int n) {
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (nums[j] > nums[j+1]) {
                int tmp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = tmp;
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

/**
 * @brief 选择排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void selection_sort(int nums[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int index = i;
        for (int j = i + 1; j < n; j++) {
            if (nums[j] < nums[index]) {
                index = j;
            }
        }
        if (index != i) {
            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
        }
    }
}

/**
 * @brief 插入排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void insert_sort(int nums[], int n) {
    for (int i = 1; i < n; i++) {
        int tmp = nums[i];
        int j = i;
        while (j > 0 && tmp < nums[j-1]) {
            nums[j] = nums[j-1];
            --j;
        }
        if (j != i) {
            nums[j] = tmp;
        }
    }
}

/**
 * @brief 希尔排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void shell_sort(int nums[], int n) {
    int gap = 1;
    while (gap < n / 3) {
        gap = 3 * gap + 1;
    }
    while (gap > 0) {
        for (int i = gap; i < n; i++) {
            int tmp = nums[i];
            int j = i - gap;
            while (j >= 0 && tmp < nums[j]) {
                nums[j+gap] = nums[j];
                j -= gap;
            }
            nums[j+gap] = tmp;
        }
        gap /= 3;
    }
}

/**
 * @brief 复制数组
 * 
 * @param nums 原数组
 * @param start 起始位置
 * @param end 结束位置（不包含）
 * @param m 结果数组的大小
 * @return int* 结果数组
 */
int* copy_array(int nums[], int start, int end, int &m) {
    m = end - start;
    int *res = (int*)calloc(m, sizeof(int));
    int k = 0;
    for (int i = start; i < end; i++) {
        res[k++] = nums[i];
    }
    return res;
}

/**
 * @brief 复制数组
 * 
 * @param nums 原数组
 * @param start 起始位置
 * @param end 结束位置（不包含）
 * @param result 结果数组
 */
void copy_array(int nums[], int start, int end, int result[]) {
    int k = 0;
    for (int i = 0; i < end; i++) {
        result[k++] = nums[i];
    }
}

/**
 * @brief 合并两个有序数组
 * 
 * @param arr1 数组1
 * @param n1 数组1的长度
 * @param arr2 数组2
 * @param n2 数组2的长度
 * @return int* 合并后的数组
 */
int* merge_array(int arr1[], int n1, int arr2[], int n2) {
    int *res = (int*)calloc(n1+n2, sizeof(int));
    int p1 = 0, p2 = 0, p3 = 0;
    while (p1 < n1 && p2 < n2) {
        if (arr1[p1] < arr2[p2]) {
            res[p3++] = arr1[p1];
            ++p1;
        } else {
            res[p3++] = arr2[p2];
            ++p2;
        }
    }
    while (p1 < n1) {
        res[p3++] = arr1[p1++];
    }
    while (p2 < n2) {
        res[p3++] = arr2[p2++];
    }
    return res;
}

/**
 * @brief 归并排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void merge_sort(int nums[], int n) {
    if (n < 2) {
        return;
    }
    int mid = n / 2;
    int n1, n2;
    int* left = copy_array(nums, 0, mid, n1);
    int* right = copy_array(nums, mid, n, n2);
    merge_sort(left, n1);
    merge_sort(right, n2);
    int* tmp = merge_array(left, n1, right, n2);
    free(left);
    free(right);
    copy_array(tmp, 0, n, nums);
    free(tmp);
}

/**
 * @brief 划分
 * 
 * @param nums 数组
 * @param left 数组左边界
 * @param right 数组右边界
 * @return int 
 */
int partition(int nums[], int left, int right) {
    int pivot = left;
    int index = pivot + 1;
    for (int i = index; i <= right; i++) {
        if (nums[i] < nums[pivot]) {
            int tmp = nums[i];
            nums[i] = nums[index];
            nums[index] = tmp;
            index++;
        }
    }
    int tmp = nums[pivot];
    nums[pivot] = nums[index-1];
    nums[index-1] = tmp;
    return index - 1;
}

/**
 * @brief 快速排序
 * 
 * @param nums 数组
 * @param left 数组左边界
 * @param right 数组右边界
 */
void quick_sort(int nums[], int left, int right) {
    if (left < right) {
        int index = partition(nums, left, right);
        quick_sort(nums, left, index - 1);
        quick_sort(nums, index + 1, right);
    }
}

/**
 * @brief 快速排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void quick_sort(int nums[], int n) {
    quick_sort(nums, 0, n - 1);
}

/**
 * @brief 调整堆
 * 
 * @param nums 数组 
 * @param i 起始位置 
 * @param n 长度
 */
void heapify(int nums[], int i, int n) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int k = i;
    if (left < n && nums[left] > nums[k]) {
        k = left;
    }
    if (right < n && nums[right] > nums[k]) {
        k = right;
    }
    if (k != i) {
        int tmp = nums[k];
        nums[k] = nums[i];
        nums[i] = tmp;
        heapify(nums, k, n);
    }
}

/**
 * @brief 建立最大堆
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void build_max_heap(int nums[], int n) {
    for (int i = n / 2; i >= 0; i--) {
        heapify(nums, i, n);
    }
}

/**
 * @brief 堆排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void heap_sort(int nums[], int n) {
    build_max_heap(nums, n);
    for (int i = n - 1; i > 0; i--) {
        int tmp = nums[0];
        nums[0] = nums[i];
        nums[i] = tmp;
        --n;
        heapify(nums, 0, n);
    }
}

/**
 * @brief 获取数组的最大值
 * 
 * @param nums 数组
 * @param n 数组长度 
 * @return int 最大值
 */
int get_max_array(int nums[], int n) {
    int ans = nums[0];
    for (int i = 1; i < n; i++) {
        if (ans < nums[i]) {
            ans = nums[i];
        }
    }
    return ans;
}

/**
 * @brief 计数排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void count_sort(int nums[], int n) {
    int max_val = get_max_array(nums, n);
    int *cnt = (int*)calloc(max_val + 1, sizeof(int));
    for (int i = 0; i < n; i++) {
        int val = nums[i];
        cnt[val]++;
    }
    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (cnt[i]) {
            nums[index++] = i;
            cnt[i]--;
        }
    }
    free(cnt);
}

/**
 * @brief 桶排序
 * 
 * @param nums 数组
 * @param n 数组长度
 * @param bucket_size 每个桶的大小 
 */
void bucket_sort(int nums[], int n, int bucket_size) {
    if (n <= 1) {
        return;
    }
    int min_val = nums[0], max_val = nums[0];
    for (int i = 1; i < n; i++) {
        if (nums[i] > max_val) {
            max_val = nums[i];
        }
        if (nums[i] < min_val) {
            min_val = nums[i];
        }
    }
    int bucket_count = (max_val - min_val) / bucket_size + 1;
    int *buckets[bucket_count];
    int cnt[bucket_count] = {0};
    for (int i = 0; i < bucket_count; i++) {
        buckets[i] = (int*)calloc(bucket_size, sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        int index = (nums[i] - min_val) / bucket_size;
        buckets[index][cnt[index]] = nums[i];
        cnt[index]++;
    }
    int index = 0;
    for (int i = 0; i < bucket_count; i++) {
        if (cnt[i] == 0) {
            continue;
        }
        insert_sort(buckets[i], cnt[i]);
        for (int j = 0; j < cnt[i]; j++) {
            nums[index++] = buckets[i][j];
        }
    }
    for (int i = 0; i < bucket_count; i++) {
        free(buckets[i]);
    }
}

/**
 * @brief 基数排序
 * 
 * @param nums 数组
 * @param n 数组长度
 * @param max_digit 最大位数
 */
void radix_sort(int nums[], int n, int max_digit) {
    int mod = 10, dev = 1;
    for (int i = 0; i < max_digit; i++, dev *= 10, mod *= 10) {
        int cnt[mod * 2] = {0};
        int *buckets[mod * 2];
        for (int j = 0; j < mod * 2; j++) {
            buckets[j] = (int*)calloc(n, sizeof(int));
        }
        for (int j = 0; j < n; j++) {
            int index = (nums[j] % mod) / dev + mod;
            buckets[index][cnt[index]++] = nums[j];
        }
        int p = 0;
        for (int j = 0; j < mod * 2; j++) {
            for (int k = 0; k < cnt[j]; k++) {
                nums[p++] = buckets[j][k];
            }
        }
        for (int j = 0; j < mod * 2; j++) {
            free(buckets[j]);
        }
    }
}

/**
 * @brief 获取数字的长度
 * 
 * @param num 数字
 * @return int 数字的长度
 */
int get_num_length(ll num) {
    if (num == 0) {
        return 1;
    }
    int ans = 0;
    while (num) {
        ++ans;
        num /= 10;
    }
    return ans;
}

/**
 * @brief 基数排序
 * 
 * @param nums 数组
 * @param n 数组长度
 */
void radix_sort(int nums[], int n) {
    int max_val = get_max_array(nums, n);
    int max_digit = get_num_length(max_val);
    radix_sort(nums, n, max_digit);
}
