class Solution {
private:
    double median(multiset<int>& leftValues, multiset<int>& rightValues){
        double median;
        if(leftValues.size() > rightValues.size()){
            median = *leftValues.rbegin();
        }else if(leftValues.size() < rightValues.size()){
            median = *rightValues.begin();
        }else{
            median = ((double)*leftValues.rbegin() + (double)*rightValues.begin()) / 2.0;
        }
        return median;
    }
    
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int K) {
        multiset<int> leftValues(nums.begin(), nums.begin() + K);
        multiset<int> rightValues(nums.begin(), nums.begin() + K);
        
        while(leftValues.size() > (K + 1) / 2){
            leftValues.erase(prev(leftValues.end()));
        }
        
        while(rightValues.size() > K / 2){
            rightValues.erase(rightValues.begin());
        }
        
        vector<double> medians;
        medians.push_back(median(leftValues, rightValues));
        
        for(int i = K; i < nums.size(); ++i){
            if(leftValues.find(nums[i - K]) != leftValues.end()){
                leftValues.erase(leftValues.find(nums[i - K]));
            }else{
                rightValues.erase(rightValues.find(nums[i - K]));
            }
            
            if(!leftValues.empty() && nums[i] <= *leftValues.rbegin()){
                leftValues.insert(nums[i]);
            }else{
                rightValues.insert(nums[i]);
            }
            
            while(leftValues.size() > rightValues.size()){
                rightValues.insert(*prev(leftValues.end()));
                leftValues.erase(prev(leftValues.end()));
            }
            
            while(rightValues.size() > leftValues.size()){
                leftValues.insert(*rightValues.begin());
                rightValues.erase(rightValues.begin());
            }
            
            medians.push_back(median(leftValues, rightValues));
        }
        
        return medians;
    }
};