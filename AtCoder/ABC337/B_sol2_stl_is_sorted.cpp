#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    if(is_sorted(S.begin(), S.end())){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}