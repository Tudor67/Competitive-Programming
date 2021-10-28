#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 26;
const int INF = 1e8;

class Solution{
private:
    static int computeCost(const string& S, const char& TARGET_CHAR, vector<vector<int>>& cost){
        int currentCost = 0;
        for(char c: S){
            currentCost += cost[c - 'A'][TARGET_CHAR - 'A'];
            if(currentCost >= INF){
                break;
            }
        }
        return currentCost;
    }

public:
    static void solve(const int& TEST_CASE, istream& cin, ostream& cout){
        string s;
        cin >> s;

        int k;
        cin >> k;

        vector<vector<int>> cost(ALPHABET_SIZE, vector<int>(ALPHABET_SIZE, INF));
        string r;
        for(int i = 0; i < k; ++i){
            cin >> r;
            cost[r[0] - 'A'][r[1] - 'A'] = 1;
        }

        for(int i = 0; i < ALPHABET_SIZE; ++i){
            cost[i][i] = 0;
        }

        for(int k = 0; k < ALPHABET_SIZE; ++k){
            for(int i = 0; i < ALPHABET_SIZE; ++i){
                for(int j = 0; j < ALPHABET_SIZE; ++j){
                    if(cost[i][k] + cost[k][j] < cost[i][j]){
                        cost[i][j] = cost[i][k] + cost[k][j];
                    }
                }
            }
        }

        int minCost = INF;
        for(char c = 'A'; c <= 'Z'; ++c){
            int currentCost = computeCost(s, c, cost);
            minCost = min(minCost, currentCost);
        }

        if(minCost >= INF){
            minCost = -1;
        }

        cout << "Case #" << TEST_CASE << ": " << minCost << "\n";
    }
};

int main(){
    ifstream cin("consistency_chapter_2_input.txt");
    ofstream cout("consistency_chapter_2_output.txt");
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        Solution::solve(testCase, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}