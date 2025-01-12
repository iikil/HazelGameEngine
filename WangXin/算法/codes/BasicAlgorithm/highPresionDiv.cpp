#include "bits/stdc++.h"
using namespace std;

vector<int> div(vector<int> A, int B, int &r){

    vector<int> C;
    r = 0;
    for(int i = A.size() - 1; i >= 0; i--){
        r = r * 10 + A[i];
        C.push_back(r / B);
        r %= B;
    }
    reverse(C.begin(), C.end());
    while (C.back() == 0 && C.size() > 1) C.pop_back();
    return C;

}


int main() {

    string a;
    int B;
    cin >> a >> B;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');

    vector<int> C;
    int r;
    C = div(A, B, r);

    for(int i = C.size() - 1; i >= 0; i--) cout << C[i];
    cout << "\n" << r;

    return 0;
}
