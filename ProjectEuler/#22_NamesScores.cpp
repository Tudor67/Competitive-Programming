#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ifstream cin("names.txt");

    string s;
    cin >> s;

    vector<string> names;
    for(int i = 1, j = 2; j < s.size(); ++j){
        if(s[j] == '"'){
            names.push_back(s.substr(i, j - i));
            i = j + 3;
            j = j + 2;
        }
    }

    sort(names.begin(), names.end());

    long long answer = 0;
    for(int i = 0; i < names.size(); ++i){
        int alpha_pos = i + 1;
        int alpha_val = 0;
        for(char c: names[i]){
            alpha_val += (c - 'A' + 1);
        }
        answer += (alpha_pos * alpha_val);
    }

    // 871198282
    cout << answer;

    return 0;
}