class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const int Q = queries.size();

        vector<int> res(Q);
        unordered_map<int, int> colorOf;
        unordered_map<int, int> freqOf;

        for(int i = 0; i < Q; ++i){
            int ball = queries[i][0];
            int newColor = queries[i][1];

            if(colorOf.count(ball)){
                int oldColor = colorOf[ball];
                freqOf[oldColor] -= 1;
                if(freqOf[oldColor] == 0){
                    freqOf.erase(oldColor);
                }
            }

            colorOf[ball] = newColor;
            freqOf[newColor] += 1;

            res[i] = freqOf.size();
        }

        return res;
    }
};