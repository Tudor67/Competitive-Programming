#include <fstream>
#include <string>
using namespace std;

void solve(const int& TEST_CASE, ifstream& cin, ofstream& cout){
    int n;
    cin >> n;

    string r_in;
    string r_out;
    cin >> r_in;
    cin >> r_out;

    cout << "Case #" << TEST_CASE << ":\n";
    for(int i = 0; i < n; ++i){
        string p(n, 'Y');

        char status = 'Y';
        for(int j = i - 1; j >= 0; --j){
            if(r_out[j + 1] == 'N' || r_in[j] == 'N'){
                status = 'N';
            }
            p[j] = status;
        }

        status = 'Y';
        for(int j = i + 1; j < n; ++j){
            if(r_out[j - 1] == 'N' || r_in[j] == 'N'){
                status = 'N';
            }
            p[j] = status;
        }

        cout << p << "\n";
    }
}

int main(){
    ifstream cin("travel_restrictions_input.txt");
    ofstream cout("travel_restrictions_output.txt");
    
    int test_cases;
    cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; ++test_case){
        solve(test_case, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}