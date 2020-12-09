class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        const int N = A.size();
        
        unordered_set<int> distinctNums;
        deque<int> dq;
        for(int i = N - 1; i >= 0; --i){
            const int DQ_SIZE = dq.size();
            int curNum = A[i];
            dq.push_back(curNum);
            distinctNums.insert(curNum);
            for(int k = 1; k <= DQ_SIZE; ++k){
                int prevNum = dq.front();
                dq.pop_front();
                curNum |= prevNum;
                if(curNum != dq.back()){
                    dq.push_back(curNum);
                    distinctNums.insert(curNum);
                }
            }
        }
        
        return distinctNums.size();
    }
};