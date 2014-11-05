#include <iostream>
using namespace std;
#include "HeapSort.h"
#include <stdlib.h>

int main()
{
    cout << "Heap Sort" << endl;
    HeapSortArray sortArr;    //Get a instance

    int _random = 0;
    int i = 0;
    for(; i < 1000; i++) {
        _random = 1 + rand() % 100;
        sortArr.Add(_random);
    }
    int j = 0;
    int item = 0;
    for(; j < sortArr.Length(); j++) {
        item = sortArr.Get(i);
        cout<<"num"<<i<<":"<<item<<endl;
    }

    return 0;
}
