#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int N, G;
        cin >> N >> G;

        vector<int> E(N);
        for(int i = 0; i < N; ++i){
            cin >> E[i];
        }

        sort(E.rbegin(), E.rend());

        pair<int, int> res = {abs(G - E[0]), 0};
        for(int i = 1; i < N; ++i){
            res = min(res, {abs(G - E[i]), i});
        }

        cout << "Case #" << TEST_CASE_ID << ": " << res.second + 1 << " " << res.first << "\n";
    }
};

int main(){
    ifstream cin("line_of_delivery_part_1_input.txt");
    ofstream cout("line_of_delivery_part_1_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}