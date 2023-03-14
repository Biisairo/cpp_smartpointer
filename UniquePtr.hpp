#ifndef __UNIQUEPTR_HPP__
#define __UNIQUEPTR_HPP__

#include <cstddef>
#include <stdexcept>

#include "Move.hpp"

namespace ft
{
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
			UniquePtr(UniquePtr* tmp)
			: _ptr(tmp->_ptr) {
				tmp->_ptr = 0;
			}
			~UniquePtr() {
				delete _ptr;
			}
			UniquePtr& operator=(void* ptr) {
				(void)ptr;
				reset();
				return *this;
			}
			UniquePtr& operator=(UniquePtr* tmp) {
				_ptr = tmp->_ptr;
				tmp->_ptr = 0;
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
					delete tmp;
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
			element_type& operator*() {
				return *_ptr;
			}
			element_type* operator->() {
				return _ptr;
			}
			element_type& operator[](std::size_t n) {
				return *(_ptr + n);
			}

			//// 왜??
			UniquePtr(const UniquePtr<element_type>& ori) {
				(void)ori;
				throw std::logic_error("Unique Pointer cannot be copied");
			}
			UniquePtr& operator=(const UniquePtr<element_type>& ori) {
				(void)ori;
				throw std::logic_error("Unique Pointer cannot be copied");
			}
			////
		private:
			element_type* _ptr;
	};

	template <typename _T>
	class UniquePtr<_T[]> {
		public:
			typedef _T element_type;

		public:
			UniquePtr()
			: _ptr(0)
			{}
			UniquePtr(element_type* ptr)
			: _ptr(ptr)
			{}
			UniquePtr(UniquePtr* tmp)
			: _ptr(tmp->_ptr) {
				tmp->_ptr = 0;
			}
			~UniquePtr() {
				delete[] _ptr;
			}
			UniquePtr& operator=(void* ptr) {
				(void)ptr;
				reset();
				return *this;
			}
			UniquePtr& operator=(UniquePtr* tmp) {
				_ptr = tmp->_ptr;
				tmp->_ptr = 0;
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
					delete[] tmp;
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
			element_type& operator*() {
				return *_ptr;
			}
			element_type* operator->() {
				return _ptr;
			}
			element_type& operator[](std::size_t n) {
				return *(_ptr + n);
			}

			//// 왜??
			UniquePtr(const UniquePtr<element_type>& ori) {
				(void)ori;
				throw std::logic_error("Unique Pointer cannot be copied");
			}
			UniquePtr& operator=(const UniquePtr<element_type>& ori) {
				(void)ori;
				throw std::logic_error("Unique Pointer cannot be copied");
			}
			////
		private:
			element_type* _ptr;
	};
}

#endif
