class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        const int Q = queries.size();

        unordered_map<int, int> colorOf;
        unordered_map<int, int> freqOf;
        
        vector<int> res;
        res.reserve(Q);

        for(vector<int>& query: queries){
            int ball = query[0];
            int newColor = query[1];

            freqOf[colorOf[ball]] -= 1;
            if(freqOf[colorOf[ball]] <= 0){
                freqOf.erase(colorOf[ball]);
            }
            colorOf[ball] = newColor;
            freqOf[colorOf[ball]] += 1;

            res.push_back((int)freqOf.size());
        }

        return res;
    }
};