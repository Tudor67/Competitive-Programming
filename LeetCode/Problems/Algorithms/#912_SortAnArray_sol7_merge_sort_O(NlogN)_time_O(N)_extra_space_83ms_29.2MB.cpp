class Solution {
private:
    void merge(vector<int>& v, const int& L, const int& MID, const int& R, vector<int>& temp){
        const int SIZE = R - L + 1;
        
        int i = L;
        int j = MID + 1;
        int k = 0;
        while(i <= MID && j <= R){
            if(v[i] <= v[j]){
                temp[k] = v[i];
                i += 1;
            }else{
                temp[k] = v[j];
                j += 1;
            }
            k += 1;
        }
        
        copy(v.begin() + i, v.begin() + MID + 1, temp.begin() + k);
        copy(v.begin() + j, v.begin() + R + 1, temp.begin() + k);
        copy(temp.begin(), temp.begin() + SIZE, v.begin() + L);
    }
    
    void mergeSort(vector<int>& v, const int& L, const int& R, vector<int>& temp){
        if(L < R){
            int mid = (L + R) / 2;
            mergeSort(v, L, mid, temp);
            mergeSort(v, mid + 1, R, temp);
            merge(v, L, mid, R, temp);
        }
    }
    
    void mergeSort(vector<int>& v){
        const int N = v.size();
        vector<int> temp(N);
        mergeSort(v, 0, N - 1, temp);
    }
    
public:
    vector<int> sortArray(vector<int>& nums) {
        const int N = nums.size();
        
        vector<int> sortedNums = nums;
        mergeSort(sortedNums);
        
        return sortedNums;
    }
};