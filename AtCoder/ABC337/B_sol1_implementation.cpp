#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    const int N = S.length();
    
    bool isValid = true;
    for(int i = 1; i < N; ++i){
        if(S[i - 1] > S[i]){
            isValid = false;
            break;
        }
    }

    if(isValid){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}