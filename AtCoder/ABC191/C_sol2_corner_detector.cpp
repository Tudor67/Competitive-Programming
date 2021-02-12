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
    for(int row = 1; row <= ROWS - 1; ++row){
        for(int col = 1; col <= COLS - 1; ++col){
            int dots = 0;
            dots += (s[row][col] == '.');
            dots += (s[row][col + 1] == '.');
            dots += (s[row + 1][col] == '.');
            dots += (s[row + 1][col + 1] == '.');
            answer += (dots % 2);
        }
    }

    cout << answer;

    return 0;
}