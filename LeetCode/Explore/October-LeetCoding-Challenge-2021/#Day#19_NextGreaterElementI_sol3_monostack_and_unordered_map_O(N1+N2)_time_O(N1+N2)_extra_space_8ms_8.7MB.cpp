class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        unordered_map<int, int> idxOf;
        for(int i = 0; i < N1; ++i){
            idxOf[nums1[i]] = i;
        }
        
        stack<int> st;
        vector<int> answer(N1);
        for(int j = N2 - 1; j >= 0; --j){
            while(!st.empty() && nums2[j] >= nums2[st.top()]){
                st.pop();
            }
            if(idxOf.count(nums2[j])){
                if(st.empty()){
                    answer[idxOf[nums2[j]]] = -1;
                }else{
                    answer[idxOf[nums2[j]]] = nums2[st.top()];
                }
            }
            st.push(j);
        }
        
        return answer;
    }
};