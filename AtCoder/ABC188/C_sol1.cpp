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

    vector<int> b = a;
    for(int step = 1; step <= n - 1; ++step){
        for(int i = 0; i < a.size(); i += 2){
            b[i / 2] = max(a[i], a[i + 1]);
        }
        b.resize(a.size() / 2);
        a.resize(a.size() / 2);
        copy(b.begin(), b.end(), a.begin());
    }

    cout << pos[min(b[0], b[1])];

    return 0;
}