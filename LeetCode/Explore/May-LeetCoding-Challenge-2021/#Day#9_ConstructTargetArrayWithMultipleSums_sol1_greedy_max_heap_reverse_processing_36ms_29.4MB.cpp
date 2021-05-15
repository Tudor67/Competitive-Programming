class Solution {
public:
    bool isPossible(vector<int>& target) {
        const int N = target.size();
        
        if(N == 1){
            return (target[0] == 1);
        }
        
        if(N == 2){
            return (target[0] == 1 || target[1] % target[0] != 0);
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
            
            long long nextNum = num % (sum - num);
            sum = sum - num + nextNum;
            
            if(num == nextNum || nextNum <= 0){
                return false;
            }
            if(nextNum >= 2){
                maxHeap.push(nextNum);
            }
        }
        
        return true;
    }
};