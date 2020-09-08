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
using my_set = tree<key_type, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
template<class key_type, class value_type, class comp = less<key_type>>
using my_map = tree<key_type, value_type, comp, rb_tree_tag, tree_order_statistics_node_update>;

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
#define input cerr << "Input: \n"
#define output cerr << "=========================================================================\n";

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
void InverseofNumbers(ll, ll);
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

vl numinverse;
void InverseofNumbers(ll n, ll p) //p is prime
{
    numinverse.resize(n + 1);
    numinverse[0] = numinverse[1] = 1;
    for (ll i = 2; i <= n; i++)
        numinverse[i] = numinverse[p % i] * (p - p / i) % p;
}

vl factorial_inverse;
void InverseofFactorial(ll n, ll p)
{
    factorial_inverse.resize(n + 1);
    factorial_inverse[0] = factorial_inverse[1] = 1;
    for (int i = 2; i <= n; i++)
        factorial_inverse[i] = (numinverse[i] * factorial_inverse[i - 1]) % p;
}

vl fact;
//fact[i] = factorial(i) % p //O(n)
void factorialmod(ll n, ll p)
{
    fact.resize(n + 1);
    ll ans = 1;
    rep(i, 0, n+1, 1)
    {
        fact[i] = ans;
        ans = (ans * (i + 1)) % p;
    }
}

ll ncrmod(ll n, ll r, ll p)
{
    ll ans = ((fact[n] * factorial_inverse[r])
              % p * factorial_inverse[n - r])
             % p;
    return ans;
}

ll ncr(ll n, ll r)
{
    if (n < r)
        return 0;
    ll res = 1;
    if (r > n - r)
        r = n - r;
    rep(i, 0, r, 1)
    {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

tuple<ll, ll, ll> euclid(ll a, ll b)
{
    ll d1, x1, y1;
    if (b == 0)
        return { a, 1, 0 };
    else
    {
        tie(d1, x1, y1) = euclid(b, a % b);
    }
    ll d = d1, x = y1, y = x1 - a / b * y1;
    return { d, x, y };
}

ll modInverse(ll n, ll p)
{
    return power_mod(n, p - 2, p);
}

ll phi(ll n) {
    ll result = n;
    for (ll i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

bool checkprime(ll p)
{
    if (p <= 1) return false;
    bool ans = true;
    for (ll i = 2; i * i <= p; i++)
    {
        if (p % i) continue;
        ans = false;
        break;
    }
    return ans;
}

ll power_mod(ll x, ll y, ll p)
{
    if (checkprime(p)) y %= (p - 1);
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

vector<bool> is_prime;
vector<ll> primes;
void prime_generator(ll n)
{
    is_prime = vector<bool>(n + 1, false);
    vector<bool> a(n + 1, true);
    for (ll i = 2; i * i <= n; i++)
    {
        if (a[i])
        {
            for (ll j = i * i; j <= n; j += i)
            {
                a[j] = false;
            }
        }
    }
    for (ll i = 2; i <= n; i++)
    {
        if (a[i])
        {
            is_prime[i] = true;
            primes.pub(a[i]);
        }
    }
}

vector<ll> spf;
void sieve(ll n)
{
    spf = vl(n + 1);
    spf[1] = 1;
    for (ll i = 2; i <= n; i++)
        spf[i] = i;
    for (ll i = 4; i <= n; i += 2)
        spf[i] = 2;

    for (ll i = 3; i * i <= n; i++)
    {
        if (spf[i] == i)
        {
            for (ll j = i * i; j <= n; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<ll> getFactorization(ll x)
{
    vector<ll> ret;
    while (x != 1)
    {
        ret.push_back(spf[x]);
        x = x / spf[x];
    }
    return ret;
}

vector<ll> getfactors(ll x)
{
    vl ans, ans1;
    for (ll i = 1; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            ans.push_back(i);
            if (i * i != x)
                ans1.push_back(x / i);
        }
    }
    ans.insert(end(ans), rbegin(ans1), rend(ans1));
    return ans;
}

vl subset;
void naive_subset_search(ll k, vl& arr)
{
    if (k == sz(arr))
    {
        //Process subset
        //for eg we can do cout << subset
    }
    else
    {
        naive_subset_search(k + 1, arr);
        subset.pub(arr[k]);
        naive_subset_search(k + 1, arr);
        subset.pob();
    }
}

void radix_sort(vector<ll>& arr)
{
    ll d = 0;
    for (const auto& i : arr)
    {
        d = max(d, ilog(i, 10) + 1);
    }
    ll n = arr.size();
    vector<queue<ll> > digits(10);
    ll prod = 10;
    vector<ll> tmp = arr;
    while (d--)
    {
        for (ll i = 0; i < n; i++)
        {
            digits[tmp[i] % 10].push(arr[i]);
        }
        ll index = 0;
        for (ll i = 0; i < 10; i++)
        {
            while (!digits[i].empty())
            {
                arr[index] = digits[i].front();
                tmp[index] = arr[index] / prod;
                digits[i].pop();
                index++;
            }
        }
        prod *= 10;
    }
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

#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)

//==================================================================

auto clk = clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
void run_time()
{
    cerr << "Time elapsed: " << (double)(clock() - clk) / CLOCKS_PER_SEC << '\n';
}

ll tc = 1;
void solve();

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    output;
    input;
    ll t = 1;
    cin >> t;
    for (tc = 1; tc <= t; tc++){
        solve();
    }
    output;
    run_time();
    return 0;
}

ml grh;
vb visited;

void solve()
{
    output;
}
