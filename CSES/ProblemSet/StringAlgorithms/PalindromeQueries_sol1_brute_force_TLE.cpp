#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void processPalindromeQueries(string& s, vector<tuple<int, int, int>>& queries){
        for(const tuple<int, int, int>& QUERY: queries){
            int queryType, x, y;
            tie(queryType, x, y) = QUERY;

            if(queryType == 1){
                s[x - 1] = y;
            }else{
                bool isPalindrome = true;
                for(int i = x - 1, j = y - 1; isPalindrome && i < j; ++i, --j){
                    if(s[i] != s[j]){
                        isPalindrome = false;
                    }
                }
                if(isPalindrome){
                    cout << "YES";
                }else{
                    cout << "NO";
                }
                cout << "\n";
            }
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    vector<tuple<int, int, int>> queries(m);
    for(int i = 0; i < m; ++i){
        int queryType;
        cin >> queryType;
        if(queryType == 1){
            int pos;
            char c;
            cin >> pos >> c;
            queries[i] = {queryType, pos, (int)c};
        }else{
            int a, b;
            cin >> a >> b;
            queries[i] = {queryType, a, b};
        }
    }

    Solution().processPalindromeQueries(s, queries);

    return 0;
}