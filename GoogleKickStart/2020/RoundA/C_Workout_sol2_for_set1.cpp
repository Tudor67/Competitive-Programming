#include <bits/stdc++.h>
using namespace std;

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    priority_queue<int> maxHeapOfDiffs;
    for(int i = 0; i < N - 1; ++i){
        maxHeapOfDiffs.push(a[i + 1] - a[i]);
    }
    
    int maxDiff = maxHeapOfDiffs.top();
    maxHeapOfDiffs.pop();

    maxHeapOfDiffs.push((maxDiff + 1) / 2);
    maxHeapOfDiffs.push(maxDiff / 2);

    int answer = maxHeapOfDiffs.top();
    
    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        solve(testCase, cin, cout);
    }

    return 0;
}