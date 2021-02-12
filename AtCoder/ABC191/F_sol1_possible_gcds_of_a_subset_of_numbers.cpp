#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; ++i){
        cin >> A[i];
    }

    const int MIN_ELEM = *min_element(A.begin(), A.end());
    unordered_map<int, int> memo;
    for(int i = 0; i < N; ++i){
        for(int d = 1; d * d <= A[i]; ++d){
            if(A[i] % d == 0){
                for(int divisor: set<int>{d, A[i] / d}){
                    if(divisor <= MIN_ELEM){
                        memo[divisor] = (memo.count(divisor) ? __gcd(memo[divisor], A[i]) : A[i]);
                    }
                }
            }
        }
    }

    int answer = 0;
    for(const pair<int, int>& P: memo){
        answer += (P.first == P.second);
    }

    cout << answer;

    return 0;
}