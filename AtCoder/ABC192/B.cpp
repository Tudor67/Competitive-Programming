#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    bool isValid = true;
    for(int i = 0; i < (int)s.length(); ++i){
        if((i % 2 == 0 && isupper(s[i])) ||
           (i % 2 == 1 && islower(s[i]))){
            isValid = false;
        }
    }

    if(isValid){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}