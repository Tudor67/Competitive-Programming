#include <bits/stdc++.h>
using namespace std;

int main(){
    int V, T, S, D;
    cin >> V >> T >> S >> D;

    if(V * T <= D && D <= V * S){
        cout << "No";
    }else{
        cout << "Yes";
    }

    return 0;
}