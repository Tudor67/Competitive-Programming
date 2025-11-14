class Solution {
public:
    int minOperations(vector<int>& nums) {
        const int N = nums.size();

        int totalOps = 0;
        stack<int> st;

        for(int num: nums){
            while(!st.empty() && st.top() > num){
                totalOps += 1;
                st.pop();
            }
            if(num != 0 && (st.empty() || st.top() != num)){
                st.push(num);
            }
        }

        totalOps += (int)st.size();

        return totalOps;
    }
};