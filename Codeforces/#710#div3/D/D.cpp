#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    map<int, int> count;
    for(int i = 1; i <= N; ++i){
        int elem;
        cin >> elem;
        count[elem] += 1;
    }

    set<pair<int, int>> countElemSet;
    for(const pair<int, int>& P: count){
        int elem = P.first;
        countElemSet.insert({count[elem], elem});
    }

    int answer = N;
    while(countElemSet.size() >= 2){
        answer -= 2;

        auto it2 = prev(countElemSet.end());
        auto it1 = prev(it2);

        int elem2 = it2->second;
        int elem1 = it1->second;

        countElemSet.erase(it2);
        countElemSet.erase(it1);

        count[elem2] -= 1;
        count[elem1] -= 1;

        if(count[elem2] >= 1){
            countElemSet.insert({count[elem2], elem2});
        }
        if(count[elem1] >= 1){
            countElemSet.insert({count[elem1], elem1});
        }
    }

    cout << answer << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}