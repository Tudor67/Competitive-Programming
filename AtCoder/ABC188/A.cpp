#include <bits/stdc++.h>
using namespace std;

int main(){
    int x, y;
    cin >> x >> y;

    if(min(x, y) + 3 > max(x, y)){
        cout << "Yes";
    }else{
        cout << "No";
    }

    return 0;
}