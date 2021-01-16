#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int dy = abs(y[j] - y[i]);
            int dx = abs(x[j] - x[i]);
            if(dy <= dx){
                count += 1;
            }
        }
    }

    cout << count;

    return 0;
}