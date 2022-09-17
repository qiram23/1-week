#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, x, start = 0, finish, mid;
    vector<int> seq;
    cout << "Enter the number of sequence elements: " << endl;
    cin >> n;
    seq.reserve(n);

    cout << "Enter the sequence: " << endl;
    for (int i = 0; i < n; i++){
        cout << "[" << i << "]:";
        cin >> seq[i];
    }

    cout << "Enter the required number: " << endl;
    cin >> x;

    finish = n-1;

    while (start < finish){
        mid = (start + finish)/2;
        if (seq[mid] == x){
            cout << "[" << mid << "]:" << x << endl;
            break;
        }
        if (seq[mid] < x){
            start = mid;
        }
        if (seq[mid] > x){
            finish = mid;
        }
        if (finish == start + 1){
            if (seq[finish] == x){
                cout << "[" << finish << "]:" << x << endl;
                break;
            }
            if (seq[start] == x){
                cout << "[" << start << "]:" << x << endl;
                break;
            }
            else {
                cout << "There is no " << x << endl;
                break;
            }

        }
    }
    if (start == finish){
        if (seq[start] == x){
            cout << "hehehe, I found you!" << endl;
        }
        else {
            cout << "youre missing" << endl;
        }
    }
    if (start > finish){
        cout << "wtf?" << endl;
    }

    return 0;
}
