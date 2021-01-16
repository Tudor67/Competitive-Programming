#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    unordered_set<string> sSet;
    string s;
    for(int i = 0; i < n; ++i){
        cin >> s;
        sSet.insert(s);
    }

    string answer = "satisfiable";
    for(string s: sSet){
        if(sSet.count("!" + s)){
            answer = s;
            break;
        }
    }

    cout << answer;

    return 0;
}