#include "bits/stdc++.h"

using namespace std;

const int N = 100010;
int q[N];

int main() {
    int n, s;
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> q[i];
    }
    while (s--){
        int x;
        cin >> x;
        int l = 0, r = n - 1;
        while(l < r){
            int mid = l + r >> 1;
            if(q[mid] >= x) r = mid;
            else l = mid + 1;
        }
//        if(q[l] != x){
//            cout << "-1 -1" << endl;
//            continue;
//        }
        cout << l << " ";
        l = 0, r = n - 1;
        while (l < r){
            int mid = l + r + 1 >> 1;
            if(q[mid] <= x) l = mid;
            else r = mid - 1;
        }
       cout << r << endl;


    }

    return 0;
}
