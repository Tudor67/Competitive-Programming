#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    while(A >= 0 && B >= 0){
        if(C == 0){
            A -= 1;
        }else{
            B -= 1;
        }
        C ^= 1;
    }

    if(B == -1){
        cout << "Takahashi\n";
    }else{
        cout << "Aoki\n";
    }

    return 0;
}