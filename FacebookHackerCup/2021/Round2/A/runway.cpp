#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        long long N, M;
        cin >> N >> M;

        vector<vector<long long>> p(2, vector<long long>(M));
        multiset<long long> activeS;
        for(int j = 0; j < M; ++j){
            cin >> p[0][j];
            activeS.insert(p[0][j]);
        }

        sort(p[0].begin(), p[0].end());
        
        long long answer = 0;

        for(int i = 1; i <= N; ++i){
            for(int j = 0; j < M; ++j){
                cin >> p[i % 2][j];
            }

            sort(p[i % 2].begin(), p[i % 2].end());

            vector<long long>& v = p[i % 2];

            long long matches = 0;
            int l = 0;
            for(int j = 0; j < M; ++j){
                long long target = p[(i + 1) % 2][j];
                int idx = lower_bound(v.begin() + l, v.end(), target) - v.begin();
                bool useActive = true;
                if(idx < M){
                    if(v[idx] == target){
                        matches += 1;
                        l = idx + 1;
                        useActive = false;
                    }
                }
                if(useActive && !activeS.empty()){
                    auto it = activeS.find(target);
                    if(it != activeS.end()){
                        matches += 1;
                        activeS.erase(it);
                    }
                }
            }

            answer += (M - matches);
        }

        cout << "Case #" << TEST_CASE_ID << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("runway_input.txt");
    ofstream cout("runway_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    
    return 0;
}