#ifndef __ENABLE_IF_HPP__
#define __ENABLE_IF_HPP__

namespace ft
{
	template <bool B, class T = void>
	struct enable_if {};

	template <class T>
	struct enable_if<true, T> {
		typedef T type;
	};

	template <class _Tp, _Tp __v>
	struct integral_constant {
		integral_constant() {std::cout << __v <<std::endl;} ////
		static const _Tp value = __v;
		typedef _Tp value_type;
		typedef integral_constant type;
		operator value_type() const {return value;}
		value_type operator ()() const {return value;}
	};

	template <class _T1, class _T2>
	struct is_convertible
	: public integral_constant<bool, __is_convertible_to(_T1, _T2)> {};


	// is array
	template <class _Tp>
	struct is_array
	: public integral_constant<bool, false> {};

	template <class _Tp>
	struct is_array<_Tp[]>
	: public integral_constant<bool, true> {};

	template <class _Tp, size_t _Np>
	struct is_array<_Tp[_Np]>
	: public integral_constant<bool, true> {};
}

#endif
