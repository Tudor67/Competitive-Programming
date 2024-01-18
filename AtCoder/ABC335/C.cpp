#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    
    vector<pair<int, int>> res;
    vector<pair<int, int>> xy(N);
    for(int i = 0; i < N; ++i){
        xy[i] = {i + 1, 0};
    }
    reverse(xy.begin(), xy.end());

    int x = 1;
    int y = 0;
    for(int i = 1; i <= Q; ++i){
        int opInt;
        cin >> opInt;

        if(opInt == 1){
            string opStr;
            cin >> opStr;
            if(opStr[0] == 'R'){
                x += 1;
            }else if(opStr[0] == 'L'){
                x -= 1;
            }else if(opStr[0] == 'U'){
                y += 1;
            }else if(opStr[0] == 'D'){
                y -= 1;
            }

            xy.push_back({x, y});
        }else{
            int idx;
            cin >> idx;

            int size = xy.size();
            res.push_back(xy[size - idx]);
        }
    }

    for(const pair<int, int>& P: res){
        cout << P.first << " " << P.second << "\n";
    }

    return 0;
}