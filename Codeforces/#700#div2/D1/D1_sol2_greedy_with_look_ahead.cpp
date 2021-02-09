#include <bits/stdc++.h>
using namespace std;

int seg(vector<int>& a, vector<int>& c){
    int segVal = 0;
    for(int i = 1; i < (int)c.size(); ++i){
        segVal += (a[c[i - 1]] != a[c[i]]);
    }
    return segVal;
}

void solve(istream& cin, ostream& cout){
    int N;
    cin >> N;

    vector<int> a(N + 1);
    for(int i = 1; i <= N; ++i){
        cin >> a[i];
    }

    vector<int> posOf(N + 1, INT_MAX);
    vector<int> nextPos(N + 1);
    for(int i = N; i >= 0; --i){
        nextPos[i] = posOf[a[i]];
        posOf[a[i]] = i;
    }

    vector<int> c0 = {0};
    vector<int> c1 = {0};
    for(int i = 1; i <= N; ++i){
        if(a[i] == a[c0.back()]){
            c1.push_back(i);
        }else if(a[i] == a[c1.back()]){
            c0.push_back(i);
        }else{
            if(nextPos[c0.back()] < nextPos[c1.back()]){
                c0.push_back(i);
            }else{
                c1.push_back(i);
            }
        }
    }

    cout << (seg(a, c0) + seg(a, c1));
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