class Solution {
public:
    vector<int> countPairs(int N, vector<vector<int>>& edges, vector<int>& queries) {
        const int E = edges.size();
        
        vector<int> degree(N + 1);
        vector<pair<int, int>> sortedEdges(E);
        for(int i = 0; i < E; ++i){
            int x = edges[i][0];
            int y = edges[i][1];
            degree[x] += 1;
            degree[y] += 1;
            sortedEdges[i] = {min(x, y), max(x, y)};
        }
        
        vector<int> sortedDegrees(degree.begin(), degree.end());
        sort(sortedDegrees.begin(), sortedDegrees.end());
        sort(sortedEdges.begin(), sortedEdges.end());
        
        vector<int> answer;
        for(int q: queries){
            int pairsCount = 0;
            
            // add all pairs (degree[x] + degree[y] > q, with x < y)
            int i = 1;
            int j = N;
            while(i < j){
                if(sortedDegrees[i] + sortedDegrees[j] <= q){
                    i += 1;
                }else{
                    pairsCount += j - i;
                    j -= 1;
                }
            }
            
            // remove bad pairs (degree[x] + degree[y] - count[{x, y}] <= q, with x < y)
            int samePairs = 0;
            for(int i = 0; i < E; ++i){
                samePairs += 1;
                if(i + 1 == E || sortedEdges[i] != sortedEdges[i + 1]){
                    int x = sortedEdges[i].first;
                    int y = sortedEdges[i].second;
                    int xyCount = samePairs;
                    if(degree[x] + degree[y] > q && degree[x] + degree[y] - xyCount <= q){
                        pairsCount -= 1;
                    }
                    samePairs = 0;
                }
            }
            
            answer.push_back(pairsCount);
        }
        
        return answer;
    }
};