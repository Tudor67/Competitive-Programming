#include <bits/stdc++.h>
using namespace std;

const string EVEN_DIGITS = "02468";

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    N -= 1;

    string s;
    while(N > 0){
        s.push_back(EVEN_DIGITS[N % 5]);
        N /= 5;
    }

    if(s.empty()){
        s += "0";
    }

    reverse(s.begin(), s.end());

    cout << s;

    return 0;
}