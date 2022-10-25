class Solution {
private:
    void mergeSort(const int& L, const int& R, vector<int>& a, vector<int>& temp, int diff, long long& res){
        const int SIZE = R - L + 1;
        const int MID = (L + R) / 2;
        
        if(SIZE <= 1){
            return;
        }
        
        mergeSort(L, MID, a, temp, diff, res);
        mergeSort(MID + 1, R, a, temp, diff, res);
        
        // add `inversions` to res
        int leftIndex = L;
        int rightIndex = MID + 1;
        while(leftIndex <= MID && rightIndex <= R){
            if(a[leftIndex] <= a[rightIndex] + diff){
                leftIndex += 1;
                res += (R - rightIndex + 1);
            }else{
                rightIndex += 1;
            }
        }
        
        // merge two sorted subarrays
        leftIndex = L;
        rightIndex = MID + 1;
        for(int tempIndex = 0; tempIndex < SIZE; ++tempIndex){
            if(rightIndex > R || (leftIndex <= MID && a[leftIndex] <= a[rightIndex])){
                temp[tempIndex] = a[leftIndex];
                leftIndex += 1;
            }else{
                temp[tempIndex] = a[rightIndex];
                rightIndex += 1;
            }
        }
        
        copy(temp.begin(), temp.begin() + SIZE, a.begin() + L);
    }
    
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        const int N = nums1.size();
        
        vector<int> a(N);
        for(int i = 0; i < N; ++i){
            a[i] = nums1[i] - nums2[i];
        }
        
        long long res = 0;
        vector<int> temp(N);
        mergeSort(0, N - 1, a, temp, diff, res);
        
        return res;
    }
};