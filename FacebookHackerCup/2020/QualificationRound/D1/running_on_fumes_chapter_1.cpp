#include <algorithm>
#include <fstream>
#include <set>
#include <vector>
using namespace std;

void solve(const int& TEST_CASE, ifstream& cin, ofstream& cout){
    int n, m;
    cin >> n >> m;

    vector<long long> cost(n + 1);
    for(int i = 1; i <= n; ++i){
        cin >> cost[i];
    }
    cost[1] = 0;
    cost[n] = 0;

    vector<long long> min_cost(n + 1, 0);
    set<pair<long long, int>> stations;
    bool is_possible = true;

    for(int i = n - 1; i >= n - m; --i){
        if(cost[i] > 0){
            stations.insert({cost[i], i});
        }
    }

    for(int i = n - m - 1; is_possible && i >= 1; --i){
        stations.erase({min_cost[i + m + 1] + cost[i + m + 1], i + m + 1});

        if(stations.empty()){
            is_possible = false;
        }else{
            min_cost[i] = stations.begin()->first;
        }

        if(cost[i] > 0){
            stations.insert({min_cost[i] + cost[i], i});
        }
    }

    long long answer = 0;
    if(is_possible){
        answer = min_cost[1];
    }else{
        answer = -1;
    }

    cout << "Case #" << TEST_CASE << ": " << answer << "\n";
}

int main(){
    ifstream cin("running_on_fumes_chapter_1_input.txt");
    ofstream cout("running_on_fumes_chapter_1_output.txt");
    
    int test_cases;
    cin >> test_cases;

    for(int test_case = 1; test_case <= test_cases; ++test_case){
        solve(test_case, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}