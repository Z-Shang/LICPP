#include "includes/core.hpp"
#include "includes/hacks.hpp"
#include "includes/list_utils.hpp"

#include <iostream>
#include <string>

using namespace std;
using namespace licpp;

int main(int, char**){
  var cons_1 = cons(1, 2);
  var cons_2 = cons("foo", "bar");
  var cons_3 = cons(1, "foo");
  cout << "Cons 1: " << cons_1 << endl;
  cout << "Cons 2: " << cons_2 << endl;
  cout << "Cons 3: " << cons_3 << endl;

  var list_1 = list(1, 2, 3);
  var list_2 = cons("foo", list_1);
  var list_3 = append(list_1, list_2);
  var list_4 = reverse(list_1);
  var list_5 = mapcar([](auto n) { return n + 1; }, list_1);
  var list_6 = mapcar([](auto n, auto s) { return to_string(n) + s; }, list_1, list("a", "b", "c"));
  cout << "List 1: " << list_1 << endl;
  cout << "List 2: " << list_2 << endl;
  cout << "List 3: " << list_3 << endl;
  cout << "List 4: " << list_4 << endl;
  cout << "List 5: " << list_5 << endl;
  cout << "List 6: " << list_6 << endl;

  auto [a, b, c, d] = list_2;
  cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;

   auto r = multiple_value_bind((a, b, c, d), append(list_5, list((string)"foo")),
      cout << "a: " << a << " b: " << b << " c: " << c << " d: " << d << endl;
      auto res = list(a, b, c, d);
      return res;
      );

   cout << r << endl;

   cout << licpp::apply(([](int a, int b, int c){
        return a + b + c;
       }), list_1) << endl;
  

    return 0;
}
