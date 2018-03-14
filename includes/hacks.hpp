#ifndef __LICPP_HACKS__
#define __LICPP_HACKS__

#include "core.hpp"
#include <type_traits>

namespace licpp{
  template <typename T>
  struct _values_t {
    using type = nullptr_t;
  };
  template <typename T>
  struct _values_t <Cons<T, nil_t> * >{
    using type = Cons<T * , nil_t> *;
  };
  template <typename T, typename U>
  struct _values_t <Cons<T, U> * > {
    using type = Cons<T * , typename _values_t<U>::type> * ;
  };

  template <typename T, typename S = typename _values_t<Cons<T, nil_t> * >::type>
  void _mvb(Cons<T, nil_t> * lst, S sym){
    *(car(sym)) = car(lst);
  }
  template <typename T, typename U, typename S = typename _values_t<Cons<T, U> * >::type>
  void _mvb(Cons<T, U> * lst, S sym){
    *(car(sym)) = car(lst);
    _mvb(cdr(lst), cdr(sym));
  }

  template <typename T, typename U, typename ... Ss>
  // This requires Concepts TS (Available in GCC >= 6.1 with flag `-fconcepts`)
#ifdef __HAS_CONCEPTS__
  requires std::is_same<typename _values_t<Cons<T, U> * >::type,
                        typename _list_t<Ss ...>::type>::value &&
  _listp<Cons<T, U> * >::value
#endif
  auto multiple_value_bind(Cons<T, U> * c, Ss ... sym){
    #ifndef __HAS_CONCEPTS__
    if(!std::is_same<typename _values_t<Cons<T, U> * >::type,
       typename _list_t<Ss ...>::type>::value){
      throw "The type of Pointer-List does not match the type of the given List";
    }
    if(!listp(c)){
      throw "MULTIPLE-VALUE-BIND requires a proper list as its first argument.";
    }
    #endif
    using sym_lst_t = typename _values_t<Cons<T, U> * >::type;
    sym_lst_t sym_lst = list(sym...);
    auto orig = mapcar([](auto p){ return *p; }, sym_lst);
    _mvb(c, sym_lst);
    return [orig, sym_lst](auto fn){
      fn();
      _mvb(orig, sym_lst);
    };
  }
};

#endif
