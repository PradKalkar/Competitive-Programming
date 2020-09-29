template<class T>
class matrix
{
public:
    matrix(){}
    matrix(const int& rows)
    {
        arr = vector<vector<T> >(rows);
    }
    matrix(const int& rows, const int& cols)
    {
        arr = vector<vector<T> >(rows, vector<T>(cols));
    }
    matrix(const int& rows, const int& cols, const T& val)
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
    vector<T>& operator[](const int& row)
    {
        vector<T>& tmp = arr[row];
        return tmp;
    }
    int n, m;
    vector<vector<T> > arr;
};
typedef matrix<int> mi;
typedef matrix<bool> mb;
typedef matrix<ld> mld;
typedef matrix<pii> mpii;
