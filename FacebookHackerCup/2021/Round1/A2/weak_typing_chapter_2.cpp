#include <bits/stdc++.h>
using namespace std;

class TestCase{
public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        const long long MODULO = 1e9 + 7;

        int N;
        cin >> N;

        string s;
        cin >> s;

        long long answer = 0;
        long long lastPosOfX = -1;
        long long lastPosOfO = -1;
        long long fX = 0;
        long long fO = 0;
        for(int i = 0; i < N; ++i){
            if(s[i] == 'F'){
                if(lastPosOfX > lastPosOfO){
                    answer += fX;
                }else{
                    answer += fO;
                }
            }else if(s[i] == 'X'){
                fX = (fO + lastPosOfO + 1) % MODULO;
                answer += fX;
                lastPosOfX = i;
            }else if(s[i] == 'O'){
                fO = (fX + lastPosOfX + 1) % MODULO;
                answer += fO;
                lastPosOfO = i;
            }
            answer %= MODULO;
        }

        cout << "Case #" << TEST_CASE_ID << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("weak_typing_chapter_2_input.txt");
    ofstream cout("weak_typing_chapter_2_output.txt");

    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    
    return 0;
}