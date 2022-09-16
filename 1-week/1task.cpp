#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string name, cashback;
    int price, temp;
    bool b_cashback;

    cout << "Product's name: ";
    cin >> name;
    cout << "Product's price: ";
    cin >> price;
    cout << "Is cash-back available for this product? (true/false): ";
    cin >> cashback;
    b_cashback = (cashback == "true");
    cout << "Maximum storing temperature: ";
    cin >> temp;

    cout << endl;
    cout << name << endl;

    cout.unsetf(ios::dec);
    cout.setf(ios::hex | ios::uppercase);
    cout.setf(ios::left);
    cout.width(17);
    cout.fill('.');
    cout << "Price:";
    cout.setf(ios::right);
    cout << setw(8) << setfill('0') << price << ends << endl;

    cout << "Has cash-back:";
    cout.setf(ios::boolalpha);
    cout.setf(ios::right);
    cout.width(11);
    cout.fill('.');
    cout << b_cashback << endl;

    cout << "Max temperature:";
    cout.setf(ios::showpos);
    cout.unsetf(ios::hex | ios::uppercase);
    cout.setf(ios::dec);
    cout.setf(ios::right);
    cout.width(9);
    cout.fill('.');
    cout << temp << endl;

    return 0;
}
