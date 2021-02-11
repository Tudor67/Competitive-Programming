#include <bits/stdc++.h>
using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;

    if(A > B - C){
        cout << "Takahashi\n";
    }else{
        cout << "Aoki\n";
    }

    return 0;
}