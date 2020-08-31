class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> next_greater;
        for(int num: nums1){
            next_greater[num] = -1;
        }
        
        stack<int> st;
        for(int i = (int)nums2.size() - 1; i >= 0; --i){
            while(!st.empty() && nums2[i] >= st.top()){
                st.pop();
            }
            if(!st.empty() && nums2[i] < st.top()){
                if(next_greater.count(nums2[i])){
                    next_greater[nums2[i]] = st.top();
                }
            }
            st.push(nums2[i]);
        }
        
        vector<int> answer(nums1.size());
        for(int i = 0; i < nums1.size(); ++i){
            answer[i] = next_greater[nums1[i]];
        }
        
        return answer;
    }
};