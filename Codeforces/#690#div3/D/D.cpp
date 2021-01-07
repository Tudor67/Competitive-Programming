#include <bits/stdc++.h>
using namespace std;

void solve(istream& cin, ostream& cout){
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    int minSteps = n - 1;
    const int TOTAL_SUM = accumulate(a.begin(), a.end(), 0);
    for(int step = 0; step <= n - 1; ++step){
        const int EXPECTED_PARTS = n - step;
        const int EXPECTED_PART_SUM = TOTAL_SUM / EXPECTED_PARTS;
        if(TOTAL_SUM % EXPECTED_PARTS == 0){
            int parts = 0;
            int partSum = 0;
            for(int i = 0; i < n; ++i){
                partSum += a[i];
                if(partSum == EXPECTED_PART_SUM){
                    parts += 1;
                    partSum = 0;
                }else if(partSum > EXPECTED_PART_SUM){
                    parts = -1;
                    partSum = -1;
                    break;
                }
            }
            if(parts == EXPECTED_PARTS && partSum == 0){
                minSteps = step;
                break;
            }
        }
    }

    cout << minSteps << "\n";
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif
    
    int tests;
    cin >> tests;

    while(tests > 0){
        solve(cin, cout);
        tests -= 1;
    }

    return 0;
}