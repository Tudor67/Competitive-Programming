#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    static void solve(const int& TEST_CASE, istream& cin, ostream& cout){
        int n;
        cin >> n;

        vector<string> board(n);
        for(int row = 0; row < n; ++row){
            cin >> board[row];
        }

        vector<int> xRowCount(n);
        vector<int> xColCount(n);
        vector<int> oRowCount(n);
        vector<int> oColCount(n);
        for(int row = 0; row < n; ++row){
            for(int col = 0; col < n; ++col){
                if(board[row][col] == 'X'){
                    xRowCount[row] += 1;
                    xColCount[col] += 1;
                }else if(board[row][col] == 'O'){
                    oRowCount[row] += 1;
                    oColCount[col] += 1;
                }
            }
        }

        const int INF = 1e9;
        int minAdditionalX = INF;
        for(int row = 0; row < n; ++row){
            if(oRowCount[row] == 0){
                int additionalX = n - xRowCount[row];
                minAdditionalX = min(minAdditionalX, additionalX);
            }
        }

        for(int col = 0; col < n; ++col){
            if(oColCount[col] == 0){
                int additionalX = n - xColCount[col];
                minAdditionalX = min(minAdditionalX, additionalX);
            }
        }

        string answer = "Impossible";
        if(minAdditionalX != INF){
            set<vector<pair<int, int>>> additionalXSet;
            for(int row = 0; row < n; ++row){
                int additionalX = n - xRowCount[row];
                if(oRowCount[row] == 0 && additionalX == minAdditionalX){
                    vector<pair<int, int>> coordinates;
                    for(int col = 0; col < n; ++col){
                        if(board[row][col] == '.'){
                            coordinates.emplace_back(row, col);
                        }
                    }
                    additionalXSet.insert(coordinates);
                }
            }

            for(int col = 0; col < n; ++col){
                int additionalX = n - xColCount[col];
                if(oColCount[col] == 0 && additionalX == minAdditionalX){
                    vector<pair<int, int>> coordinates;
                    for(int row = 0; row < n; ++row){
                        if(board[row][col] == '.'){
                            coordinates.emplace_back(row, col);
                        }
                    }
                    additionalXSet.insert(coordinates);
                }
            }

            answer = to_string(minAdditionalX) + " " + to_string(additionalXSet.size());
        }

        cout << "Case #" << TEST_CASE << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("xs_and_os_input.txt");
    ofstream cout("xs_and_os_output.txt");
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        Solution::solve(testCase, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}