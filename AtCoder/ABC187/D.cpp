#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<long long> gain(n);
    long long a, b;
    long long diff = 0;
    for(int i = 0; i < n; ++i){
        cin >> a >> b;
        diff -= a;
        gain[i] = 2 * a + b;
    }

    sort(gain.rbegin(), gain.rend());

    int answer = 0;
    for(int i = 0; i < n; ++i){
        diff += gain[i];
        if(diff > 0){
            answer = i + 1;
            break;
        }
    }

    cout << answer;

    return 0;
}