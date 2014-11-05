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

#include "HeapSort.h"

HeapSortArray::HeapSortArray()
{
    //ctor
}

HeapSortArray::~HeapSortArray()
{
    //dtor
}

void HeapSortArray::buildMaxHeap(vector<int> a) {
    int len = a.size();
    int i = len/2 - 1;      //倒数第一个非叶子节点为n/2
    for(; i >= 0; i--) {
        maxHeapify(a, i, len - i - 1);
    }
}

/*
 * [private]维护最大堆性质
 * @param a 堆化数组
 * @param index Root节点下标
 * @param len 调整的树长度
*/
void HeapSortArray::maxHeapify(vector<int> a, int root, int len) {
    int l = 2 * root;        //左孩子
    int r = l + 1;           //右孩子
    int largest = 0;         //记录最大值
    /* 左孩子跟Parent中找最大的 */
    if(l <= len - 1 && a[l] > a[root]) {
        largest = l;
    } else {
        largest = root;
    }
    /* 右孩子跟当前最大的比 */
    if(r <= len - 1 && a[r] > a[largest]) {
        largest = r;
    }
    /* 交换largest和根 */
    if(largest != root) {
        _swap(&a[root], &a[largest]);
        maxHeapify(a, largest, a.size() - 1 - largest);    //largest大顶堆可能破坏,递归重新排
    }

}

void HeapSortArray::Sort() {
    /* 构建大顶堆 */
    int len = this->_sortArray.size();    //数据长度
    buildMaxHeap(this->_sortArray);
    int i = len - 1;
    for(; i > 0; i--) {
        _swap(&this->_sortArray[i], &this->_sortArray[0]);    //交换,冒出最大Root
        len--;                                                  //冒出一个后,减1
        maxHeapify(this->_sortArray, 0, len);               //交换完后重新调整大顶堆
    }

}

/*
 * [public]添加一个元素到末尾
 * @param a 要添加的元素
 * @retval none
*/
void HeapSortArray::Add(int a) {
    this->_sortArray.push_back(a);
}

/*
 * [private]获取某个数
 * @param a 要交换数的a的地址
 * @param b 要交换的数b的地址
*/
int HeapSortArray::Get(int index) {
    return this->_sortArray[index];
}

/*
 * [public]获取此序列里元素的个数
 * @param a 要交换数的a的地址
 * @param b 要交换的数b的地址
*/
int HeapSortArray::Length() {
    return this->_sortArray.size();
}

/*
 * [private]交换两个数
 * @param a 要交换数的a的地址
 * @param b 要交换的数b的地址
*/
void HeapSortArray::_swap(int* a, int* b) {
    //如果两个地址相同,则不做交换
    if(a == b) return;

    int mid = *a;
    *a = *b;
    *b = mid;
}

