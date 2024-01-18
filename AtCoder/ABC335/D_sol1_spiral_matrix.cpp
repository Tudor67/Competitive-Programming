#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));
    int topRow = 0;
    int bottomRow = N - 1;
    int leftCol = 0;
    int rightCol = N - 1;
    int cellID = 0;

    while(cellID < N * N){
        for(int col = leftCol; cellID < N * N && col <= rightCol; ++col){
            a[topRow][col] = ++cellID;
        }
        topRow += 1;

        for(int row = topRow; cellID < N * N && row <= bottomRow; ++row){
            a[row][rightCol] = ++cellID;
        }
        rightCol -= 1;

        for(int col = rightCol; cellID < N * N && col >= leftCol; --col){
            a[bottomRow][col] = ++cellID;
        }
        bottomRow -= 1;

        for(int row = bottomRow; cellID < N * N && row >= topRow; --row){
            a[row][leftCol] = ++cellID;
        }
        leftCol += 1;
    }

    for(int row = 0; row < N; ++row){
        for(int col = 0; col < N; ++col){
            if(row == N / 2 && col == N / 2){
                cout << "T ";
            }else{
                cout << a[row][col] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}