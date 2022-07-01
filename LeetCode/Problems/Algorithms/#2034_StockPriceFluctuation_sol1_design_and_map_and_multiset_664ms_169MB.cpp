class StockPrice {
private:
    map<int, int> priceAt;
    multiset<int> prices;
    
public:
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
        if(priceAt.count(timestamp)){
            prices.erase(prices.find(priceAt[timestamp]));
        }
        priceAt[timestamp] = price;
        prices.insert(price);
    }
    
    int current() {
        return prev(priceAt.end())->second;
    }
    
    int maximum() {
        return *prev(prices.end());
    }
    
    int minimum() {
        return *prices.begin();
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */