#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

void solve(const int& TEST_CASE, ifstream& cin, ofstream& cout){
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt_a = count(s.begin(), s.end(), 'A');
    int cnt_b = count(s.begin(), s.end(), 'B');

    char answer = (cnt_a + 1 == cnt_b || cnt_a == cnt_b + 1 ? 'Y' : 'N');

    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ifstream cin("alchemy_input.txt");
    ofstream cout("alchemy_output.txt");
    
    int test_cases;
    cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; ++test_case){
        solve(test_case, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}