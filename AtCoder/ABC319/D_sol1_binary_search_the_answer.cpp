#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<int>& a, const int M, const long long MAX_WIDTH){
    const int N = a.size();

    int rows = 1;
    long long w = a[0];
    for(int i = 1; i < N && rows <= M; ++i){
        if(w + 1 + a[i] <= MAX_WIDTH){
            w += 1 + a[i];
        }else{
            rows += 1;
            w = a[i];
        }
    }

    return (rows <= M);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    long long l = *max_element(a.begin(), a.end());
    long long r = accumulate(a.begin(), a.end(), 0LL) + N;
    while(l != r){
        long long mid = (l + r) / 2;
        if(isValid(a, M, mid)){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    cout << r;

    return 0;
}