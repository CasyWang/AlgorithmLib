/*
The MIT License (MIT)

Copyright (c) <2014> <oliver-lxtech2013@gmail.com>

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <iostream>
#include <stdlib.h>
using namespace std;

#define TEST_SUIT_SIZE     100

int qsPartition(int a[], int p, int r);
void quickSort(int a[], int p, int r);

int main()
{
    cout << "QuickSort Man" << endl;
    //随机生成测试数据
    int _random = 0;
    int* testSuit = NULL;
    testSuit = new int[TEST_SUIT_SIZE];
    if(testSuit == NULL) {
        cout << "error while malloc, exit" << endl;
        return 0;
    }

    int i = 0;
    for(; i < TEST_SUIT_SIZE; i++) {
        _random = 1 + rand() % 100;
        testSuit[i] = _random;
        cout << "raw" << i << ":" << testSuit[i] << endl;
    }

    quickSort(testSuit, 0, TEST_SUIT_SIZE - 1);

    for(i = 0; i < TEST_SUIT_SIZE; i++) {
        cout << "result" << i << ":" << testSuit[i] << endl;
    }

    return 0;
}

/** 交换两个数据位置
  @param a 待交换元素a的地址
  @param b 待交换元素b的地址
  @return none
*/
void Swap(int* a, int* b) {
    //如果两个地址相同,则不做交换
    if(a == b) return;

    int mid = *a;
    *a = *b;
    *b = mid;
}

/** 快速排序,非原址
  @param a 待排序数组.
  @param p 数组左边界
  @param r 数组右边界
  @return None
*/
void quickSort(int a[], int p, int r) {
    if(p < r) {                          //递归循环终止条件, p = r,也就是区间只剩余一个元素的时候
        int mid = qsPartition(a, p, r);  //先分割
        quickSort(a, p, mid - 1);        //对mid左侧的递归调用排序
        quickSort(a, mid + 1, r);        //对mid右侧的递归调用排序
    }
}


/** 分割,排序完后无序区分为三个区间,[p,i] [i+1] [i+2,r].
  @param a 待排序数组.
  @param p 数组左边界
  @param r 数组右边界
  @return 中间分界元素i+1下标
*/
int qsPartition(int a[], int p, int r) {
    int key = a[r];    //比较权值
    int i = p - 1;     //记录最大的牌与最小的牌的边界
    int j = p;
    for (; j < r; j++) {
        if(a[j] <= key) {
            i++;
            Swap(&a[i], &a[j]);    //将找到的小值与大小交界处的那个大值交换
        }
    }
    Swap(&a[i + 1], &a[r]);
    return i+1;
}


