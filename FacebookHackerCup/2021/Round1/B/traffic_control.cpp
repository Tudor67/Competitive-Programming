#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int ROWS, COLS, A, B;
        cin >> ROWS >> COLS >> A >> B;

        int startVal = A - (ROWS + COLS - 2);
        int endVal = B - (ROWS + COLS - 2);
        bool isPossible = (startVal >= 1 && endVal >= 1);

        cout << "Case #" << TEST_CASE_ID << ": ";
        if(isPossible){
            cout << "Possible\n";
            for(int row = 1; row <= ROWS; ++row){
                for(int col = 1; col <= COLS; ++col){
                    int val = 1;
                    if(row == 1 && col == 1){
                        val = startVal;
                    }else if(row == ROWS && col == 1){
                        val = endVal;
                    }
                    cout << val << " ";
                }
                cout << "\n";
            }
        }else{
            cout << "Impossible\n";
        }
    }
};

int main(){
    ifstream cin("traffic_control_input.txt");
    ofstream cout("traffic_control_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    
    return 0;
}