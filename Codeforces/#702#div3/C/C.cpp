#include <bits/stdc++.h>
using namespace std;

const long long MAX_NUM = 1e12;
set<long long> cubes;

void precompute(){
    for(long long i = 1; i * i * i <= MAX_NUM; ++i){
        cubes.insert(i * i * i);
    }
}

void solve(istream& cin, ostream& cout){
    long long x;
    cin >> x;

    bool isValid = false;
    for(long long a: cubes){
        if(a >= x){
            break;
        }
        if(cubes.count(x - a)){
            isValid = true;
            break;
        }
    }

    if(isValid){
        cout << "YES" << "\n";
    }else{
        cout << "NO" << "\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int tests;
    cin >> tests;

    precompute();

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}