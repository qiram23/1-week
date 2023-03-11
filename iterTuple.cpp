
#include<iostream>
#include<tuple>

using namespace std;

template <typename T>
void print_element(const T& x) {
  cout << x << " ";
};

template <typename TupleT, size_t... Is>
void print_tuple_manual(const TupleT& tp, index_sequence<Is...>) {
  (print_elem(get<Is>(tp)), ...);
}

template <typename TupleT, size_t TupSize = tuple_size_v<TupleT>>
void print_tuple(const TupleT& tp) {
  print_tuple_manual(tp, make_index_sequence<TupSize>{});
}


int main() 
{
  tuple a{1, a, tupel};
  print_tuple(a);
  cout << '\n';
}