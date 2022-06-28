class Solution {
public:
    bool isPossible(vector<int>& target) {
        // Step 1: special case (target.size() == 1)
        if((int)target.size() == 1){
            return (target[0] == 1);
        }
        
        // Step 2: greedy approach
        //         process all the operations in reverse order (from target vector to vector of ones)
        //         from the statement (all elements > 0):
        //              the current maximum element is the sum of elements from the next step
        //              as a result, the path from target vector to vector of ones is deterministic
        //         we move from the current target vector to the next target vector
        //            by simply removing from the current max the difference (currentSum - nextSum)
        //         we use a max heap to maintain the current max element
        long long sum = accumulate(target.begin(), target.end(), 0LL);
        priority_queue<long long> maxHeap(target.begin(), target.end());
        
        while(maxHeap.top() >= 2){
            long long maxNum = maxHeap.top();
            maxHeap.pop();
            
            if(sum - maxNum == 0){
                return false;
            }
            
            long long nextMaxNum = maxHeap.top();
            long long k = (maxNum - nextMaxNum) / (sum - maxNum);
            long long prevNum = maxNum - max(1LL, k) * (sum - maxNum);
            
            if(prevNum >= 1){
                maxHeap.push(prevNum);
                sum -= maxNum;
                sum += prevNum;
            }else{
                return false;
            }
        }
        
        return true;
    }
};