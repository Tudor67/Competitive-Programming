#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int N;
        cin >> N;

        string s;
        cin >> s;

        stack<char> st;
        for(char c: s){
            if(c != 'F'){
                if(st.empty() || st.top() != c){
                    st.push(c);
                }
            }
        }

        int answer = max(0, (int)st.size() - 1);

        cout << "Case #" << TEST_CASE_ID << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("weak_typing_chapter_1_input.txt");
    ofstream cout("weak_typing_chapter_1_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    
    return 0;
}