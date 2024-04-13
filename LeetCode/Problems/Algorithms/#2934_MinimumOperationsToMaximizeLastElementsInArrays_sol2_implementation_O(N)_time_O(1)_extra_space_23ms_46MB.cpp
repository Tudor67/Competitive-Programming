class Solution {
private:
    const int INF = 1e9;
    
    int computeMinOps(vector<int>& nums1, vector<int>& nums2, int targetMax1, int targetMax2){
        const int N = nums1.size();
        
        int minOps = 0;
        for(int i = 0; i < N; ++i){
            if(nums1[i] <= targetMax1 && nums2[i] <= targetMax2){
                // ok
            }else if(nums1[i] <= targetMax2 && nums2[i] <= targetMax1){
                minOps += 1;
            }else{
                return INF;
            }
        }
        
        return minOps;
    }
    
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        
        int minOps1 = computeMinOps(nums1, nums2, nums1[N - 1], nums2[N - 1]);
        int minOps2 = computeMinOps(nums1, nums2, nums2[N - 1], nums1[N - 1]);
        
        int minOps = min(minOps1, minOps2);
        if(minOps >= INF){
            minOps = -1;
        }
        
        return minOps;
    }
};