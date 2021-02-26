#include <bits/stdc++.h>
using namespace std;

int minAddedSessions(const vector<int>& DIFFS, const int& MAX_POSSIBLE_DIFF){
    int minSessions = 0;
    for(int diff: DIFFS){
        minSessions += (diff + MAX_POSSIBLE_DIFF - 1) / MAX_POSSIBLE_DIFF - 1;
    }
    return minSessions;
}

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

    int l = 1;
    int r = *max_element(diffs.begin(), diffs.end());
    while(l != r){
        int mid = (l + r) / 2;
        if(minAddedSessions(diffs, mid) <= K){
            r = mid;
        }else{
            l = mid + 1;
        }
    }

    int answer = r;
    
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