#include <bits/stdc++.h>
using namespace std;

int countUniqueChars(const string& S){
    vector<bool> exists(128, false);
    for(char c: S){
        exists[c] = true;
    }
    return count(exists.begin(), exists.end(), true);
}

void solve(istream& cin, ostream& cout){
    string s;
    cin >> s;

    const int N = s.length();
    const int UNIQUE_CHARS = countUniqueChars(s);

    string answer;
    int prevPos = 0;
    vector<bool> isAdded(128, false);
    vector<bool> exists(128);
    for(int iteration = 1; iteration <= UNIQUE_CHARS; ++iteration){
        for(char candidate = 'z'; candidate >= 'a'; --candidate){
            if(!isAdded[candidate]){
                int pos = prevPos;
                for(; pos < N && s[pos] != candidate; ++pos);
                int candidatePos = pos;

                fill(exists.begin() + 'a', exists.end(), false);
                for(; pos < N; ++pos){
                    exists[s[pos]] = true;
                }

                int remChars = 0;
                for(char c = 'a'; c <= 'z'; ++c){
                    if(!isAdded[c] && exists[c]){
                        remChars += 1;
                    }
                }

                if(remChars + (int)answer.length() == UNIQUE_CHARS){
                    answer += candidate;
                    isAdded[candidate] = true;
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