class Solution {
private:
    double computeMedianFromSortedVector(const vector<int>& V){
        const int N = V.size();
        double median = ((double)V[N / 2] + (double)V[(N - 1) / 2]) / 2.0;
        return median;
    }
    
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int K) {
        vector<int> w(nums.begin(), nums.begin() + K);
        sort(w.begin(), w.end());
        
        vector<double> medians;
        medians.push_back(computeMedianFromSortedVector(w));
        
        for(int i = K; i < nums.size(); ++i){
            // Step 1: remove nums[i - K]
            int pos = find(w.begin(), w.end(), nums[i - K]) - w.begin();
            copy(w.begin() + pos + 1, w.end(), w.begin() + pos);
            
            // Step 2: add nums[i]
            pos = lower_bound(w.begin(), w.end() - 1, nums[i]) - w.begin();
            copy_backward(w.begin() + pos, w.end() - 1, w.end());
            w[pos] = nums[i];
            
            // Step 3: compute the median
            medians.push_back(computeMedianFromSortedVector(w));
        }
        
        return medians;
    }
};