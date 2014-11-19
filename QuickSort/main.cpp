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
    //������ɲ�������
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

/** ������������λ��
  @param a ������Ԫ��a�ĵ�ַ
  @param b ������Ԫ��b�ĵ�ַ
  @return none
*/
void Swap(int* a, int* b) {
    //���������ַ��ͬ,��������
    if(a == b) return;

    int mid = *a;
    *a = *b;
    *b = mid;
}

/** ��������,��ԭַ
  @param a ����������.
  @param p ������߽�
  @param r �����ұ߽�
  @return None
*/
void quickSort(int a[], int p, int r) {
    if(p < r) {                          //�ݹ�ѭ����ֹ����, p = r,Ҳ��������ֻʣ��һ��Ԫ�ص�ʱ��
        int mid = qsPartition(a, p, r);  //�ȷָ�
        quickSort(a, p, mid - 1);        //��mid���ĵݹ��������
        quickSort(a, mid + 1, r);        //��mid�Ҳ�ĵݹ��������
    }
}


/** �ָ�,���������������Ϊ��������,[p,i] [i+1] [i+2,r].
  @param a ����������.
  @param p ������߽�
  @param r �����ұ߽�
  @return �м�ֽ�Ԫ��i+1�±�
*/
int qsPartition(int a[], int p, int r) {
    int key = a[r];    //�Ƚ�Ȩֵ
    int i = p - 1;     //��¼����������С���Ƶı߽�
    int j = p;
    for (; j < r; j++) {
        if(a[j] <= key) {
            i++;
            Swap(&a[i], &a[j]);    //���ҵ���Сֵ���С���紦���Ǹ���ֵ����
        }
    }
    Swap(&a[i + 1], &a[r]);
    return i+1;
}


