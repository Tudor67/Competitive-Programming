class MovieRentingSystem {
private:
    using PriceShopMovie = tuple<int, int, int>;
    set<PriceShopMovie> rented;
    
    using PriceShop = pair<int, int>;
    unordered_map<int, set<PriceShop>> priceShopOfUnrented;
    
    unordered_map<int, unordered_map<int, int>> priceOf;
    
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(const vector<int>& ENTRY: entries){
            int shop = ENTRY[0];
            int movie = ENTRY[1];
            int price = ENTRY[2];
            priceShopOfUnrented[movie].insert({price, shop});
            priceOf[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        vector<int> shops;
        for(const PriceShop& PS: priceShopOfUnrented[movie]){
            int shop = get<1>(PS);
            shops.push_back(shop);
            if((int)shops.size() == 5){
                break;
            }
        }
        return shops;
    }
    
    void rent(int shop, int movie) {
        int price = priceOf[shop][movie];
        priceShopOfUnrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceOf[shop][movie];
        rented.erase({price, shop, movie});
        priceShopOfUnrented[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> r;
        for(const PriceShopMovie& PSM: rented){
            int shop = get<1>(PSM);
            int movie = get<2>(PSM);
            r.push_back({shop, movie});
            if((int)r.size() == 5){
                break;
            }
        }        
        return r;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */