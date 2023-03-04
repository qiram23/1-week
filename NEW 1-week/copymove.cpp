#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

class CopyMove
{
public:
CopyMove(size_t len): len(len), data(new int[len]){vector.resize(len);}

CopyMove(const CopyMove& a): len(a.len), data(new int[a.len])
{
    vector = a.vector;
    copy(a.data, a.data + len, data);
}

CopyMove(CopyMove&&a) noexcept: data(nullptr), len(0)
{
    data = a.data;
    len = a.len;
    vector = a.vector;

    a.vector.clear();
    a.data = nullptr;
    a.len = 0;
}

~CopyMove(){if (data != nullptr){delete[] data;}}

CopyMove& operator=(const CopyMove& a)
{
    if (this != &a)
    {
        delete[] data;
        len = a.len;
        data = new int[len];
        copy(a.data, a.data + len, data);
        vector = a.vector;
    }
    return *this;
}

CopyMove& operator = (CopyMove&&a) noexcept 
{
    if (this != &a)
    {
        delete[] data;

        data = a.data;
        len = a.len;
        vector = a.vector;

        a.vector.clear();
        a.data = nullptr;
        a.len = 0;
    }
    return *this;
}

size_t len() const {return len;}

size_t len;
int* data;
vector<int> vector;
};

int main()
{
    CopyMove a(1e6), b(1e6), c(1e6), d(1e6);
    for (int i = 0; i < 1e6; i++) {a.data[i] = 1;}
    for (int i = 0; i < 1e6; i++) {c.data[i] = 1;}

    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    CopyMove e(a);

    auto time = chrono::steady_clock::now() - start;
    cout << "Copy: " << chrono::duration_cast<chrono::milliseconds>(time).count() << "ms" << endl;

    start = chrono::steady_clock::now();
    a = b;

    time = chrono::steady_clock::now() - start;
    cout << "Copy: " << chrono::duration_cast<chrono::milliseconds>(time).count() << "ms" << endl;

    start = chrono::steady_clock::now();
    CopyMove f(move(c));

    time = chrono::steady_clock::now() - start;
    cout << "Move: " << chrono::duration_cast<chrono::milliseconds>(time).count() << "ms" << endl;

    start = chrono::steady_clock::now();
    c = move(d);

    time = chrono::steady_clock::now() - start;
    cout << "Move: " << chrono::duration_cast<chrono::milliseconds>(time).count() << "ms" << endl;
};
