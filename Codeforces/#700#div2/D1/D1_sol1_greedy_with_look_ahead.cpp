#include <bits/stdc++.h>
using namespace std;

int seg(vector<int>& c){
    int segVal = 0;
    for(int i = 1; i < (int)c.size(); ++i){
        segVal += (c[i - 1] != c[i]);
    }
    return segVal;
}

int nextPosition(vector<int>& nextPositions, int currentPosition){
    while(!nextPositions.empty() && nextPositions.back() <= currentPosition){
        nextPositions.pop_back();
    }
    return (nextPositions.empty() ? INT_MAX : nextPositions.back());
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    vector<vector<int>> nextPosOf(N + 1);
    for(int i = N - 1; i >= 0; --i){
        nextPosOf[a[i]].push_back(i);
    }

    vector<int> c0 = {0};
    vector<int> c1 = {0};
    for(int i = 0; i < N; ++i){
        if(a[i] == c0.back()){
            c1.push_back(a[i]);
        }else if(a[i] == c1.back()){
            c0.push_back(a[i]);
        }else{
            int nextPosC0 = nextPosition(nextPosOf[c0.back()], i);
            int nextPosC1 = nextPosition(nextPosOf[c1.back()], i);
            if(nextPosC0 < nextPosC1){
                c0.push_back(a[i]);
            }else{
                c1.push_back(a[i]);
            }
        }
    }

    cout << (seg(c0) + seg(c1));
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(cin, cout);

    return 0;
}