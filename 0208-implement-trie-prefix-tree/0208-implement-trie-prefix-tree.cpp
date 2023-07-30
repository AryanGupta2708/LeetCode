[[maybe_unused]] static const auto _ = []() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	return nullptr;
}();






class Trie {
public:
    Trie() {
        
    }
    
    void insert(string word) {
        h.emplace(word);
        string s;
        for (auto c:word) {
            s.push_back(c);
            hPref.emplace(s);
        }
    }
    
    bool search(string word) {
        return (h.find(word) != h.end());
    }
    
    bool startsWith(string prefix) {
        return (hPref.find(prefix) != hPref.end());
    }
private:
    unordered_set<string> h, hPref;
};