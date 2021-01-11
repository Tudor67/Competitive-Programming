#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int total = (1 << n);
    vector<int> a(total);
    unordered_map<int, int> pos;
    for(int i = 0; i < total; ++i){
        cin >> a[i];
        pos[a[i]] = i + 1;
    }

    for(int step = 1; step <= n - 1; ++step){
        for(int i = 0; i < a.size(); i += 2){
            a[i / 2] = max(a[i], a[i + 1]);
        }
        a.resize(a.size() / 2);
    }

    cout << pos[min(a[0], a[1])];

    return 0;
}