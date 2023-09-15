#include <bits/stdc++.h>
using namespace std;

bool isVerticalLine(int a, int b, int c){
    int col1 = a % 3;
    int col2 = b % 3;
    int col3 = c % 3;
    return (col1 == col2 && col2 == col3);
}

bool isHorizontalLine(int a, int b, int c){
    int row1 = a / 3;
    int row2 = b / 3;
    int row3 = c / 3;
    return (row1 == row2 && row2 == row3);
}

bool isDiagonalLine(int a, int b, int c){
    static vector<int> aux;
    aux.clear();
    aux.push_back(a);
    aux.push_back(b);
    aux.push_back(c);
    sort(aux.begin(), aux.end());
    return (aux[0] == 0 && aux[1] == 4 && aux[2] == 8) ||
           (aux[0] == 2 && aux[1] == 4 && aux[2] == 6);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> vals(9);
    int idx = -1;
    for(int i = 0; i < 3; ++i){
        for(int j = 0; j < 3; ++j){
            idx += 1;
            cin >> vals[idx];
        }
    }

    int goodCount = 0;
    int totalCount = 0;

    vector<int> p(9);
    iota(p.begin(), p.end(), 0);
    
    do{
        bool isValid = true;
        for(int i = 0; isValid && i < 9; ++i){
            for(int j = i + 1; isValid && j < 9; ++j){
                if(vals[p[i]] != vals[p[j]]){
                    continue;
                }
                for(int k = j + 1; isValid && k < 9; ++k){
                    int a = p[i];
                    int b = p[j];
                    int c = p[k];
                    if(vals[a] == vals[b] && vals[b] != vals[c]){
                        if(isVerticalLine(a, b, c) || isHorizontalLine(a, b, c) || isDiagonalLine(a, b, c)){
                            isValid = false;
                        }
                    }
                }
            }
        }

        if(isValid){
            goodCount += 1;
        }
        totalCount += 1;
    }while(next_permutation(p.begin(), p.end()));

    cout << fixed << setprecision(10) << (double)(goodCount) / (double)totalCount;

    return 0;
}