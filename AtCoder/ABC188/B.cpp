#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<int> b(n);
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    int innerProduct = inner_product(a.begin(), a.end(), b.begin(), 0);

    if(innerProduct == 0){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}