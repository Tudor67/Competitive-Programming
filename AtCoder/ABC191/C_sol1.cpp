#include <bits/stdc++.h>
using namespace std;

int main(){
    int ROWS, COLS;
    cin >> ROWS >> COLS;

    vector<string> s(ROWS + 1);
    for(int i = 1; i <= ROWS; ++i){
        cin >> s[i];
        s[i] = "." + s[i];
    }

    int answer = 0;
    const vector<pair<int, int>> DIRECTIONS = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for(int row = 2; row <= ROWS - 1; ++row){
        for(int col = 2; col <= COLS - 1; ++col){
            if(s[row][col] == '#'){
                for(const pair<int, int>& DIRECTION: DIRECTIONS){
                    int nextRow = row + DIRECTION.first;
                    int nextCol = col + DIRECTION.second;
                    answer += (s[nextRow][nextCol] == '.');
                }
            }
        }
    }

    for(int row = 2; row <= ROWS - 1; ++row){
        for(int col = 2; col <= COLS - 1; ++col){
            if(s[row][col - 1] == '#' && s[row][col] == '#' &&
               s[row - 1][col - 1] == '.' && s[row - 1][col] == '.'){
                answer -= 1;
            }
            if(s[row][col - 1] == '#' && s[row][col] == '#' &&
               s[row + 1][col - 1] == '.' && s[row + 1][col] == '.'){
                answer -= 1;
            }
            if(s[row - 1][col] == '#' && s[row][col] == '#' &&
               s[row - 1][col - 1] == '.' && s[row][col - 1] == '.'){
                answer -= 1;
            }
            if(s[row - 1][col] == '#' && s[row][col] == '#' &&
               s[row - 1][col + 1] == '.' && s[row][col + 1] == '.'){
                answer -= 1;
            }
        }
    }

    cout << answer;

    return 0;
}