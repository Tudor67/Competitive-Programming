#include <bits/stdc++.h>
using namespace std;

class Solution{
private:
    static void dfs(int prevNode, int node, vector<long long>& gold, vector<int>& subtreeIdx, const vector<vector<int>>& G){
        gold[node] += gold[prevNode];
        for(int nextNode: G[node]){
            if(subtreeIdx[nextNode] == 0){
                subtreeIdx[nextNode] = subtreeIdx[node];
                dfs(node, nextNode, gold, subtreeIdx, G);
            }
        }
    }

public:
    static void solve(const int& TEST_CASE, istream& cin, ostream& cout){
        int n;
        cin >> n;

        vector<long long> gold(n + 1);
        for(int node = 1; node <= n; ++node){
            cin >> gold[node];
        }

        vector<vector<int>> g(n + 1);
        for(int i = 1; i <= n - 1; ++i){
            int x, y;
            cin >> x >> y;
            g[x].push_back(y);
            g[y].push_back(x);
        }

        vector<int> subtreeIdx(n + 1);
        subtreeIdx[1] = 1;
        int currentSubtreeIdx = 1;
        for(int node: g[1]){
            subtreeIdx[node] = ++currentSubtreeIdx;
            dfs(1, node, gold, subtreeIdx, g);
        }

        long long maxGold = gold[1];
        for(int node = 1; node <= n; ++node){
            for(int nextNode = 1; nextNode <= n; ++nextNode){
                if(subtreeIdx[node] != subtreeIdx[nextNode]){
                    long long cycleGold = gold[node] + gold[nextNode] - gold[1];
                    maxGold = max(maxGold, cycleGold);
                }
            }
        }

        cout << "Case #" << TEST_CASE << ": " << maxGold << "\n";
    }
};

int main(){
    ifstream cin("gold_mine_chapter_1_input.txt");
    ofstream cout("gold_mine_chapter_1_output.txt");
    
    int T;
    cin >> T;

    for(int testCase = 1; testCase <= T; ++testCase){
        Solution::solve(testCase, cin, cout);
    }

    cin.close();
    cout.close();
    return 0;
}