#ifndef __LICPP_LIST_UTILS__
#define __LICPP_LIST_UTILS__

#include "core.hpp"
#include <type_traits>
#include <iostream>

namespace licpp{
  template <typename T, typename U>
  struct _append_t{
    using type = nullptr_t;
  };
  template <typename T, typename U>
  struct _append_t<nil_t, Cons<T, U> * >{
    using type = Cons<T, U> *;
  };
  template <typename T, typename U>
  struct _append_t<Cons<T, U> *, nil_t>{
    using type = Cons<T, U> *;
  };
  template <typename T, typename S, typename Y>
  struct _append_t<T, Cons<S, Y> * >{
    using type = Cons<T, Cons<S, Y> * > * ;
  };
  template <typename T, typename S, typename Y>
  struct _append_t<Cons<T, nil_t> * , Cons<S, Y> * >{
    using type = Cons<T, Cons<S, Y> * > * ;
  };
  template <typename T, typename U, typename S, typename Y>
  struct _append_t<Cons<T, U> *, Cons<S, Y> * >{
    using type = Cons<T, typename _append_t<U, Cons<S, Y> * >::type> *;
  };
  template <typename S, typename Y>
  Cons<S, Y> * _append(nil_t, Cons<S, Y> * b){
    return b;
  }
  template <typename T, typename U>
  Cons<T, U> * _append(Cons<T, U> * a, nil_t){
    return a;
  }
  template <typename T, typename U, typename S, typename Y,
            typename R = typename _append_t<Cons<T, U> *, Cons<S, Y> *>::type>
  R _append(Cons<T, U> * a, Cons<S, Y> * b){
    return cons(car(a), _append(cdr(a), b));
  }
  template <typename T, typename U, typename S, typename Y>
  auto append(Cons<T, U> * a, Cons<S, Y> * b){
    if(listp(a) && listp(b)){
      return _append(a, b);
    }
    throw "APPEND only works on proper lists.";
  }

  template <typename T>
  struct _reverse_t {
    using type = nullptr_t;
  };
  template <>
  struct _reverse_t <nil_t> {
    using type = nil_t;
  };
  template <typename T>
  struct _reverse_t <Cons<T, nil_t> *>{
    using type = Cons<T, nil_t> *;
  };
  template <typename T, typename U>
  struct _reverse_t <Cons<T, Cons<U, nil_t> * > *>{
    using type = Cons<U, Cons<T, nil_t> *> *;
  };
  template <typename T, typename U>
  struct _reverse_t <Cons<T, U> *>{
    using type = typename _append_t<typename _reverse_t<U>::type, Cons<T, nil_t> * >::type;
  };
  nil_t _reverse(nil_t){
    return nil;
  }
  template <typename T, typename U, typename R = typename _reverse_t<Cons<T, U> *>::type>
  R _reverse(Cons<T, U> * lst){
    return append(_reverse(cdr(lst)), list(car(lst)));
  }
  template <typename T, typename U>
  auto reverse(Cons<T, U> * lst){
    if(listp(lst)){
      return _reverse(lst);
    }
    throw "APPEND only works on proper lists.";
  }

  template <typename T, typename U, typename ...Us>
  struct _mapcar_t {};
  template <typename F>
  struct _mapcar_t<F, nil_t>{
    using type = nil_t;
  };
  template <typename F, typename T>
  struct _mapcar_t<F, Cons<T, nil_t> *>{
    using type = Cons<typename std::result_of<F&(T)>::type, nil_t> *;
  };
  template <typename F, typename T, typename U>
  struct _mapcar_t<F, Cons<T, U> *>{
    using type = Cons<typename std::result_of<F&(T)>::type, typename _mapcar_t<F, U>::type> * ;
  };
  template <typename F, typename ...S>
  struct _packed_result_t{
    using type = typename std::result_of<F&(S...)>::type;
  };
  template <typename F, typename T, typename ...S>
  struct _mapcar_t<F, Cons<T, nil_t> *, S...>{
    using type = Cons<typename _packed_result_t<F, T, typename _car_t<S>::type ...>::type,
                      nil_t> * ;
  };
  template <typename F, typename T, typename U, typename ...S>
  struct _mapcar_t<F, Cons<T, U> *, S...>{
    using type = Cons<typename _packed_result_t<F, T, typename _car_t<S>::type ...>::type,
                      typename _mapcar_t<F, U, typename _cdr_t<S>::type ...>::type> *;
  };

  template <typename F, typename T>
  auto _mapcar(F fn, Cons<T, nil_t> * lst){
    return list(fn(car(lst)));
  }
  template <typename F, typename T, typename U,
            typename R = typename _mapcar_t<Cons<T, U>*, F>::type>
  R _mapcar(F fn, Cons<T, U> * lst){
    return cons(fn(car(lst)), _mapcar(fn, cdr(lst)));
  }
  template <typename F, typename T, typename ...S>
  auto _mapcar(F fn, Cons<T, nil_t> * lst, S... rest){
    return list(fn(car(lst), car(rest)...));
  }
  template <typename F, typename T, typename U, typename ...S>
  auto _mapcar(F fn, Cons<T, U> * lst, S... rest){
    return cons(fn(car(lst), car(rest)...), _mapcar(fn, cdr(lst), cdr(rest)...));
  }
  template <typename F, typename T, typename U>
  auto mapcar(F fn, Cons<T, U> * lst){
    if(listp(lst)){
      return _mapcar(fn, lst);
    }
    throw "MAPCAR only works on proper list.";
  }
  template <typename F, typename T, typename U, typename ...S>
  auto mapcar(F fn, Cons<T, U> * lst, S... rest){
    if(listp(lst)){
      return _mapcar(fn, lst, rest...);
    }
    throw "MAPCAR only works on proper list.";
  }
};

#endif
