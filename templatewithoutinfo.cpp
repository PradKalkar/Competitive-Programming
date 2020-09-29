/**
 *    author: pradnesh
 *    created: 29.09.2020 18:35:00
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;
#define int ll

typedef long double ld;
typedef long long ll;
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef set<int> si;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
template<class key_type, class cont = vi, class comp = less<key_type>>
using p_queue = priority_queue<key_type, cont, comp>;
template<class key_type, class comp = less<key_type>>
using oset = tree<key_type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key_type, class value_type, class comp = less<key_type>>
using omap = tree<key_type, value_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

const long double PI = 2 * acos(0.0);
const int INF = (ll)9e18;
const int mod1 = 998244353;
const int mod2 = 1000000007; //10^9 + 7
#define sz(v) int((v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define rep(var,start,end,interval) for(int var=start;(interval>0 and var<end) or (interval<0 and var>=end);var+=interval)
#define nl cout << '\n'
#define yes cout << "YES\n"
#define no cout<< "NO\n"
#define google(x, y) cout << "Case #" << x << ": " << y << '\n'

template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec)
{
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        stream << vec[i] << ' ';
    }
    stream << '\n';
    return stream;
}

template<class T>
istream& operator>>(istream& stream, vector<T>& vec)
{
    int n = vec.size();
    for (int j = 0; j < n; j++)
    {
        stream >> vec[j];
    }
    return stream;
}

istream& operator>>(istream& stream, pii& p)
{
    stream >> p.first >> p.second;
    return stream;
}

string operator+(const char& c, const string& str)
{
    string ans(1, c);
    ans.insert(end(ans), all(str));
    return ans;
}

//matrix

//modint 

//all function prototypes
int ilog(int n, int base);
int power(int, int);

void InverseofNumbers(int, int); //separating out to a group
void InverseofFactorial(int, int);
void factorialmod(int, int);
int ncrmod(int n, int r, int p);

int ncr(int n, int r);
tuple<int, int, int> euclid(int a, int b);
int modInverse(int n, int p);
int phi(int n);
bool checkprime(int p);
int power_mod(int x, int y, int p);
void prime_generator(int n);
void sieve(int n);
vector<int> getFactorization(int x);
vector<int> getfactors(int x);
void naive_subset_search(int k, vector<int>& arr);
void radix_sort(vector<int>& arr);

//some templates
void out(){cout << '\n';return;}
template<typename T, typename... Args>
void out(const T& a, const Args&... args) {cout << a << ' '; out(args...);}

void in(){return;}
template<typename T, typename... Args>
void in(T& a, Args&... args) {cin >> a; in(args...);}

//all function definitions
int ilog(int n, int base)
{
    assert(n > 0);
    int prod = base;
    int p = 0;
    while (1)
    {
        if (n < prod)
        {
            return p;
        }
        prod *= base;
        p++;
    }
}

int power(int x, int y)
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

//========================Debug======================================
 
//void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

//template<int mod>
//void __print(const modint<mod>& x) {cerr << x.v;}
 
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}

int total_time = 0;

#ifdef local
    #define debug(x...)               \
        cerr << "[" << #x << "] = ["; \
        _print(x)
    #define input cerr << "===================\nInput: \n"
    #define output cerr << "Output: \n"; clk1
    #define spacing cerr << "===================\n"
    #define clk1 auto start = steady_clock::now()
    #define clk2 auto finish = steady_clock::now(); total_time += duration_cast<milliseconds>(finish - start).count(); clkdur
    #define clk3 cerr << "\nTotal time elapsed: " << total_time << '\n'
    #define clkdur cerr << "\nTime elapsed: " << duration_cast<milliseconds>(finish - start).count() << '\n'
#else
    #define debug(x...)
    #define input
    #define output
    #define spacing
    #define clk1
    #define clk2
    #define clk3
    #define clkdur
#endif

//==================================================================

int tc = 1;
void solve();

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    spacing;
    int t = 1;
    cin >> t;
    for (tc = 1; tc <= t; tc++){
        solve();
    }
    spacing;
    clk3;
    return 0;
}

//mi grh;
//vb visited;

void solve()
{

}
