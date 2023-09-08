class Solution {
public:
    vector<int> colorTheArray(int N, vector<vector<int>>& queries) {
        const int Q = queries.size();

        int adjEqualColors = 0;
        vector<int> colorAt(N + 2);

        vector<int> res(Q);
        for(int i = 0; i < Q; ++i){
            int pos = queries[i][0] + 1;
            int color = queries[i][1];
            
            if(colorAt[pos] != color){
                adjEqualColors -= (int)(colorAt[pos] != 0 && colorAt[pos - 1] == colorAt[pos]);
                adjEqualColors -= (int)(colorAt[pos] != 0 && colorAt[pos] == colorAt[pos + 1]);
                colorAt[pos] = color;
                adjEqualColors += (int)(colorAt[pos - 1] == colorAt[pos]);
                adjEqualColors += (int)(colorAt[pos] == colorAt[pos + 1]);
            }
            
            res[i] = adjEqualColors;
        }
        
        return res;
    }
};