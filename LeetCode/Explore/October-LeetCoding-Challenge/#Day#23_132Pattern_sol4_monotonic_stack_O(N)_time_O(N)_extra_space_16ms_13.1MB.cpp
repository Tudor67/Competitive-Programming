class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        const int N = nums.size();
        
        // prefMin[i] = min(nums[0], nums[1], .. nums[i])
        vector<int> prefMin(N);
        prefMin[0] = nums[0];
        for(int pos = 1; pos < N; ++pos){
            prefMin[pos] = min(prefMin[pos - 1], nums[pos]);
        }
        
        stack<int> st;
        for(int pos = N - 1; pos >= 1; --pos){
            // fix leftNum and midNum
            int leftNum = prefMin[pos - 1];
            int midNum = nums[pos];
            if(leftNum < midNum){
                // leftNum < st.top() <= st.top() - 1 <= ....
                while(!st.empty() && leftNum >= st.top()){
                    st.pop();
                }

                // fix rightNum
                int rightNum = (st.empty() ? INT_MIN : st.top());

                // update stack for the next trials
                st.push(midNum);

                // check if the current triplet is valid
                if(leftNum < midNum && midNum > rightNum && leftNum < rightNum){
                    return true;
                }
            }
        }
        
        return false;
    }
};