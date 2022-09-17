#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k;
    vector<float> inserted;
    cout << "Enter the number of sequence elements: ";
    cin >> n;
    inserted.reserve(n);

    cout << "Enter the elements: " << endl;

    for (int i = 0; i < n; i++) {
        cout << "[" << i << "]:";
        cin >> inserted[i];
    }

    for (int i = 1; i < n; i++) {
        k = i-1;
        while (k > 0, inserted[k] > inserted[k + 1]) {
            swap (inserted[k], inserted[k+1]);
            if (k > 0){
                k--;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << inserted[i] << endl;
    }
    return 0;
}
