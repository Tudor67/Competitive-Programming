#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int xSum = 0;
    int ySum = 0;
    for(int i = 0; i < N; ++i){
        int x, y;
        cin >> x >> y;
        xSum += x;
        ySum += y;
    }

    if(xSum > ySum){
        cout << "Takahashi";
    }else if(xSum < ySum){
        cout << "Aoki";
    }else{
        cout << "Draw";
    }

    return 0;
}