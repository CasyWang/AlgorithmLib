#include <iostream>
using namespace std;
#include "HeapSort.h"
#include <stdlib.h>

int main()
{
    cout << "Heap Sort" << endl;

    HeapSortArray sortArr;    //Get a instance

    //���ɲ��������
    int _random = 0;
    int i = 0;
    for(; i < 100; i++) {
        _random = 1 + rand() % 100;
        sortArr.Add(_random);
        cout<<"raw"<<i<<":"<<_random<<endl;
    }

    //����
    sortArr.Sort();
    //��ӡ������
    sortArr.Printf();

    return 0;
}
