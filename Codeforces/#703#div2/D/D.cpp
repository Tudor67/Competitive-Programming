#include <bits/stdc++.h>
using namespace std;

bool isValid(const int& MEDIAN, const vector<int>& A, const int& N, const int& K){
    static vector<int> prefSum;
    prefSum.resize(max((int)prefSum.size(), N));

    bool isOk = false;
    int prevMinValidPrefSum = 0;
    for(int i = 0; i < N; ++i){
        if(i >= K){
            prevMinValidPrefSum = min(prefSum[i - K], prevMinValidPrefSum);
        }
        
        prefSum[i] = (i == 0 ? 0 : prefSum[i - 1]);
        if(A[i] < MEDIAN){
            prefSum[i] -= 1;
        }else{
            prefSum[i] += 1;
        }

        if(i >= K - 1 && prevMinValidPrefSum < prefSum[i]){
            isOk = true;
            break;
        }
    }

    return isOk;
}

void solve(istream& cin, ostream& cout){
    int N, K;
    cin >> N >> K;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    int l = 1;
    int r = *max_element(A.begin(), A.end());
    while(l != r){
        int mid = (l + r + 1) / 2;
        if(isValid(mid, A, N, K)){
            l = mid;
        }else{
            r = mid - 1;
        }
    }

    cout << r;
}

int main(int argc, char** argv){
    #ifndef ONLINE_JUDGE
        ifstream cin(string(argv[1]) + ".in");
        ofstream cout(string(argv[1]) + ".out");
    #endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve(cin, cout);

    return 0;
}