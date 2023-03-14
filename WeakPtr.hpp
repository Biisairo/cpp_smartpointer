#ifndef __WEAKPTR_HPP__
#define __WEAKPTR_HPP__

#include <cstddef>

#include "SharedPtr.hpp"

namespace ft
{
	template <typename _T>
	class WeakPtr
	{
		public:
			typedef _T element_type;

		public:
			WeakPtr()
			: _ptr(NULL), _controlBlock(new ControlBlock(0))
			{}
			WeakPtr(const SharedPtr<element_type>& ori)
			: _ptr(ori.get()), _controlBlock(ori._getControlBlock())
			{}
			WeakPtr(const WeakPtr<element_type>& ori)
			: _ptr(ori.get()), _controlBlock(ori._getControlBlock())
			{}
			~WeakPtr() {
				clear();
			}
			WeakPtr& operator=(const WeakPtr<element_type>& ori) {
				clear();
				_ptr = ori.get();
				_controlBlock = ori._getControlBlock();
				return *this;
			}
			WeakPtr& operator=(const SharedPtr<element_type>& ori) {
				clear();
				_ptr = ori.get();
				_controlBlock = ori._getControlBlock();
				return *this;
			}
			void reset(element_type* ptr) {
				clear();
				_ptr = ptr;
				_controlBlock = new ControlBlock();
			}
			void swap(WeakPtr& ori) {
				element_type* tmp_p;
				ControlBlock* tmp_c;
				tmp_p = _ptr;
				tmp_c = _controlBlock;
				_ptr = ori.get();
				_controlBlock = ori._getControlBlock();
				ori.get() = tmp_p;
				ori._getControlBlock() = tmp_c;
			}
			element_type* get() {
				return _ptr;
			}
			element_type& operator*() {
				return *_ptr;
			}
			element_type* operator->() const {
				return _ptr;
			}
			element_type& operator[](std::size_t n) {
				return *(_ptr + n);
			}
			std::size_t use_count() {
				return _controlBlock->getRefCount();
			}
			bool unique() const {
				return _controlBlock->getRefCount() == 1;
			}
			operator bool() const {
				get() != NULL;
			}
			ControlBlock* _getControlBlock() const {
				return _controlBlock;
			}

		private:
			void clear() {
				if (_ptr != NULL) {
					if (_controlBlock->getRefCount() == 0) {
						delete _ptr;
						delete _controlBlock;
					}
				}
				else
					delete _controlBlock;
			}

		private:
			element_type* _ptr;
			ControlBlock* _controlBlock;
	};
}

#endif
