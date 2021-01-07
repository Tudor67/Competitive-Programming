#include <bits/stdc++.h>
using namespace std;

bool sortIncX(const pair<int, int>& LHS, const pair<int, int>& RHS){
    return (LHS.first < RHS.first);
}

bool sortIncY(const pair<int, int>& LHS, const pair<int, int>& RHS){
    return (LHS.second < RHS.second);
}

bool lowerBoundY(const pair<int, int>& IT, const int& Y){
    return (IT.second < Y);
}

bool upperBoundX(const int& X, const pair<int, int>& IT){
    return (X < IT.first);
}

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; ++i){
        cin >> segments[i].first >> segments[i].second;
    }

    vector<pair<int, int>> segmentsIncX = segments;
    vector<pair<int, int>> segmentsIncY = segments;

    sort(segmentsIncX.begin(), segmentsIncX.end(), sortIncX);
    sort(segmentsIncY.begin(), segmentsIncY.end(), sortIncY);

    int answer = n - 1;
    for(const pair<int, int>& SEGMENT: segments){
        int startPos = SEGMENT.first;
        int endPos = SEGMENT.second;
        int p1 = lower_bound(segmentsIncY.begin(), segmentsIncY.end(), startPos, lowerBoundY) - segmentsIncY.begin();
        int p2 = upper_bound(segmentsIncX.begin(), segmentsIncX.end(), endPos, upperBoundX) - segmentsIncX.begin();
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