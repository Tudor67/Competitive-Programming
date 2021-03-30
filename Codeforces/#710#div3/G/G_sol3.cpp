#include <bits/stdc++.h>
using namespace std;

int countUniqueChars(const string& S){
    vector<bool> exists(26, false);
    for(char c: S){
        exists[c - 'a'] = true;
    }
    return count(exists.begin(), exists.end(), true);
}

void solve(istream& cin, ostream& cout){
    string s;
    cin >> s;

    const int N = s.length();
    const int UNIQUE_CHARS = countUniqueChars(s);

    vector<vector<int>> count(N, vector<int>(26, 0));
    count[N - 1][s[N - 1] - 'a'] = 1;
    for(int i = N - 2; i >= 0; --i){
        count[i] = count[i + 1];
        count[i][s[i] - 'a'] += 1;
    }

    string answer;
    int prevPos = 0;
    vector<bool> isAdded(26, false);
    for(int iteration = 1; iteration <= UNIQUE_CHARS; ++iteration){
        for(char candidate = 'z'; candidate >= 'a'; --candidate){
            if(!isAdded[candidate - 'a']){
                int candidatePos = prevPos;
                for(; candidatePos < N && s[candidatePos] != candidate; ++candidatePos);

                int remChars = 0;
                for(char c = 'a'; c <= 'z'; ++c){
                    if(!isAdded[c - 'a'] && candidatePos < N && count[candidatePos][c - 'a'] >= 1){
                        remChars += 1;
                    }
                }

                if(remChars + (int)answer.length() == UNIQUE_CHARS){
                    answer += candidate;
                    isAdded[candidate - 'a'] = true;
                    prevPos = candidatePos;
                    break;
                }
            }
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