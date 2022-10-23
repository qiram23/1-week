#include <iostream>
#include <iomanip>
using namespace std;

struct Date
{
  unsigned int seconds : 6;
  unsigned int minuts : 6;
  unsigned int hours :5;
  unsigned int days : 5;
  unsigned int months : 5;
  unsigned int years : 7; //from 0 to 99
};


int main()
{
  Date date;
  unsigned int q;

  cout << "Enter the date " << endl;

  cout << "day: ";
  cin >> q;
  date.days = q;

  cout << "month: ";
  cin >> q;
  date.months = q;

  cout << "years: ";
  cin >> q;
  date.years = q;

  cout << "\n\n";

  cout << "Enter the time " << endl;

  cout << "hour: ";
  cin >> q;
  date.hours = q;

  cout << "minutes: ";
  cin >> q;
  date.minuts = q;

  cout << "seconds: ";
  cin >> q;
  date.seconds = q;

  cout << "\n\n";

  cout << setw(2) << setfill('0') << date.days << "." << setw(2) << setfill('0') << date.months << "." << setw(2) << setfill('0') << date.years;
  cout << "   " << setw(2) << setfill('0') << date.hours << ":" << setw(2) << setfill('0') << date.minuts << ":" << setw(2) << setfill('0') << date.seconds;
    return 0;
}

