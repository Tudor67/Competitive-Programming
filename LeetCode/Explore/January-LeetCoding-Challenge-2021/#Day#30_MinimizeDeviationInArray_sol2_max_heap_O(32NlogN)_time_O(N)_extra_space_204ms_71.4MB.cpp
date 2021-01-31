class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minNum = INT_MAX;
        priority_queue<int> maxHeap;
        for(int num: nums){
            if(num % 2 == 1){
                num *= 2;
            }
            maxHeap.push(num);
            minNum = min(num, minNum);
        }
        
        int answer = INT_MAX;
        while(!maxHeap.empty()){
            int maxNum = maxHeap.top();
            maxHeap.pop();
            answer = min(maxNum - minNum, answer);
            if(maxNum % 2 == 0){
                maxHeap.push(maxNum / 2);
                minNum = min(maxNum / 2, minNum);
            }else{
                break;
            }
        }
        
        return answer;
    }
};