class FoodRatings {
private:
    unordered_map<string, set<pair<int, string>>> rfOf;
    unordered_map<string, string> cuisineOf;
    unordered_map<string, int> ratingOf;
    
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        const int N = foods.size();
        for(int i = 0; i < N; ++i){
            rfOf[cuisines[i]].emplace(-ratings[i], foods[i]);
            cuisineOf[foods[i]] = cuisines[i];
            ratingOf[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int oldRating = ratingOf[food];
        string cuisine = cuisineOf[food];
        rfOf[cuisine].erase({-oldRating, food});
        ratingOf[food] = newRating;
        rfOf[cuisine].emplace(-newRating, food);
    }
    
    string highestRated(string cuisine) {
        return rfOf[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */