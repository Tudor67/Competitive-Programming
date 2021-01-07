#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    vector<int> l(n);
    vector<int> r(n);
    for(int i = 0; i < n; ++i){
        cin >> segments[i].first >> segments[i].second;
        l[i] = segments[i].first;
        r[i] = segments[i].second;
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    int answer = n - 1;
    for(const pair<int, int>& SEGMENT: segments){
        int startPos = SEGMENT.first;
        int endPos = SEGMENT.second;
        int p1 = lower_bound(r.begin(), r.end(), startPos) - r.begin();
        int p2 = upper_bound(l.begin(), l.end(), endPos) - l.begin();
        int validSetSize = (n - p1) - (n - p2);
        answer = min(n - validSetSize, answer);
    }

    cout << answer << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}