#ifndef HEAPSORT_H
#define HEAPSORT_H
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
using namespace std;

#include <vector>

class HeapSortArray
{
    public:
        HeapSortArray();
        void Sort(void);      /* ���� */
        virtual ~HeapSortArray();
        void Add(int a);                 /* ����Ԫ�� */
        int Get(int index);              /* ��ȡindexλ�õ�Ԫ�� */
        int Length(void);                /* ��ȡArray�е�Ԫ�ظ��� */
    protected:
    private:
        vector<int> _sortArray;
        void maxHeapify(vector<int> a, int root, int len);    /* ά���������� */
        void buildMaxHeap(vector<int> a);    /* �������� */
        void _swap(int* a, int* b);            /* ���õ��� */
};

#endif // HEAPSORT_H