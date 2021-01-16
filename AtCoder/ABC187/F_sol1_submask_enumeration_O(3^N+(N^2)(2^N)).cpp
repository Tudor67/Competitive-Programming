#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n + 1, vector<bool>(n + 1, false));
    for(int i = 1; i <= m; ++i){
        int x, y;
        cin >> x >> y;
        a[x][y] = true;
        a[y][x] = true;
    }

    const int FULL_MASK = (1 << n) - 1;
    vector<bool> isComplete(FULL_MASK + 1, true);
    for(int mask = 0; mask <= FULL_MASK; ++mask){
        vector<int> nodes;
        for(int bit = 0; bit < n; ++bit){
            if((mask >> bit) & 1){
                nodes.push_back(bit + 1);
            }
        }
        for(int i = 0; i < (int)nodes.size(); ++i){
            for(int j = i + 1; j < (int)nodes.size(); ++j){
                if(!a[nodes[i]][nodes[j]]){
                    isComplete[mask] = false;
                    break;
                }
            }
        }
    }

    const int INF = n + 5;
    vector<int> minCC(FULL_MASK + 1, INF);
    for(int mask = 0; mask <= FULL_MASK; ++mask){
        if(isComplete[mask]){
            minCC[mask] = 1;
        }
    }

    for(int mask = 1; mask <= FULL_MASK; ++mask){
        for(int submask = mask; submask >= 1; submask = (submask - 1) & mask){
            minCC[mask] = min(minCC[submask] + minCC[submask ^ mask], minCC[mask]);
        }
    }

    cout << minCC[FULL_MASK];
    
    return 0;
}