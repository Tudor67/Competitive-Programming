#include <bits/stdc++.h>
using namespace std;

using Point = pair<int, int>;
map<pair<int, int>, int> freq;

class TestCase{
private:
    int computeMinMoves(const Point& ORIGIN, const vector<Point>& P){
        freq.clear();
        for(const Point& POINT: P){
            int dx = POINT.first - ORIGIN.first;
            int dy = POINT.second - ORIGIN.second;
            if(dx == 0 && dy == 0){
                continue;
            }else{
                int g = gcd(dx, dy);
                freq[{dx / g, dy / g}] += 1;
            }
        }

        int minMoves = (int)P.size() - 2;
        for(const pair<const pair<int, int>, int>& PP: freq){
            minMoves = min(minMoves, (int)P.size() - (PP.second + 1));
        }

        return minMoves;
    }

public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int N;
        cin >> N;

        vector<Point> P(N);
        for(int i = 0; i < N; ++i){
            cin >> P[i].first >> P[i].second;
        }

        srand(67);
        random_shuffle(P.begin(), P.end());

        int res = N - 2;
        for(int i = 0; i < min(30, N) && res > 0; ++i){
            res = min(res, computeMinMoves(P[i], P));
        }

        cout << "Case #" << TEST_CASE_ID << ": " << res << "\n";
    }
};

int main(){
    ifstream cin("fall_in_line_input.txt");
    ofstream cout("fall_in_line_output.txt");
    
    int T;
    cin >> T;

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}