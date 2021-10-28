#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;

vector<vector<int>> g;

class TestCase{
private:
    const int INF = 1e8;
    
    void dfs(int prevNode, int node, int level, vector<int>& minLevelOf, const vector<vector<int>>& G,
             long long& answer, vector<int>& f){
        minLevelOf[node] = level;
        for(int nextNode: G[node]){
            if(minLevelOf[nextNode] == INF){
                dfs(node, nextNode, level + 1, minLevelOf, G, answer, f);
            }
            if(nextNode != prevNode){
                minLevelOf[node] = min(minLevelOf[nextNode], minLevelOf[node]);
            }
        }
        if(level <= minLevelOf[node] && prevNode != -1){
            if(f[prevNode] != f[node]){
                answer += 1;
            }
        }
    }

public:
    void solve(const int& TEST_CASE_ID, istream& cin, ostream& cout){
        int N;
        cin >> N;

        g.clear();
        g.resize(N + 3);
        for(int i = 1; i <= N - 1; ++i){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> f(N + 1);
        vector<int> prevNodeWith(N + 3, -1);
        for(int i = 1; i <= N; ++i){
            cin >> f[i];
            if(prevNodeWith[f[i]] != -1){
                int x = i;
                int y = prevNodeWith[f[i]];
                g[x].push_back(y);
                g[y].push_back(x);
            }
            prevNodeWith[f[i]] = i;
        }

        // critical connections
        long long answer = 0;
        vector<int> minLevelOf(N + 3, INF);
        dfs(-1, 1, 0, minLevelOf, g, answer, f);

        cout << "Case #" << TEST_CASE_ID << ": " << answer << "\n";
    }
};

int main(){
    ifstream cin("chainblock_input.txt");
    ofstream cout("chainblock_output.txt");
    
    int T;
    cin >> T;

    rlimit R;
    getrlimit(RLIMIT_STACK, &R);
    R.rlim_cur = R.rlim_max;
    setrlimit(RLIMIT_STACK, &R);

    for(int testCaseId = 1; testCaseId <= T; ++testCaseId){
        TestCase().solve(testCaseId, cin, cout);
    }

    cin.close();
    cout.close();
    
    return 0;
}