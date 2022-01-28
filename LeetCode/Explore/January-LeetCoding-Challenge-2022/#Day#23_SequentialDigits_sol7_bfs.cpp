class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> q;
        for(int digit = 1; digit <= 9; ++digit){
            q.push(digit);
        }
        
        vector<int> answer;
        while(!q.empty()){
            int num = q.front();
            q.pop();
            
            if(low <= num && num <= high){
                answer.push_back(num);
            }
            
            int nextDigit = (num % 10) + 1;
            if(nextDigit <= 9){
                int nextNum = 10 * num + nextDigit;
                if(nextNum <= high){
                    q.push(nextNum);
                }
            }
        }
        
        return answer;
    }
};