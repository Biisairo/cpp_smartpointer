#ifndef __SHAREDPTR_HPP__
#define __SHAREDPTR_HPP__

#include <cstddef>

namespace ft
{
	template <typename _T>
	class SharedPtr
	{
		public:
			typedef _T element_type;

		public:
			SharedPtr() {
				_ptr = 0;
				_link = new std::size_t(0);
				_isArray = false;
			}
			SharedPtr(element_type* ptr, bool isArray = false) {
				_ptr = ptr;
				_link = new std::size_t(1);
				_isArray = isArray;
			}
			SharedPtr(const SharedPtr<element_type>& ori) {
				_ptr = ori._getPtr();
				_link = ori._getLink();
				_isArray = ori._getIsArray();
				(*_link)++;
			}
			~SharedPtr() {
				(*_link)--;
				if (*_link == 0)
					clear();
			}
			SharedPtr& operator=(const SharedPtr<element_type>& ori) {
				if (_ptr != 0)
 {
					(*_link)--;
					if (*_link == 0)
						clear();
				}
				_ptr = ori._getPtr();
				_link = ori._getLink();
				_isArray = ori.getIsArray();
				(*_link)++;
			}
			std::size_t use_count() {
				return *_link;
			}
			element_type& operator*() {
				return *_ptr;
			}
			element_type& operator[](std::size_t n) {
				return *(_ptr + n);
			}
			element_type* operator->() const {
				return _ptr;
			}

		private:
			element_type* _getPtr() const {
				return _ptr;
			}
			std::size_t* _getLink() const {
				return _link;
			}
			bool _getIsArray() const {
				return _isArray;
			}
			void clear() {
				if (_isArray)
					delete[] _ptr;
				else
					delete _ptr;
				delete _link;
			}

		private:
			element_type*	_ptr;
			std::size_t*	_link;
			bool		_isArray;
	};
}

#endif
