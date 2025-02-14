class ProductOfNumbers {
private:
    vector<int> nums;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        nums.push_back(num);
    }
    
    int getProduct(int k) {
        int prod = 1;
        for(int i = (int)nums.size() - k; i < (int)nums.size(); ++i){
            prod *= nums[i];
        }
        return prod;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */