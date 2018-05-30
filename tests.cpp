#include "includes/core.hpp"
#include "includes/base_hacks.hpp"
#include "includes/hacks.hpp"
#include "includes/list_utils.hpp"

#include <iostream>
#include <string>
#include <functional>

using namespace std;
namespace l = licpp;

using namespace l;

int main(int, char**){
  var cons_1 = l::cons(1, 2);
  var cons_2 = l::cons("foo", "bar");
  var cons_3 = l::cons(1, "foo");
  cout << "Cons 1: " << cons_1 << endl;
  cout << "Cons 2: " << cons_2 << endl;
  cout << "Cons 3: " << cons_3 << endl;

  auto test = [](int a, std::string b) { return to_string(a) + b; };

  var list_1 = l::list(1, 2, 3);
  var list_2 = l::cons("foo", list_1);
  var list_3 = l::append(list_1, list_2);
  var list_4 = l::reverse(list_1);
  var list_5 = l::mapcar([](auto n) { return n + 1; }, list_1);
  var list_6 = l::mapcar(test, list_1, l::list("a", "b", "c"));
  //var list_6 = l::mapcar([](auto n, auto s) { return to_string(n) + s; }, list_1, l::list("a", "b", "c"));
  cout << "List 1: " << list_1 << endl;
  cout << "List 2: " << list_2 << endl;
  cout << "List 3: " << list_3 << endl;
  cout << "List 4: " << list_4 << endl;
  cout << "List 5: " << list_5 << endl;
  cout << "List 6: " << list_6 << endl;
  cout << length(list_6) << endl;
  //cout << length(cons_2) << endl; // Should result in error
  //
  cout << "Nth 3: " << nth<3>(list_3) << endl;
  cout << "Apply test (123, \"asd\"): " << apply(test, l::list(123, (string)"asd")) << endl;

  int v1, v2, v3;
  string v4;
  cout << l::multiple_value_bind(l::append(list_5, l::list((string)"foo")), &v1, &v2, &v3, &v4)([&](){
      cout << "v1: " << v1 << " v2: " << v2 << " v3: " << v3 << " v4: " << v4 << endl;
      return l::list(v4, v1, v2, v3);
    }) << endl;

  var list_7 = l::list(1, 2, 3, 4, 5);

  auto add2 = [](auto a, auto b){ return a + b; };
  auto sub2 = [](auto a, auto b){ return a - b; };

  cout << l::foldl(add2, 0, list_7) << endl;
  cout << l::foldr(add2, 0, list_7) << endl;
  cout << l::foldl(sub2, 0, list_7) << endl;
  cout << l::foldr(sub2, 0, list_7) << endl;

  return 0;
}
