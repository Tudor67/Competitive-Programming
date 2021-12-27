#include <bits/stdc++.h>
using namespace std;

int countLessOrEqual(vector<int>& v, const int& THRESHOLD){
    int count = 0;
    for(int val: v){
        if(val <= THRESHOLD){
            count += 1;
        }
    }
    return count;
}

int main(){
    ifstream cin("sdo.in");
    ofstream cout("sdo.out");

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    int minVal = v[0];
    int maxVal = v[0];
    for(int val: v){
        minVal = min(minVal, val);
        maxVal = max(maxVal, val);
    }

    int l = minVal;
    int r = maxVal;
    while(l != r){
        int mid = (l + r) / 2;
        if(countLessOrEqual(v, mid) < k){
            l = mid + 1;
        }else{
            r = mid;
        }
    }

    cout << r;

    cin.close();
    cout.close();
    return 0;
}