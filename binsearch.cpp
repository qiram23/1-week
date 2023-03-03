#include <iostream>
#include <cmath>
#include <vector>
#include <list>
#include <forward_list>
#include <iterator>

using namespace std;

template <class iter, typename T>
int BinSearch(T arr, iter start, iter finish, int key)
{
    start = arr.begin();
    finish = arr.end();
    auto mid = start + (finish - start)/2;
    while (start < finish)
    {
        mid = (start + (finish - start) / 2);
        if (*mid >= key) {finish = mid;}
        else {start = mid;}
        if (*mid == key) {return mid - arr.begin();}
    };
    return -1;
}

template <class iter, typename T>
int BinSearch_Bidirect(T arr, iter start, iter finish, int key)
{
    auto mid = arr.begin();
    int dist = arr.size();
    if (*arr.begin() == key) {return 0;}
    while (dist > 0)
    {
        int i = 0;
        auto mid = start;
        for (i = 0; i < dist / 2; i++, mid++);
        if (*mid < key)
        {
            for (i = 0; i < dist / 2; i++)
            {
                start++;
                dist -= i;
            }
        }
        else
        {
            for (i = 0; i < dist / 2; i++)
            {
                finish--;
                dist -= i;
            }
        };

        if (*mid == key)
        {
            auto finCoord = arr.begin();
            int i = 0;
            while (*finCoord != *mid)
            {
                finCoord++;
                i++;
            }
            return i;
        }
        if (dist == 1 and *start != key and *finish != key) {return -1;}
    }
}

template <class iter, typename T>
int BinSearch_Forward(T arr, iter start, iter finish, int key)
{
    auto mid = arr.begin();
    int len = 1;
    while (start != finish)
    {
        start++;
        len++;
    }
    start = arr.begin();
    int finPos = len - 1;
    if (*arr.begin() == key) {return 0;}
    while (len > 0)
    {
        int i = 0;
        auto mid = start;
        for (i = 0; i < len / 2; ++i, ++mid);
        if (*mid < key)
        {
            for (i = 0; i < len / 2; ++i, ++start);
            len = len - i;
        }
        else
        {
            for (i = 0; i < len / 2; ++i, finPos--);
            finish = arr.begin();
            for (int j = 0; j < finPos; ++j, ++finish)
            len = len - i;
        };
        if (*mid == key)
        {
            auto fin = arr.begin();
            int i = 0;
            while (*fin != key)
            {
                ++fin;
                i++;
            }
            return i;
        }
    }
    return -1;
};



int main() {

    cout << "Binary Search"<< endl;
    vector<int> v = {1, 2, 3, 4, 5};
    cout << BinSearch(v, v.begin(), v.end(), 1) << endl;

    cout << "Binary Search: bidirectional iterator" << endl;
    list<int> l = {1, 2, 3, 4, 5};
    cout << BinSearch_Bidirect(l, l.begin(), l.end(), 1) << endl;

    cout << "Binary Search: forward iterator" << endl;
    forward_list<int> fl = {1, 2, 3, 4, 5};
    cout << BinSearch_Forward(fl, fl.begin(), fl.end(), 1) << endl;
}
