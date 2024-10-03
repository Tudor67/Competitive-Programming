#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        long double N, P;
        cin >> N >> P;

        long double answer = P * (pow(100 / P, 1 / N) - 1);

        cout << fixed << setprecision(10);
        cout << "Case #" << TEST_CASE_ID << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("line_by_line_input.txt");
    ofstream cout("line_by_line_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}