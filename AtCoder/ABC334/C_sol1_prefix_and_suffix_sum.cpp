#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;

    vector<int> f(N + 1, 2);
    for(int i = 0; i < K; ++i){
        int color;
        cin >> color;
        f[color] -= 1;
    }

    vector<int> v;
    v.reserve(2 * N - K);
    for(int i = 1; i <= N; ++i){
        v.resize(v.size() + f[i], i);
    }

    const int V_SIZE = v.size();
    int res = 0;

    if(V_SIZE <= 1){
        res = 0;
    }else if(V_SIZE % 2 == 0){
        for(int i = 1; i < V_SIZE; i += 2){
            res += (v[i] - v[i - 1]);
        }
    }else{
        vector<int> pref(V_SIZE);
        for(int i = 1; i < V_SIZE; i += 2){
            pref[i] = v[i] - v[i - 1];
            if(i >= 2){
                pref[i] += pref[i - 2];
            }
        }

        vector<int> suff(V_SIZE + 1);
        for(int i = V_SIZE - 2; i >= 0; i -= 2){
            suff[i] = v[i + 1] - v[i] + suff[i + 2];
        }

        res = min(pref[V_SIZE - 2], suff[1]);
        for(int i = 2; i + 1 < V_SIZE; ++i){
            int cost = 0;
            if(i % 2 == 0){
                cost = pref[i - 1] + suff[i + 1];
            }else{
                cost = pref[i - 2] + v[i + 1] - v[i - 1] + suff[i + 2];
            }
            res = min(res, cost);
        }
    }

    cout << res;

    return 0;
}