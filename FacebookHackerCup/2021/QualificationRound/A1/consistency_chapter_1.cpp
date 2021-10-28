#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static bool isVowel(char c){
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }

    static int computeCost(const string& S, const char& TARGET_CHAR){
        int cost = 0;
        for(char c: S){
            if(c != TARGET_CHAR){
                if((isVowel(c) && isVowel(TARGET_CHAR)) ||
                   (!isVowel(c) && !isVowel(TARGET_CHAR))){
                    cost += 2;
                }else{
                    cost += 1;
                }
            }
        }
        return cost;
    }

public:
    static void solve(const int& TEST_CASE, istream& cin, ostream& cout){
        string s;
        cin >> s;

        int minCost = INT_MAX;
        for(char c = 'A'; c <= 'Z'; ++c){
            int cost = computeCost(s, c);
            minCost = min(minCost, cost);
        }

        cout << "Case #" << TEST_CASE << ": " << minCost << "\n";
    }
};

int main(){
    ifstream cin("consistency_chapter_1_input.txt");
    ofstream cout("consistency_chapter_1_output.txt");
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        Solution::solve(testCase, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}