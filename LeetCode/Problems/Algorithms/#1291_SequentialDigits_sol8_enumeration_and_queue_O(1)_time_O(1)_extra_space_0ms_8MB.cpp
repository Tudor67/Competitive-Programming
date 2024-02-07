class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int i = 1; i <= 9; ++i){
            q.push(i);
        }

        vector<int> res;
        while(!q.empty()){
            int num = q.front();
            q.pop();

            if(low <= num && num <= high){
                res.push_back(num);
            }

            int lastDigit = num % 10;
            if(lastDigit + 1 <= 9 && num <= (high - lastDigit - 1) / 10){
                q.push(10 * num + lastDigit + 1);
            }
        }

        return res;
    }
};