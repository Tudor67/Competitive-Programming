#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        long long N, K;
        cin >> N >> K;

        vector<int> S(N);
        for(int i = 0; i < N; ++i){
            cin >> S[i];
        }

        long long minS = *min_element(S.begin(), S.end());
        long long minTime = minS;
        if(N >= 3){
            minTime = minS + minS * 2 * (N - 2);
        }

        string resStr = "YES";
        if(minTime > K){
            resStr = "NO";
        }

        cout << "Case #" << TEST_CASE_ID << ": " << resStr << "\n";
    }
};

int main(){
    ifstream cin("walk_the_line_input.txt");
    ofstream cout("walk_the_line_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}