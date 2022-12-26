class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        const int Q = queries.size();
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];
            
            string aStr = bitset<32>(a).to_string();
            string bStr = bitset<32>(b).to_string();
            
            const int L = aStr.length();
            int aIndex = find(aStr.begin(), aStr.end(), '1') - aStr.begin();
            int bIndex = find(bStr.begin(), bStr.end(), '1') - bStr.begin();
            
            while(aIndex < L && bIndex < L && aStr[aIndex] == bStr[bIndex]){
                aIndex += 1;
                bIndex += 1;
            }
            answer[i] = (L - aIndex) + (L - bIndex) + 1;
        }
        
        return answer;
    }
};