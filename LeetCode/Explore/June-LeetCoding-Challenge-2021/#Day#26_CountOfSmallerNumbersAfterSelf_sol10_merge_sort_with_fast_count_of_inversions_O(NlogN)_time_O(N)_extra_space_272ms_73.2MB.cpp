class Solution {
private:
    void merge(const int& L, const int& MID, const int& R, const vector<int>& NUMS, vector<int>& indices, vector<int>& count){
        static vector<int> temp;
        const int RANGE_SIZE = R - L + 1;
        temp.resize(RANGE_SIZE, (int)temp.size());
        for(int k = 0, i = L, j = MID + 1, inversionsStatus = 0; k < RANGE_SIZE; ++k){
            if(j > R || (i <= MID && NUMS[indices[i]] <= NUMS[indices[j]])){
                count[indices[i]] += inversionsStatus;
                temp[k] = indices[i++];
            }else{
                inversionsStatus += 1;
                temp[k] = indices[j++];
            }
        }
        copy(temp.begin(), temp.begin() + RANGE_SIZE, indices.begin() + L);
    }
    
    void mergeSort(const int& L, const int& R, const vector<int>& NUMS, vector<int>& indices, vector<int>& count){
        const int RANGE_SIZE = R - L + 1;
        const int MID = (L + R) / 2;
        if(RANGE_SIZE >= 2){
            mergeSort(L, MID, NUMS, indices, count);
            mergeSort(MID + 1, R, NUMS, indices, count);
            merge(L, MID, R, NUMS, indices, count);
        }
    }
    
    void mergeSort(const vector<int>& NUMS, vector<int>& count){
        const int N = NUMS.size();
        vector<int> indices(N);
        iota(indices.begin(), indices.end(), 0);
        mergeSort(0, N - 1, NUMS, indices, count);
    }
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        const int N = nums.size();
        vector<int> count(N);
        mergeSort(nums, count);
        return count;
    }
};