#include <iostream>
using namespace std;
#include "HeapSort.h"
#include <stdlib.h>

int main()
{
    cout << "Heap Sort" << endl;

    HeapSortArray sortArr;    //Get a instance

    //生成测试随机数
    int _random = 0;
    int i = 0;
    for(; i < 100; i++) {
        _random = 1 + rand() % 100;
        sortArr.Add(_random);
        cout<<"raw"<<i<<":"<<_random<<endl;
    }

    //排序
    sortArr.Sort();
    //打印排序结果
    sortArr.Printf();

    return 0;
}
