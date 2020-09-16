#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int x, y;
    int min_sum = INT_MAX;
    int max_sum = INT_MIN;
    int min_diff = INT_MAX;
    int max_diff = INT_MIN;
    for(int i = 0; i < n; ++i){
        cin >> x >> y;
        min_sum = min(x + y, min_sum);
        max_sum = max(x + y, max_sum);
        min_diff = min(x - y, min_diff);
        max_diff = max(x - y, max_diff);
    }

    cout << max(max_sum - min_sum, max_diff - min_diff);
    return 0;
}