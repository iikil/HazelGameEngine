#include "bits/stdc++.h"

using namespace std;

vector<int> mul(vector<int> &A, int b){
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size() || t; i++){
        if(i < A.size()) t += A[i] * b;
        C.push_back(t % 10);
        t /= 10;
    }
    while(C.back() == 0 && C.size() > 1) C.pop_back();
    return C;

}


int main() {

    string a;
    int B;
    cin >> a >> B;

    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    vector<int> C = mul(A, B);

    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];


    return 0;
}