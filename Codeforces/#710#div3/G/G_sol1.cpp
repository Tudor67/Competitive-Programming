#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    string s;
    cin >> s;

    const int N = s.length();
    vector<vector<int>> posOf(128);
    for(int i = 0; i < N; ++i){
        posOf[s[i]].push_back(i);
    }

    string answer;
    int prevBorderPos = 0;
    set<char> uniqueCharsInS(s.begin(), s.end());

    for(int iteration = 1; iteration <= (int)uniqueCharsInS.size(); ++iteration){
        
        for(set<char>::reverse_iterator rit = uniqueCharsInS.rbegin(); rit != uniqueCharsInS.rend(); ++rit){

            if(answer.find(*rit) == string::npos){

                vector<int>::iterator it = lower_bound(posOf[*rit].begin(), posOf[*rit].end(), prevBorderPos);
                int borderPos = (it == posOf[*rit].end() ? N : *it);

                bool isPossible = true;
                for(char c: uniqueCharsInS){
                    if(answer.find(c) == string::npos){
                        vector<int>::iterator it = lower_bound(posOf[c].begin(), posOf[c].end(), borderPos);
                        if(it == posOf[c].end()){
                            isPossible = false;
                            break;
                        }
                    }
                }

                if(isPossible){
                    answer += *rit;
                    prevBorderPos = borderPos;
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