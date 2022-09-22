class Solution {
private:
    int computeMaxPrefixMatch(const int& A_START_POS, const vector<int>& A, const vector<int>& B,
                              vector<int>& psTemp, vector<int>& pTemp){
        const int A_SIZE = A.size();
        const int B_SIZE = B.size();
        const int PS_SIZE = A_SIZE - A_START_POS + B_SIZE + 1;
        
        vector<int>& PS = psTemp;
        PS.resize(PS_SIZE);
        copy(A.begin() + A_START_POS, A.end(), PS.begin());
        PS[A_SIZE - A_START_POS] = INT_MIN;
        copy(B.begin(), B.end(), PS.begin() + A_SIZE - A_START_POS + 1);
        
        vector<int>& p = pTemp;
        p.resize(PS_SIZE);
        for(int i = 1; i < PS_SIZE; ++i){
            int k = p[i - 1];
            while(k > 0 && PS[k] != PS[i]){
                k = p[k - 1];
            }
            if(PS[k] == PS[i]){
                k += 1;
            }
            p[i] = k;
        }
        
        return *max_element(p.begin() + A_SIZE - A_START_POS + 1, p.end());
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        const int N1 = nums1.size();
        const int N2 = nums2.size();
        
        int maxMatch = 0;
        vector<int> psTemp;
        vector<int> pTemp;
        for(int i1 = 0; i1 < N1; ++i1){
            maxMatch = max(maxMatch, computeMaxPrefixMatch(i1, nums1, nums2, psTemp, pTemp));
        }
        
        return maxMatch;
    }
};