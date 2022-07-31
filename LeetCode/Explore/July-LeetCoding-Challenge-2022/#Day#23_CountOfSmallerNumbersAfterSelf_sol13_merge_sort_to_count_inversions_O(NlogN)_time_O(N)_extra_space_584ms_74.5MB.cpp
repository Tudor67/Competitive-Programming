class Solution {
private:
    void mergeSort(const vector<int>& NUMS, vector<int>& indices, vector<int>& count,
                   const int& L, const int& R, vector<int>& temp){
        const int SIZE = R - L + 1;
        const int MID = (L + R) / 2;
        if(SIZE <= 1){
            return;
        }
        
        mergeSort(NUMS, indices, count, L, MID, temp);
        mergeSort(NUMS, indices, count, MID + 1, R, temp);
        
        int i = L;
        int j = MID + 1;
        for(int k = 0; k < SIZE; ++k){
            if(j == R + 1 || (i <= MID && NUMS[indices[i]] <= NUMS[indices[j]])){
                temp[k] = indices[i];
                count[indices[i]] += (j - (MID + 1));
                i += 1;
            }else{
                temp[k] = indices[j];
                j += 1;
            }
        }
        
        copy(temp.begin(), temp.begin() + SIZE, indices.begin() + L);
    }
    
    void mergeSort(const vector<int>& NUMS, vector<int>& indices, vector<int>& count){
        const int N = NUMS.size();
        vector<int> temp(N);
        mergeSort(NUMS, indices, count, 0, N - 1, temp);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> count(N);
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        mergeSort(nums, indices, count);
        
        return count;
    }
};