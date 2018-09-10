#pragma once

#include "core.hpp"

namespace licpp{

  template <typename T, typename ...A>
    struct Deferred {
      explicit Deferred (std::function<T(A...)> f) : _f(f) {}

      T force(A... args){
        return _f(args...);
      }

      std::function<T(A...)> _f;
    };
};
