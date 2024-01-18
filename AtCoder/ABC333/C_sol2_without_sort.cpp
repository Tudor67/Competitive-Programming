#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<long long> repunits = {1};
    for(int i = 2; i <= 12; ++i){
        repunits.push_back(repunits.back() * 10 + 1);
    }

    const int R = repunits.size();
    vector<long long> v;
    for(int i = 0; i < R; ++i){
        for(int j = 0; j <= i; ++j){
            for(int k = 0; k <= j; ++k){
                v.push_back(repunits[i] + repunits[j] + repunits[k]);
            }
        }
    }

    cout << v[N - 1];

    return 0;
}