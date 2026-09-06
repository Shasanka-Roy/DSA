class LRUCache {
private:
    int capacity;

    // {key, value}
    // Front = most recently used
    // Back = least recently used
    list<pair<int, int>> cache;

    // key -> position in list
    unordered_map<int, list<pair<int, int>>::iterator> mp;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        // Key doesn't exist
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        // Get the node
        auto it = mp[key];
        int value = it->second;

        // Move it to the front
        cache.erase(it);
        cache.push_front({key, value});

        // Update map
        mp[key] = cache.begin();

        return value;
    }

    void put(int key, int value) {
        // Key already exists
        if (mp.find(key) != mp.end()) {
            cache.erase(mp[key]);
        }

        // Add to front (most recently used)
        cache.push_front({key, value});
        mp[key] = cache.begin();

        // If capacity exceeded
        if (cache.size() > capacity) {
            auto last = cache.back();
            int lastKey = last.first;

            mp.erase(lastKey);
            cache.pop_back();
        }
    }
};
