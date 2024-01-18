#include <bits/stdc++.h>
using namespace std;

bool areAdjacent(char a, char b){
    int diff = max(a, b) - min(a, b);
    return (diff == 1 || 5 - diff == 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    string T;

    cin >> S;
    cin >> T;

    if(areAdjacent(S[0], S[1]) == areAdjacent(T[0], T[1])){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}