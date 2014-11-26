#include <iostream>

using namespace std;
int new_binary_search(int a[], int p, int r, int x);
int new_binary_search1(int a[], int p, int r, int x);
int main()
{
    cout << "BinarySearch" << endl;
    int a[] = {15, 16, 19, 20, 25, 27, 28, 29, 0, 1, 3, 4, 5, 7, 10, 14};
    int i;
    for(i = 0; i < sizeof(a)/sizeof(int); i++) {
        int res = new_binary_search1(a, 0, 15, a[i]);
        cout<< res << endl;
    }

    int out = new_binary_search1(a, 0, 11, 200);
    cout<< "out of range:" << out << endl;;
    return 0;
}

int new_binary_search1(int a[], int p, int r, int x) {
    if(p <= r) {
        int mid = p + (r - p) / 2;
        if(a[mid] >= a[p]) {
            if(x == a[mid]) {
                return mid;
            }
            else if(x >= a[p] && x < a[mid]) {
                return new_binary_search1(a, p, mid - 1, x);
            }
            else {
                return new_binary_search1(a, mid + 1, r, x);
            }
        }
        else {
            if(x == a[mid]) {
                return mid;
            }
            else if(x > a[mid] && x <= a[r]) {
                return new_binary_search1(a, mid + 1, r, x);
            }
            else {
                return new_binary_search1(a, p, mid - 1, x);
            }
        }
    }
    else {
        return -1;
    }
}

//从a[]中查找x
int new_binary_search(int a[], int p, int r, int x) {
    while(p <= r) {
        int mid = p + (r - p) / 2;
        if(a[mid] >= a[p]) {                 //如果落在左半部分
            if(x == a[mid]) {
                return mid;
            }
            else if(x >= a[p] && x < a[mid]) {
                r = mid - 1;
            }
            else {
                p = mid + 1;
            }
        }
        else {                               //如果落在右半部分
            if(x == a[mid]) {
                return mid;
            }
            else if(x > a[mid] && x <= a[r]) {
                p = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

}
