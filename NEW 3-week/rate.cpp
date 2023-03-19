#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <chrono>
#include <algorithm>

using namespace std;

int main()
{
  const int N = 50000;
  int cont[3*N];
  for (int i = 0; i < 3*N; i++) { cont[i] = rand(); }

  chrono::steady_clock::time_point start = chrono::steady_clock::now();
  set<int> Set;
  for (int i = 0; i < N; i++) { Set.insert(cont[i]); }
  auto Time1 = chrono::steady_clock::now() - start;
  cout << "set time: " << chrono::duration_cast<chrono::milliseconds>(Time1).count() << " ms" << endl;

  start = chrono::steady_clock::now();
  vector<int> Vect;
  for (int i = 0; i < N; i++) { Vect.push_back(cont[i]); }
  sort(Vect.begin(), Vect.end());
  auto Time2 = chrono::steady_clock::now() - start;
  cout << "vector time: " << chrono::duration_cast<chrono::milliseconds>(Time2).count() << " ms" << endl;

  start = chrono::steady_clock::now();
  int Arr[N];
  for (int i = 0; i < N; i++) { Arr[i] = cont[i]; }
  sort(Arr, Arr + N);
  auto Time3 = chrono::steady_clock::now() - start;
  cout << "array time: " << chrono::duration_cast<chrono::milliseconds>(Time3).count() << " ms" << endl;

  cout << "research" << endl;
  auto dif = chrono::duration_cast<chrono::milliseconds>(Time2 - Time1).count();
  int EN = N;
  while (dif < 0)
  {
    EN += 10000;
    cout << EN << endl;
    chrono::steady_clock::time_point start = chrono::steady_clock::now();
    set<int> Set;
    for (int i = 0; i < EN; i++) { Set.insert(cont[i]); }
    auto Time1 = (chrono::steady_clock::now() - start);
    cout << "set time: " << chrono::duration_cast<chrono::milliseconds>(Time1).count() << " ms" << endl;

    start = chrono::steady_clock::now();
    vector<int> Vect;
    for (int i = 0; i < EN; i++) { Vect.push_back(cont[i]); }
    sort(Vect.begin(), Vect.end());
    auto Time2 = (chrono::steady_clock::now() - start);
    cout << "vector time: " << chrono::duration_cast<chrono::milliseconds>(Time2).count() << " ms" << endl;
    auto dif = chrono::duration_cast<chrono::milliseconds>(Time2 - Time1).count();
    cout << dif << endl;
  }
    return 0;
}

// порогового значения при одном и том же наборе данных не найдено


