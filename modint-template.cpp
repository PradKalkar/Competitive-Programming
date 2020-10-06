template <int MOD>
struct modint {
    using M = modint;

    int v;

    modint(int _v = 0) { set_norm(_v % MOD + MOD); }
    M& set_norm(int _v) {  //[0, MOD * 2)->[0, MOD)
        v = (_v < MOD) ? _v : _v - MOD;
        return *this;
    }

    explicit operator bool() const {return v != 0;}
    M operator+(const M& a) const {return M().set_norm(v + a.v);}
    M operator+(const int& a) const {return M().set_norm(v + a);}
    M operator-(const M& a) const {return M().set_norm(v + MOD - a.v);}
    M operator-(const int& a) const {return M().set_norm(v + MOD - a);}

    M operator*(const M& a) const {return M().set_norm(v * a.v % MOD);}
    M operator*(const int& a) const {return M().set_norm(v * (a % MOD) % MOD);}

    M operator/(const M& a) const {return *this * a.inv();}
    M operator/(const int& a) const {return *this * M(a).inv();}

    M& operator+=(const M& a) {return *this = *this + a; }
    M& operator+=(const int& a) {return *this = *this + a;}

    M& operator-=(const M& a) {return *this = *this - a;}
    M& operator-=(const int& a) {return *this = *this - a;}

    M& operator*=(const M& a) {return *this = *this * a; }
    M& operator*=(const int& a) {return *this = *this * a; }

    M& operator/=(const M& a) {return *this = *this / a; }
    M& operator/=(const int& a) {return *this = *this / a; }

    M operator-() const { return M() - *this; }

    M& operator++(signed) { return *this = *this + 1; }
    M& operator--(signed) { return *this = *this - 1; }

    M pow(int n) const {
        if (n < 0) return inv().pow(-n);
        M x = *this, res = 1;
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    M inv() const { 
        int a = v, b = MOD, p = 1, q = 0, t;
        while (b != 0) {
            t = a / b;
            swap(a -= t * b, b);
            swap(p -= t * q, q);
        }
        return M(p);
    }

    bool operator==(const M& a) const { return v == a.v; }
    bool operator!=(const M& a) const { return v != a.v; }

    friend ostream& operator<<(ostream& os, const M& a) { return os << a.v; }
    friend istream& operator>>(istream& is, M& a){
        int tmp;
        is >> tmp;
        tmp %= MOD;
        if (tmp < 0) tmp += MOD;
        a.v = tmp;
        return is;
    }

    static int get_mod() { return MOD; }
};
using Mint = modint<998244353LL>;

vector<Mint> fact(1LL, 1LL);
vector<Mint> inv_fact(1LL, 1LL);

Mint C(int n, int k) { //O(n) time
    if (k < 0 || k > n) {
        return 0;
    }
    while (sz(fact) < n + 1) {
        fact.push_back(fact.back() * sz(fact));
        inv_fact.push_back((Mint)1LL / fact.back());
    }
    return fact[n] * inv_fact[k] * inv_fact[n - k];
}
