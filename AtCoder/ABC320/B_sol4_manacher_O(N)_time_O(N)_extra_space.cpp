#include <bits/stdc++.h>
using namespace std;

void manacher(string& initialStr, vector<int>& radius){
    const int N = 2 * initialStr.size() + 1;
    
    string s(N, '.');
    for(int i = 1; i < N; i += 2){
        s[i] = initialStr[i / 2];
    }

    radius.assign(N, 0);
    int a = 0;
    int b = 0;
    for(int i = 0; i < N; ++i){
        if(i <= b){
            radius[i] = min(radius[a + (b - i)], b - i + 1);
        }

        while(0 <= i - radius[i] && i + radius[i] < N &&
              s[i - radius[i]] == s[i + radius[i]]){
            radius[i] += 1;
        }

        if(i + radius[i] - 1 >= b){
            a = i - radius[i] + 1;
            b = i + radius[i] - 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    
    vector<int> radius;
    manacher(s, radius);

    int res = *max_element(radius.begin(), radius.end()) - 1;

    cout << res;

    return 0;
}