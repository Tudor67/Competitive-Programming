class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();
        
        int triplets = 0;
        unordered_map<int, int> leftCnt;
        unordered_map<int, int> rightCnt;
        for(int j = 1; j < N; ++j){
            int a = 0;
            leftCnt.clear();
            for(int i = j - 1; i >= 0; --i){
                a ^= arr[i];
                leftCnt[a] += 1;
            }
            
            int b = 0;
            rightCnt.clear();
            for(int k = j; k < N; ++k){
                b ^= arr[k];
                rightCnt[b] += 1;
            }
            
            for(const pair<int, int>& P: leftCnt){
                a = P.first;
                if(rightCnt.count(a)){
                    triplets += (leftCnt[a] * rightCnt[a]);
                }
            }
        }
        
        return triplets;
    }
};