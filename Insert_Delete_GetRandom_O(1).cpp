#include <unordered_map>
class RandomizedSet {
private:
    unordered_map<int, int> map; // Maps value to index in the vector
    vector<int> values;         // Stores values for random access

public:
    RandomizedSet() {}

    bool insert(int val) {
        if (map.find(val) != map.end()) {
            return false; // Value already exists
        }
        // Add to the map and vector
        values.push_back(val);
        map[val] = values.size() - 1; // Store the index of the value in the vector
        return true;
    }

    bool remove(int val) {
        if (map.find(val) == map.end()) {
            return false; // Value does not exist
        }
        // Swap the value to remove with the last value in the vector
        int lastValue = values.back();
        int idx = map[val];
        values[idx] = lastValue;        // Overwrite the value with the last value
        map[lastValue] = idx;          // Update index of the last value in the map
        values.pop_back();             // Remove the last value
        map.erase(val);                // Remove from the map
        return true;
    }

    int getRandom() {
        if (values.empty()) {
            return false;
        }
        int randIndex = rand() % values.size(); // Get a random index
        return values[randIndex];
    }
};