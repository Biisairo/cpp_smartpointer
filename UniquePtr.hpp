#ifndef __UNIQUEPTR_HPP__
#define __UNIQUEPTR_HPP__

#include <cstddef>

#include <iostream>

namespace ft
{
	struct ForMove {
		void* _ptr;
		bool _isArray;
	};

	template <typename _T>
	struct defaultDelete {
		void operator()(_T* ptr) {
			delete ptr;
		}
	};

	template <typename _T>
	struct defaultDelete<_T[]> {
		void operator()(_T* ptr) {
			delete[] ptr;
		}
	};

	template <typename _T>
	class UniquePtr {
		public:
			typedef _T element_type;

		public:
			UniquePtr()
			: _ptr(0)
			{}
			UniquePtr(element_type* ptr)
			: _ptr(ptr)
			{}
			UniquePtr(const struct ForMove& ori) {
				_ptr = reinterpret_cast<element_type*>(ori._ptr);
			}
			~UniquePtr() {
				_del(_ptr);
			}
			UniquePtr& operator=(void* ptr) {
				(void)ptr;
				reset();
				return *this;
			}
			UniquePtr& operator=(element_type* ori) {
				reset(ori);
				return *this;
			}
			element_type* release() {
				element_type* res = _ptr;
				_ptr = 0;
				return _ptr;
			}
			void reset(element_type* ptr = 0) {
				element_type* tmp = _ptr;
				_ptr = ptr;
				if (tmp)
					_del(tmp);
			}
			void swap(UniquePtr& ori) {
				UniquePtr tmp;

				tmp._ptr = ori._ptr;
				ori._ptr = _ptr;
				_ptr = tmp._ptr;
			}
			element_type* get() {
				return _ptr;
			}
			struct defaultDelete<_T> get_deleter() {
				return _del;
			}
			element_type& operator*() {
				return *_ptr;
			}
			element_type* operator->() {
				return _ptr;
			}
			element_type& operator[](std::size_t n) {
				return *(_ptr + n);
			}

		private:
			element_type* _ptr;
			struct defaultDelete<_T> _del;

			UniquePtr(const UniquePtr<element_type>& ori) {}
			UniquePtr& operator=(const UniquePtr<element_type>& ori) {}

		// move
		private:
			template <typename _U>
			friend _U* move(UniquePtr<_U>& tmp);
	};

	template <typename _T>
	_T* move(UniquePtr<_T>& tmp) {
		_T* res = tmp._ptr;
		tmp._ptr = 0;
		return res;
	}
}

#endif
