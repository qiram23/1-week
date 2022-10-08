#include <iostream>
#include <algorithm>

using namespace std;
auto SortAsc(int a, int b)
{
    return a < b;
}

auto SortDesc(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    cout << "Enter the amount of numbers: ";
    cin >> n;
    int arr[n];
    cout << "Enter values for array: " << endl;
    for (int i = 0; i < n; i++){
        cout << "[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\n";

    cout << "Sort ascending: " << endl;

    sort (arr, arr + n, SortAsc);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << "\n\n";

    cout << "Sort descending: " << endl;

    sort (arr, arr + n, SortDesc);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
