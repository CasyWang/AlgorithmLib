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
 * [public]��������
 * @param a �ѻ�����
*/
void HeapSortArray::buildMaxHeap(vector<int> &a) {
    int len = a.size();
    int i;                 //������һ����Ҷ�ӽڵ���±�Ϊn/2 - 1(�к��ӵĽڵ�Ϊ[len/2-1, 0])
    for(i = len/2 - 1; i >= 0; i--) {
        maxHeapify(a, i, len);
    }
}

/*
 * [public]ά����������
 * @param a �ѻ�����
 * @param index Root�ڵ��±�
 * @param heap_size ������������
*/
void HeapSortArray::maxHeapify(vector<int> &a, int root, int heap_size) {
    int l = 2 * root + 1;        //����,����±��0��ʼ,Left(root) = 2 * root + 1;
    int r = l + 1;               //�Һ���
    int largest = root;          //����������Ϊ�����Ը�������

    /* ��ߵĺ��Ӹ����ӱȴ�(�ǵ��ȿ����Ը������û�к���) */
    if(l <= heap_size - 1 && a[l] > a[largest]) {
        largest = l;             //��ȥ,��ߵĺ��Ӿ�Ȼ���Ҵ�,�ð�,���ƺ��ø�����.
    }
    /* �Һ��Ӹ����ӱȴ�(�ǵÿ����Ը��ұ���û�к���) */
    if(r <= heap_size - 1 && a[r] > a[largest]) {
        largest = r;             //��ȥ,�ұߵĺ��Ӿ�Ȼ���Ҵ�,�ð�,���ƺ��ø�����.
    }
    /*
      * ��������Ҳ�������,��û�취,��ϵ���λ
      * Ҫ�����ø����Ķ���
     */
    if(largest != root) {
        _swap(&a[root], &a[largest]);         //�ʹ���ӻ���λ
        maxHeapify(a, largest, heap_size);    //��������Ӽ�,��ѽ,���ÿ���û�д��ƶ��Ӽҵ�ƽ��,�����ӱȱ�(������largest���󶥶ѿ����ƻ�,�ݹ�������)
    }
}

/*
 * [public]����
*/
void HeapSortArray::Sort() {
    /* �����󶥶� */
    int heap_size = this->_sortArray.size();    //���ݳ���
    buildMaxHeap(this->_sortArray);             //�����󶥶�
    int i;
    for(i = heap_size - 1; i > 0; i--) {
        _swap(&this->_sortArray[i], &this->_sortArray[0]);    //����,ð�����Root
        maxHeapify(this->_sortArray, 0, i);                   //����������µ����󶥶�
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
 * [public]��ӡ����
*/
void HeapSortArray::Printf() {
    int i = 0;
    cout<<"Array:"<<endl;
    for(; i < this->_sortArray.size(); i++) {
        cout<<"A"<<i<<":"<<this->_sortArray[i]<<endl;
    }
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

