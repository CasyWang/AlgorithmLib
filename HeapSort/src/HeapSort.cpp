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
    int i = len/2 - 1;      //������һ����Ҷ�ӽڵ�Ϊn/2
    for(; i >= 0; i--) {
        maxHeapify(a, i, len - i - 1);
    }
}

/*
 * [private]ά����������
 * @param a �ѻ�����
 * @param index Root�ڵ��±�
 * @param len ������������
*/
void HeapSortArray::maxHeapify(vector<int> a, int root, int len) {
    int l = 2 * root;        //����
    int r = l + 1;           //�Һ���
    int largest = 0;         //��¼���ֵ
    /* ���Ӹ�Parent�������� */
    if(l <= len - 1 && a[l] > a[root]) {
        largest = l;
    } else {
        largest = root;
    }
    /* �Һ��Ӹ���ǰ���ı� */
    if(r <= len - 1 && a[r] > a[largest]) {
        largest = r;
    }
    /* ����largest�͸� */
    if(largest != root) {
        _swap(&a[root], &a[largest]);
        maxHeapify(a, largest, a.size() - 1 - largest);    //largest�󶥶ѿ����ƻ�,�ݹ�������
    }

}

void HeapSortArray::Sort() {
    /* �����󶥶� */
    int len = this->_sortArray.size();    //���ݳ���
    buildMaxHeap(this->_sortArray);
    int i = len - 1;
    for(; i > 0; i--) {
        _swap(&this->_sortArray[i], &this->_sortArray[0]);    //����,ð�����Root
        len--;                                                  //ð��һ����,��1
        maxHeapify(this->_sortArray, 0, len);               //����������µ����󶥶�
    }

}

/*
 * [public]���һ��Ԫ�ص�ĩβ
 * @param a Ҫ��ӵ�Ԫ��
 * @retval none
*/
void HeapSortArray::Add(int a) {
    this->_sortArray.push_back(a);
}

/*
 * [private]��ȡĳ����
 * @param a Ҫ��������a�ĵ�ַ
 * @param b Ҫ��������b�ĵ�ַ
*/
int HeapSortArray::Get(int index) {
    return this->_sortArray[index];
}

/*
 * [public]��ȡ��������Ԫ�صĸ���
 * @param a Ҫ��������a�ĵ�ַ
 * @param b Ҫ��������b�ĵ�ַ
*/
int HeapSortArray::Length() {
    return this->_sortArray.size();
}

/*
 * [private]����������
 * @param a Ҫ��������a�ĵ�ַ
 * @param b Ҫ��������b�ĵ�ַ
*/
void HeapSortArray::_swap(int* a, int* b) {
    //���������ַ��ͬ,��������
    if(a == b) return;

    int mid = *a;
    *a = *b;
    *b = mid;
}

