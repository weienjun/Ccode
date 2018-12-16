#ifdef __TEST_H__

#define __TEST_H__

#endif 

int binary_search(const int arr[],const int data,int left,int right);//递归法二分查找
int choose_search(int arr[],const int sz);//选择排序
int choose_search1(int arr[],const int sz);//优化选择排序
int bubble_sort(int arr[],const int sz);//优化冒泡排序
int selection_sort(int arr[],const int sz);//快速排序
static void change(int *arr,int *anum);//交换两个数
void print(const int arr[],const int sz);//输出