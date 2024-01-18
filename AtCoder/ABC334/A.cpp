#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int B, G;
    cin >> B >> G;

    if(B > G){
        cout << "Bat";
    }else{
        cout << "Glove";
    }

    return 0;
}