class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        const int N = segments.size();
        
        map<int, long long> delta;
        for(const vector<int>& SEG: segments){
            int startPos = SEG[0];
            int endPos = SEG[1];
            int color = SEG[2];
            delta[startPos] += color;
            delta[endPos] -= color;
        }
        
        vector<vector<long long>> painting;
        int prevPos = 0;
        long long currentColor = 0;
        for(const pair<int, long long>& P: delta){
            int pos = P.first;
            long long color = P.second;
            
            if(currentColor >= 1){
                painting.push_back({prevPos, pos, currentColor});
            }
            
            currentColor += color;
            prevPos = pos;
        }
        
        return painting;
    }
};