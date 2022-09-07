class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        deque<int> dq;
        for(int firstDigit = 1; firstDigit <= 9; ++firstDigit){
            dq.push_back(firstDigit);
        }
        
        for(int length = 2; length <= n; ++length){
            for(int i = dq.size(); i >= 1; --i){
                int num = dq.front();
                dq.pop_front();
                
                int lastDigit = num % 10;
                if(lastDigit - k >= 0){
                    dq.push_back(num * 10 + (lastDigit - k));
                }
                if(lastDigit + k <= 9 && k >= 1){
                    dq.push_back(num * 10 + (lastDigit + k));
                }
            }
        }
        
        return vector<int>(dq.begin(), dq.end());
    }
};