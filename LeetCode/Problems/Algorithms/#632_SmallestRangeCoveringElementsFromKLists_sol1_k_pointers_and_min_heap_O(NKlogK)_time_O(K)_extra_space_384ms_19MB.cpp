class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        int maxNum = nums[0][0];
        int minNum = nums[0][0];
        for(int i = 0; i < nums.size(); ++i){
            pq.push({nums[i][0], 0, i});
            minNum = min(nums[i][0], minNum);
            maxNum = max(nums[i][0], maxNum);
        }
        
        vector<int> answer = {minNum, maxNum};
        while(pq.size() >= nums.size()){
            int num = pq.top()[0];
            int numPos = pq.top()[1];
            int listIdx = pq.top()[2];
            pq.pop();
            
            minNum = num;
            int currentLength = maxNum - minNum;
            int answerLength = answer[1] - answer[0];
            if(currentLength < answerLength || (currentLength == answerLength && minNum < answer[0])){
                answer = {minNum, maxNum};
            }
            
            if(numPos + 1 < nums[listIdx].size()){
                pq.push({nums[listIdx][numPos + 1], numPos + 1, listIdx});
                maxNum = max(nums[listIdx][numPos + 1], maxNum);
            }
        }
        
        return answer;
    }
};