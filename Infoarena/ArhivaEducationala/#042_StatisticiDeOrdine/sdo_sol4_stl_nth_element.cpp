#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("sdo.in");
    ofstream cout("sdo.out");

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    nth_element(v.begin(), v.begin() + k - 1, v.end());

    cout << v[k - 1];

    cin.close();
    cout.close();
    return 0;
}