/**
 *    author: pradnesh
 *    created: 08.09.2020 16:38:00
**/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
using namespace std::chrono;

typedef long double ld;
typedef long long ll;
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef set<ll> sl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
template<class key_type, class cont = vl, class comp = less<key_type>>
using p_queue = priority_queue<key_type, cont, comp>;
template<class key_type, class comp = less<key_type>>
using oset = tree<key_type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key_type, class value_type, class comp = less<key_type>>
using omap = tree<key_type, value_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

const long double PI = 2 * acos(0.0);
const ll INF = (ll)9e18;
const ll mod1 = 998244353;
const ll mod2 = 1000000007; //10^9 + 7
#define sz(v) ll((v).size())
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define eb emplace_back
#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define mp make_pair
#define mt make_tuple
#define rep(var,start,end,interval) for(ll var=start;(interval>0 and var<end) or (interval<0 and var>=end);var+=interval)
#define nl cout << '\n'
#define yes cout << "YES\n"
#define no cout<< "NO\n"
#define google(x, y) cout << "Case #" << x << ": " << y << '\n'

template<typename T>
ostream& operator<<(ostream& stream, const vector<T>& vec)
{
    ll n = vec.size();
    for (ll i = 0; i < n; i++)
    {
        stream << vec[i] << ' ';
    }
    stream << '\n';
    return stream;
}

template<class T>
istream& operator>>(istream& stream, vector<T>& vec)
{
    ll n = vec.size();
    for (ll j = 0; j < n; j++)
    {
        stream >> vec[j];
    }
    return stream;
}

istream& operator>>(istream& stream, pll& p)
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

template<class T>
class matrix
{
public:
    matrix(){}
    matrix(ll rows)
    {
        arr = vector<vector<T> >(rows);
    }
    matrix(ll rows, ll cols)
    {
        arr = vector<vector<T> >(rows, vector<T>(cols));
    }
    matrix(ll rows, ll cols, T val)
    {
        arr = vector<vector<T> >(rows, vector<T>(cols, val));
    }
    void out()
    {
        for (auto& i : arr)
        {
            cout << i;
        }
    }
    void in()
    {
        for (auto& i : arr)
        {
            cin >> i;
        }
    }
    vector<T>& operator[](ll row)
    {
        vector<T>& tmp = arr[row];
        return tmp;
    }
    ll n, m;
    vector<vector<T> > arr;
};
typedef matrix<ll> ml;
typedef matrix<bool> mb;
typedef matrix<ld> mld;
typedef matrix<pll> mpll;

//all function prototypes
ll ilog(ll n, ll base);
ll power(ll, ll);

void InverseofNumbers(ll, ll); //separating out to a group
void InverseofFactorial(ll, ll);
void factorialmod(ll, ll);
ll ncrmod(ll n, ll r, ll p);

ll ncr(ll n, ll r);
tuple<ll, ll, ll> euclid(ll a, ll b);
ll modInverse(ll n, ll p);
ll phi(ll n);
bool checkprime(ll p);
ll power_mod(ll x, ll y, ll p);
void prime_generator(ll n);
void sieve(ll n);
vector<ll> getFactorization(ll x);
vector<ll> getfactors(ll x);
void naive_subset_search(ll k, vl& arr);
void radix_sort(vector<ll>& arr);

//some templates
void out(){cout << '\n';return;}
template<typename T, typename... Args>
void out(const T& a, const Args&... args) {cout << a << ' '; out(args...);}

void in(){return;}
template<typename T, typename... Args>
void in(T& a, Args&... args) {cin >> a; in(args...);}

template<typename T>
T max1(T a, T b){return max(a, b);}
template<typename T, typename... Args>
T max1(T a, Args... args) {return max(a, max1(args...));}

template<typename T>
T min1(T a, T b){return min(a, b);}
template<typename T, typename... Args>
T min1(T a, Args... args) {return min(a, min1(args...));}

//all function definitions
ll ilog(ll n, ll base)
{
    ll prod = base;
    ll p = 0;
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

ll power(ll x, ll y)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x);
        y = y >> 1;
        x = (x * x);
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    if (p == mod1 || p == mod2)
    {
        return power_mod(n, p-2, p);
    }
    //return power_mod(n, phi(p) - 1, p); when p is not prime
}

ll power_mod(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

//========================Debug======================================
 
void __print(int x) { cerr << x; }
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

ll total_time = 0;

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

ll tc = 1;
void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    spacing;
    ll t = 1;
    cin >> t;
    for (tc = 1; tc <= t; tc++){
        solve();
    }
    spacing;
    clk3;
    return 0;
}

ml grh;
vb visited;

void solve()
{
    input;
    output;
    clk2;
}
