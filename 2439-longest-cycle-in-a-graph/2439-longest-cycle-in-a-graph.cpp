static const int __ = []() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr); return 0; }();

typedef long long ll; typedef unsigned int ui; typedef unsigned long long ull; typedef pair<int ,int> pii; typedef pair<ll, ll> pll; typedef double rl;
typedef pii int2; typedef tuple<int, int, int> int3; typedef tuple<int, int, int, int> int4; typedef tuple<int, int, int, int, int> int5;
typedef pll ll2; typedef tuple<ll, ll, ll> ll3; typedef tuple<ll, ll, ll, ll> ll4; typedef tuple<ll, ll, ll, ll, ll> ll5;
typedef vector<int> vi; typedef vector<pii> vii; typedef vector<ll> vll; typedef vector<pll> vll_ll; typedef vector<vi> vvi; typedef vector<vii> vvii; typedef vector<vll> vvll; typedef vector<vll_ll> vvll_ll;

#define pb push_back
#define mp make_pair
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,N) for(int i=0; i<N; i++)
#define g0(x) get<0>(x)
#define g1(x) get<1>(x)
#define g2(x) get<2>(x)
#define g3(x) get<3>(x)
#define g4(x) get<4>(x)

template<typename A> string to_string(A* ptr) { stringstream ss; ss << "0x" << std::setw(16) << std::setfill ('0') << std::hex << (uint64_t)(uintptr_t)ptr; return ss.str(); }
string to_string(char c) { return ((string)"'"+c)+ "'"; }
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) { return '"' + s + '"'; }
string to_string(const char* s) { return to_string((string) s); }
string to_string(bool b) { return (b ? "true" : "false"); }
string to_string(vector<bool> v) {
    bool first = true; string res = "{";
	for (int i = 0; i < static_cast<int>(v.size()); i++) { if (!first) { res += ", "; } first = false; res += to_string(v[i]); }
	res += "}"; return res;
}
template <size_t N> string to_string(bitset<N> v) { string res = ""; for (size_t i = 0; i < N; i++) { res += static_cast<char>('0' + v[i]); } return res; }
template <typename A> string to_string(A v) {
	bool first = true; string res = "{";
	for (const auto &x : v) {
		if (!first) { res += ", "; }
		first = false; res += to_string(x);
	}
	res += "}"; return res;
}
template <typename A, typename B> string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")"; }
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) { return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; }
void debug_out() { cout << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cout << " " << to_string(H); debug_out(T...); }

#define popc __builtin_popcountll
//#define popc __builtin_popcount
//#define clz __builtin_clzll
//#define clz __builtin_clz
inline int bitLength(uint32_t val) { return 32 - __builtin_clz  (val); }
inline int bitLength(uint64_t val) { return 64 - __builtin_clzll(val); }

template<typename T> inline void domax(T& A, const T& B) { A=max(A, B); }
template<typename T> inline void domin(T& A, const T& B) { A=min(A, B); }

template<typename T>
inline T true_mod(T A, T B)
{
    assert(B>=1);
    A%=B;
    if(A<0) A+=B;
    return A;
}

template<typename T>
inline T div_down(T A, T B)
{
    return (A-true_mod(A,B))/B;
}

template<typename T>
inline T div_up(T A, T B)
{
    return div_down(A+B-1, B);
}

#if 0
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

const int NOE=-1;

class Solution {
public:
    int longestCycle(vector<int>& e) {
        int n=e.size();
        
        vector<bool> visited(n, false);
        vector<int> t_visited(n);
        vector<int> id_visited(n, -1);
        //int id_visited(n);

        int result=-1;
        
        int id=0;
        FOR(i, n) {
            if(visited[i]) continue;
            int curr=i;
            
            dbg("------");
            dbg(i);
            
            int tt=0;
            while(true) {
                tt++;
                
                dbg(curr, tt);
                
                if(visited[curr]) {    
                    if(id_visited[curr]==id) {
                        domax(result, tt-t_visited[curr]);
                    }
                    
                    break;
                }
                
                visited[curr]=true;
                t_visited[curr]=tt;
                id_visited[curr]=id;
                
                
                int next=e[curr];
                if(next==-1) break;
                curr=next;
            }
            
            id++;
        }
        
        return result;
    }
};