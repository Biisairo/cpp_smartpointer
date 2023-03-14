#ifndef __MOVE_HPP__
#define __MOVE_HPP__

namespace ft
{
	template <typename _T>
	_T* move(_T& tmp) {
		return &tmp;
	}

	template <template <typename> class _C, typename _T>
	_C<_T>* move(_C<_T>& tmp) {
		return &tmp;
	}

	template <template <typename> class _C, typename _T>
	_C<_T[]>* move(_C<_T[]>& tmp) {
		return &tmp;
	}
}

#endif
