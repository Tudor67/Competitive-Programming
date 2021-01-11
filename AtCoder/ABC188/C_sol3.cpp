#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int total = (1 << n);
    vector<int> a(total + 1);
    for(int i = 1; i <= total; ++i){
        cin >> a[i];
    }

    int posOfMax1 = max_element(a.begin() + 1, a.begin() + total / 2 + 1) - a.begin();
    int posOfMax2 = max_element(a.begin() + total / 2 + 1, a.end()) - a.begin();

    if(a[posOfMax1] < a[posOfMax2]){
        cout << posOfMax1;
    }else{
        cout << posOfMax2;
    }

    return 0;
}