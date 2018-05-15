/*
 * This file is a part of the LICPP project,
 * licensed under MIT liense.
 * Please read LICENSE.TXT and README.MKD for more information.
 */

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

  template <typename L>
    struct get_return : get_return<decltype(&L::operator())>
  {};
  template <typename C, typename ...A>
    struct get_return <void (C::*)(A...)>{
      template <typename L>
        Cons<bool, nullptr_t> * operator()(L fn){
          fn();
          return cons(false, nullptr);
        }
    };
  template <typename R, typename C, typename ...A>
    struct get_return <R (C::*)(A...)>{
      template <typename L>
        Cons<bool, R> * operator()(L fn){
          return cons(true, fn());
        }
    };
  template <typename C, typename ...A>
    struct get_return <void (C::*)(A...) const>{
      template <typename L>
        Cons<bool, nullptr_t> * operator()(L fn){
          fn();
          return cons(false, nullptr);
        }
    };
  template <typename R, typename C, typename ...A>
    struct get_return <R (C::*)(A...) const>{
      template <typename L>
        Cons<bool, R> * operator()(L fn){
          return cons(true, fn());
        }
    };

  template <typename T, typename U, typename ... Ss>
    auto multiple_value_bind(Cons<T, U> * c, Ss ... sym){
      if(!std::is_same<typename _values_t<Cons<T, U> * >::type,
          typename _list_t<Ss ...>::type>::value){
        throw "The type of Pointer-List does not match the type of the given List";
      }
      if(!listp(c)){
        throw "MULTIPLE-VALUE-BIND requires a proper list as its first argument.";
      }
      using sym_lst_t = typename _values_t<Cons<T, U> * >::type;
      sym_lst_t sym_lst = list(sym...);
      auto orig = mapcar([](auto p){ return *p; }, sym_lst);
      _mvb(c, sym_lst);
      return [orig, sym_lst](auto fn){
        auto retval = get_return<decltype(fn)>()(fn);
        _mvb(orig, sym_lst);
        if(car(retval)){
          return cdr(retval);
        }
        typename _cdr_t<decltype(retval)>::type ret = 0;
        return ret;
      };
    }
};

#endif
