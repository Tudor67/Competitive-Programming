#include <bits/stdc++.h>
using namespace std;

void solve(const int& TEST_CASE, istream& cin, ostream& cout){
    int N, B;
    cin >> N >> B;

    vector<int> a(N);
    for(int i = 0; i < N; ++i){
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int answer = 0;
    int prefSum = 0;
    for(int i = 0; i < N; ++i){
        prefSum += a[i];
        if(prefSum <= B){
            answer = i + 1;
        }else{
            break;
        }
    }

    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        solve(testCase, cin, cout);
    }

    return 0;
}