class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        const int N = nums.size();

        long long validSubarrays = N;

        stack<pair<int, int>> st;
        for(int num: nums){
            while(!st.empty() && st.top().first < num){
                st.pop();
            }
            if(!st.empty() && st.top().first == num){
                validSubarrays += st.top().second;
                st.top().second += 1;
            }else{
                st.push({num, 1});
            }
        }

        return validSubarrays;
    }
};