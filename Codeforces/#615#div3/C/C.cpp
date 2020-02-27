#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

#ifdef ONLINE_JUDGE
    #include <iostream>
#else
    #include <fstream>
#endif

void solve(int n, ostream& cout){
    // O(sqrt(n))
    vector <pair<int, int>> divs;
    int x = n;
    int a[4];

    for(int d = 2; d * d <= n; ++d){
        if(x % d == 0){
            int cnt = 0;
            while(x % d == 0){
                x /= d;
                ++cnt;
            }

            divs.push_back(make_pair(d, cnt));
        }
    }

    if(x > 1){
        divs.push_back(make_pair(x, 1));
    }

    bool ok = 0;
    int exp1, exp2;

    if(divs.size() >= 3){
        ok = 1;
        exp1 = divs[0].second;
        exp2 = divs[1].second;
        a[1] = pow(divs[0].first, exp1);
        a[2] = pow(divs[1].first, exp2);
        a[3] = n / (a[1] * a[2]);
    }else if(divs.size() == 2){
        exp1 = divs[0].second;
        exp2 = divs[1].second;
        if(exp1 + exp2 >= 4){
            ok = 1;
            a[1] = pow(divs[0].first, 1);
            a[2] = pow(divs[1].first, 1);
            a[3] = n / (a[1] * a[2]);
        }
    }else if(divs.size() == 1){
        exp1 = divs[0].second;
        if(exp1 >= 6){
            ok = 1;
            a[1] = pow(divs[0].first, 1);
            a[2] = pow(divs[0].first, 2);
            a[3] = n / (a[1] * a[2]);
        }
    }

    if(ok){
        cout << "YES\n";
        cout << a[1] << " " << a[2] << " " << a[3] << "\n";
    }else{
        cout << "NO\n";
    }
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    int t, n;
    cin >> t;
 
    for(; t > 0; --t){
        cin >> n;
        solve(n, cout);
    }

    return 0;
}