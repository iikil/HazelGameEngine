//#include "bits/stdc++.h"
#include <iostream>
#include <vector>

using namespace std;

int pos = -1;

int partition(vector<int> &a, int l, int r){
    // 将中间的数放在左边，然后按照左边继续处理
    // 这里也可以换成将一个随机数选择好之后放在左边
    swap(a[l], a[(l + r) / 2]);
    int v = a[l];
    while (l < r){
        while (l < r && a[r] >= v) r--;
        a[l] = a[r];
        while (l < r && a[l] <= v) l++;
        a[r] = a[l];
    }
    a[l] = v;
    return l;
}

void quickselect(vector<int> &a, int l, int r, int k){
    if(l >= r) return;
    int pivot = partition(a, l, r);
    if(pivot > k){
        quickselect(a, l, pivot - 1, k);
    }
    else if(pivot < k) {
        quickselect(a, pivot + 1, r, k);
    }
    else{
        pos = a[pivot];
        return;
    }
}

int main() {

    vector<int> a = {99, 44, 3, 6,  7, 8, 9, 10};
    quickselect(a, 0, a.size()-1, 5);
    cout << pos << endl;

    return 0;
}
