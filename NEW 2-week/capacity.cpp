#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> vect1;
  for (int i = 0; i < 9; i++)
  {
    vect1.push_back(i);
    cout << "capacity: " << (int)vect1.capacity() << '\n';
  }

  cout << '\n';

  //åìêîñòü óäâàèâàåòñÿ ïðè êàæäîì çàïîëíåíèè ñ 1

  vector<int> vect2;
  vect2.reserve(3);
  cout << "capacity: " << (int)vect2.capacity() << '\n';

  for (int i = 0; i < 4; i++) {vect2.push_back(i);}
  cout << "capacity: " << (int)vect2.capacity() << '\n';

  cout << '\n';

  // åìêîñòü óäâàèâàåòñÿ êàæäûé ðàç, êîãäà îíà çàïîëíÿåòñÿ, íà÷èíàÿ ñ ÷èñëà,
  // óñòàíîâëåííîãî â ðåçåðâíîé ôóíêöèè

  vector<int> vect3;

  vect3.push_back(1);
  int prev = vect3.capacity();
  int now = vect3.capacity();

  while ((now = prev) or (now = prev * 2)) {
  prev = vect3.capacity();
  vect3.push_back(1e6);
  now = vect3.capacity();
  if (now == 2 * prev)
    {
    cout << "new capacity: " << now << endl;
    }
  }

  cout << "capacity: " << (int)vect3.capacity() << '\n';
  cout << "prev: " << prev << '\n';

  //ñèëüíî óâåëè÷èâàåòñÿ äî ìîìåíòà, êîãäà åìêîñòü ñòàíîâèòñÿ îòðèöàòåëüíîé

  for (int i = 0; i <10; i++)
    {
    cout << vect3[i];
    }

  vect3.push_back(1e6);

  cout << "capacity: " << (int)vect3.capacity() << '\n';
  cout << "prev: " << prev << '\n';

  return 0;
}
