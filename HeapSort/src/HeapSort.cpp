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

/*
 * [public]建立最大堆
 * @param a 堆化数组
*/
void HeapSortArray::buildMaxHeap(vector<int> &a) {
    int len = a.size();
    int i;                 //倒数第一个非叶子节点的下标为n/2 - 1(有孩子的节点为[len/2-1, 0])
    for(i = len/2 - 1; i >= 0; i--) {
        maxHeapify(a, i, len);
    }
}

/*
 * [public]维护最大堆性质
 * @param a 堆化数组
 * @param index Root节点下标
 * @param heap_size 调整的树长度
*/
void HeapSortArray::maxHeapify(vector<int> &a, int root, int heap_size) {
    int l = 2 * root + 1;        //左孩子,如果下标从0开始,Left(root) = 2 * root + 1;
    int r = l + 1;               //右孩子
    int largest = root;          //首先老子认为老子自个是最大的

    /* 左边的孩子跟老子比大(记得先看看自个左边有没有孩子) */
    if(l <= heap_size - 1 && a[l] > a[largest]) {
        largest = l;             //我去,左边的孩子居然比我大,好吧,最大称号让给你了.
    }
    /* 右孩子跟老子比大(记得看看自个右边有没有孩子) */
    if(r <= heap_size - 1 && a[r] > a[largest]) {
        largest = r;             //我去,右边的孩子居然比我大,好吧,最大称号让给你了.
    }
    /*
      * 如果老子我不是最大的,那没办法,最顶上的王位
      * 要拱手让给最大的儿子
     */
    if(largest != root) {
        _swap(&a[root], &a[largest]);         //和大儿子换个位
        maxHeapify(a, largest, heap_size);    //换到大儿子家,妈呀,还得看有没有打破儿子家的平衡,和孙子比比(交换后largest处大顶堆可能破坏,递归重新排)
    }
}

/*
 * [public]排序
*/
void HeapSortArray::Sort() {
    /* 构建大顶堆 */
    int heap_size = this->_sortArray.size();    //数据长度
    buildMaxHeap(this->_sortArray);             //建立大顶堆
    int i;
    for(i = heap_size - 1; i > 0; i--) {
        _swap(&this->_sortArray[i], &this->_sortArray[0]);    //交换,冒出最大Root
        maxHeapify(this->_sortArray, 0, i);                   //交换完后重新调整大顶堆
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
 * [public]打印数组
*/
void HeapSortArray::Printf() {
    int i = 0;
    cout<<"Array:"<<endl;
    for(; i < this->_sortArray.size(); i++) {
        cout<<"A"<<i<<":"<<this->_sortArray[i]<<endl;
    }
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

