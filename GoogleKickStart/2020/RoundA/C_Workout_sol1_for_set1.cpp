#include <bits/stdc++.h>
using namespace std;

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<int> diffs(N - 1);
    for(int i = 0; i < N - 1; ++i){
        diffs[i] = a[i + 1] - a[i];
    }

    const int IDX_OF_MAX_DIFF = max_element(diffs.begin(), diffs.end()) - diffs.begin();
    const int MAX_DIFF = diffs[IDX_OF_MAX_DIFF];

    diffs[IDX_OF_MAX_DIFF] = diffs.back();
    diffs.pop_back();
    
    diffs.push_back(MAX_DIFF / 2);
    diffs.push_back((MAX_DIFF + 1) / 2);
    
    int answer = *max_element(diffs.begin(), diffs.end());
    
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