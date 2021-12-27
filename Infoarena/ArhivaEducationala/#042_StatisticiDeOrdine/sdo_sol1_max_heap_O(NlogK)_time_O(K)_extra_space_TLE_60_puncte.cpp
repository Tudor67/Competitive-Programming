#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("sdo.in");
    ofstream cout("sdo.out");

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for(int i = 0; i < n; ++i){
        cin >> v[i];
    }

    priority_queue<int> maxHeap;
    for(int val: v){
        maxHeap.push(val);
        if((int)maxHeap.size() > k){
            maxHeap.pop();
        }
    }

    cout << maxHeap.top();

    cin.close();
    cout.close();
    return 0;
}