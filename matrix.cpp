template<class T>
class matrix
{
public:
    matrix(){}
    matrix(const ll& rows)
    {
        arr = vector<vector<T> >(rows);
    }
    matrix(const ll rows, const ll& cols)
    {
        arr = vector<vector<T> >(rows, vector<T>(cols));
    }
    matrix(const ll& rows, const ll& cols, const T& val)
    {
        arr = vector<vector<T> >(rows, vector<T>(cols, val));
    }
    friend ostream& operator<<(ostream& os, const matrix& m)
    {
        const auto& vec = m.arr;
        for (auto& i : vec)
        {
            os << i;
        }
        return os;
    }
    friend istream& operator>>(istream& is, matrix& m)
    {
        auto& vec = m.arr;
        for (auto& i : vec)
        {
            is >> i;
        }
        return is;
    }
    vector<T>& operator[](const ll& row)
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
