#include <algorithm>
#include <fstream>
#include <map>
#include <set>
#include <tuple>
#include <vector>
using namespace std;

void solve(const int& TEST_CASE, ifstream& cin, ofstream& cout){
    int n;
    cin >> n;

    const int MID_POS = 1;
    const int RIGHT_POS = 0;
    int pos, pos_type, height;
    set<tuple<int, int, int>> pos_set;

    for(int i = 0; i < n; ++i){
        cin >> pos >> height;
        pos_set.insert({pos, MID_POS, height});
        pos_set.insert({pos + height, RIGHT_POS, height});
    }

    vector<map<int, int>> max_len(2);
    for(const tuple<int, int, int>& T: pos_set){
        pos = get<0>(T);
        pos_type = get<1>(T);
        height = get<2>(T);

        if(pos_type == RIGHT_POS){
            // try [real_position, real_position + height]
            int prev_len = (max_len[RIGHT_POS].count(pos - height) ? max_len[RIGHT_POS][pos - height] : 0);
            if(max_len[RIGHT_POS].count(pos)){
                max_len[RIGHT_POS][pos] = max(prev_len + height, max_len[RIGHT_POS][pos]);
            }else{
                max_len[RIGHT_POS][pos] = prev_len + height;
            }
        }

        if(pos_type == MID_POS){
            // try [real_position - height, real_position]
            int prev_len1 = (max_len[RIGHT_POS].count(pos - height) ? max_len[RIGHT_POS][pos - height] : 0);
            int prev_len2 = (max_len[MID_POS].count(pos - height) ? max_len[MID_POS][pos - height] : 0);
            max_len[MID_POS][pos] = max(prev_len1, prev_len2) + height;
        }
    }

    int answer = 0;
    for(const int& POS_TYPE: {RIGHT_POS, MID_POS}){
        for(const pair<int, int>& P: max_len[POS_TYPE]){
            answer = max(P.second, answer);
        }
    }

    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ifstream cin("timber_input.txt");
    ofstream cout("timber_output.txt");
    
    int test_cases;
    cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; ++test_case){
        solve(test_case, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}