#include "bits/stdc++.h"

using namespace std;

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

void quicksort(vector<int> &a, int l, int r){
    if(l >= r) return;
    int pivot = partition(a, l, r);
    quicksort(a, l, pivot - 1);
    quicksort(a, pivot + 1, r);
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    quicksort(a, 0, a.size()-1);
    for(int i : a){
        cout << i << " ";
    }
    return 0;

}
