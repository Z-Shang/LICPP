#ifndef __BASE_HACKS_HPP__
#define __BASE_HACKS_HPP__

#include <type_traits>
#include <functional>
#include <utility>
#include "core.hpp"

namespace licpp {
	template <typename R, typename C, bool constp, typename ... As>
		struct _lambda_type {
			static const bool constp = constp;
			enum { arity = sizeof...(As) };
			using return_type = R;
			using arg_type = typename _list_t<As...>::type;
		};
	template <typename L>
		struct lambda_type : lambda_type<decltype(&L::operator())> {};
	template <typename R, typename C, typename ... As>
		struct lambda_type<R(C::*)(As...)> : _lambda_type<R, C, false, As...> {};
	template <typename R, typename C, typename ... As>
		struct lambda_type<R(C::*)(As...) const> : _lambda_type<R, C, true, As...> {};
};

#endif