class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        const int N = nums.size();

        vector<int> nextGreater(N, N);
        stack<int> st;
        for(int i = 0; i < N; ++i){
            while(!st.empty() && nums[st.top()] < nums[i]){
                nextGreater[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        long long validSubarrays = 0;
        for(int i = 0; i < N; ++i){
            int j = nextGreater[i] - 1;
            const vector<int>& indices = numToIndices[nums[i]];
            int index2 = upper_bound(indices.begin(), indices.end(), j) - indices.begin();
            int index1 = lower_bound(indices.begin(), indices.end(), i) - indices.begin();
            validSubarrays += (index2 - index1);
        }

        return validSubarrays;
    }
};