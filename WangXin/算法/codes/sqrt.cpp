#include <bits/stdc++.h>
using namespace std;

int main() {

    double n;
    cin >> n;
    double l = 0, r = abs(n) + 1;
    double eps = 1e-8;
    while (r - l > eps){
        double mid = (l + r) / 2;
        if(mid * mid * mid > abs(n)) r = mid;
        else l = mid;
    }

    printf("%.6f\n",  n > 0 ? l : -l);
}

