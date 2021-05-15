class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long> maxHeap;
        for(int num: target){
            if(num >= 2){
                maxHeap.push(num);
            }
        }
        
        long long sum = accumulate(target.begin(), target.end(), 0LL);
        while(!maxHeap.empty()){
            long long num = maxHeap.top();
            maxHeap.pop();
            
            if(sum == num){
                return false;
            }
            
            long long nextNum = num % (sum - num);
            if(nextNum == 0){
                nextNum = sum - num;
            }
            sum = sum - num + nextNum;
            
            if(num == nextNum){
                return false;
            }
            if(nextNum >= 2){
                maxHeap.push(nextNum);
            }
        }
        
        return true;
    }
};