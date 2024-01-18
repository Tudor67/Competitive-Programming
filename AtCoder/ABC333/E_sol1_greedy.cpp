#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> T(N);
    vector<int> X(N);
    vector<vector<int>> xToIdx(N + 1);
    for(int i = 0; i < N; ++i){
        cin >> T[i] >> X[i];
        if(T[i] == 1){
            xToIdx[X[i]].push_back(i);
        }
    }

    vector<bool> used(N, false);
    for(int i = N - 1; i >= 0; --i){
        if(T[i] == 2){
            while(!xToIdx[X[i]].empty() && i < xToIdx[X[i]].back()){
                xToIdx[X[i]].pop_back();
            }
            if(xToIdx[X[i]].empty()){
                cout << "-1";
                return 0;
            }
            used[xToIdx[X[i]].back()] = true;
            xToIdx[X[i]].pop_back();
        }
    }

    int maxPotions = 0;
    int potions = 0;
    for(int i = 0; i < N; ++i){
        if(T[i] == 1){
            if(used[i]){
                potions += 1;
            }
        }else if(T[i] == 2){
            potions -= 1;
        }
        maxPotions = max(maxPotions, potions);
    }

    cout << maxPotions << "\n";
    for(int i = 0; i < N; ++i){
        if(T[i] == 1){
            if(used[i]){
                cout << "1";
            }else{
                cout << "0";
            }
            cout << " ";
        }
    }

    return 0;
}