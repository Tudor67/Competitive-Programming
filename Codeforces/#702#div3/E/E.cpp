#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<pair<int, int>> a(N + 2);
    for(int i = 1; i <= N; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin() + 1, a.begin() + N + 1);

    vector<long long> pref(N + 2);
    for(int i = 1; i <= N; ++i){
        pref[i] = pref[i - 1] + a[i].first;
    }

    vector<int> answer;
    for(int i = N; i >= 1; --i){
        if(pref[i] >= a[i + 1].first){
            answer.push_back(a[i].second);
        }else{
            break;
        }
    }

    sort(answer.begin(), answer.end());

    cout << answer.size() << "\n";
    for(int elem: answer){
        cout << elem << " ";
    }
    cout << "\n";
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