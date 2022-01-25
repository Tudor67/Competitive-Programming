class Solution {
private:
    struct PairHash{
        size_t operator()(const pair<int, int>& P) const{
            size_t lhs = P.first;
            size_t rhs = P.second;
            return (lhs << 15) | rhs;
        }
    };
    
public:
    vector<int> countPairs(int N, vector<vector<int>>& edges, vector<int>& queries) {
        vector<int> degree(N + 1);
        unordered_map<pair<int, int>, int, PairHash> count;
        for(const vector<int>& EDGE: edges){
            int x = EDGE[0];
            int y = EDGE[1];
            degree[x] += 1;
            degree[y] += 1;
            count[{min(x, y), max(x, y)}] += 1;
        }
        
        vector<int> sortedDegrees = degree;
        sort(sortedDegrees.begin(), sortedDegrees.end());
        
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
            for(const pair<pair<int, int>, int>& P: count){
                int x = P.first.first;
                int y = P.first.second;
                int xyCount = P.second;
                if(degree[x] + degree[y] > q && degree[x] + degree[y] - xyCount <= q){
                    pairsCount -= 1;
                }
            }
            
            answer.push_back(pairsCount);
        }
        
        return answer;
    }
};