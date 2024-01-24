#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;

    int M = 0;
    for(int bit = 0; (1 << bit) <= N - 1; ++bit){
        if(((N - 1) >> bit) & 1){
            M = bit + 1;
        }
    }

    cout << M << endl;
    
    for(int i = 0; i < M; ++i){
        vector<int> v;
        for(int j = 0; j < N; ++j){
            if((j >> i) & 1){
                v.push_back(j + 1);
            }
        }

        cout << v.size() << " ";
        for(int elem: v){
            cout << elem << " ";
        }
        cout << endl;
    }

    string s;
    cin >> s;

    reverse(s.begin(), s.end());
    
    int res = stoi(s, nullptr, 2) + 1;

    cout << res;

    return 0;
}