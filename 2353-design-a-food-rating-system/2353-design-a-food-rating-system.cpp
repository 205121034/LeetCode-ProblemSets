class FoodRatings {
    // Info about a food: its cuisine and current rating
    struct FoodInfo {
        string cuisine;
        int rating;
    };
    
    // Custom comparator for set: higher rating first, then lexicographically smaller name
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first)
                return a.first > b.first;  // Higher rating comes first
            return a.second < b.second;    // Lexicographically smaller name comes first
        }
    };
    
    unordered_map<string, FoodInfo> foodMap;            // food -> {cuisine, rating}
    unordered_map<string, set<pair<int, string>, Compare>> cuisineMap;  // cuisine -> sorted (rating, foodName)

public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for (int i = 0; i < n; ++i) {
            string food = foods[i];
            string cuisine = cuisines[i];
            int rating = ratings[i];
            
            foodMap[food] = {cuisine, rating};
            cuisineMap[cuisine].insert({rating, food});
        }
    }
    
    void changeRating(string food, int newRating) {
        auto& info = foodMap[food];
        string cuisine = info.cuisine;
        int oldRating = info.rating;
        
        // Remove old entry and update rating
        cuisineMap[cuisine].erase({oldRating, food});
        cuisineMap[cuisine].insert({newRating, food});
        info.rating = newRating;
    }
    
    string highestRated(string cuisine) {
        // The first element in the set is the highest-rated food
        return cuisineMap[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */