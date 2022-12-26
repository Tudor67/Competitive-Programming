class Solution {
public:
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        const int Q = queries.size();
        
        vector<int> answer(Q);
        for(int i = 0; i < Q; ++i){
            int a = queries[i][0];
            int b = queries[i][1];

            answer[i] = 1;
            while(a != b){
                if(a < b){
                    b /= 2;
                }else{
                    a /= 2;
                }
                answer[i] += 1;
            }
        }
        
        return answer;
    }
};