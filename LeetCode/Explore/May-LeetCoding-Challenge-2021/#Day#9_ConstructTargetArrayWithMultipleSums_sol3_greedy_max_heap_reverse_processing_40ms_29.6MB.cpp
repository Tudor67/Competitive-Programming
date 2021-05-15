class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int N = target.size();
        
        if(N == 1){
            return (target[0] == 1);
        }
        
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
            
            long long nextNum = 1 + (num - 1) % (sum - num);
            sum = sum - num + nextNum;
            if(nextNum >= 2){
                maxHeap.push(nextNum);
            }
            
            if(nextNum == num){
                return false;
            }
        }
        
        return true;
    }
};