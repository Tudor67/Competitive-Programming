class FindSumPairs {
private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(int num2: nums2){
            freq2[num2] += 1;
        }
    }
    
    void add(int index, int val) {
        freq2[nums2[index]] -= 1;
        nums2[index] += val;
        freq2[nums2[index]] += 1;
    }
    
    int count(int tot) {
        int validPairs = 0;
        for(int num1: nums1){
            int complNum = tot - num1;
            if(freq2.count(complNum)){
                validPairs += freq2[complNum];
            }
        }
        return validPairs;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */