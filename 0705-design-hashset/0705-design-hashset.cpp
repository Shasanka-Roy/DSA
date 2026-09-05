class MyHashSet {
private:
    vector<bool> hashSet;

public:
    MyHashSet() {
        // Keys are from 0 to 10^6
        hashSet.resize(1000001, false);
    }

    void add(int key) {
        hashSet[key] = true;
    }

    void remove(int key) {
        hashSet[key] = false;
    }

    bool contains(int key) {
        return hashSet[key];
    }
};
