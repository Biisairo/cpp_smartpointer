#ifndef __SHAREDPTR_HPP__
#define __SHAREDPTR_HPP__

#include <cstddef>

#include "ControlBlock.hpp"
#include "UniquePtr.hpp"

namespace ft
{
	template <typename _T>
	class SharedPtr
	{
		public:
			typedef _T element_type;

		public:
			SharedPtr()
			: _ptr(NULL), _controlBlock(new ControlBlock(0))
			{}
			SharedPtr(element_type* ptr)
			: _ptr(ptr), _controlBlock(new ControlBlock())
			{}
			SharedPtr(const SharedPtr<element_type>& ori)
			: _ptr(ori._ptr), _controlBlock(ori._controlBlock) {
				_controlBlock->add();
			}
			~SharedPtr() {
				clear();
			}
			SharedPtr& operator=(const SharedPtr<element_type>& ori) {
				clear();
				_ptr = ori._ptr;
				_controlBlock = ori._controlBlock;
				_controlBlock->add();
				return *this;
			}
			void reset(element_type* ptr) {
				clear();
				_ptr = ptr;
				_controlBlock = new ControlBlock();
			}
			void swap(SharedPtr& ori) {
				element_type* tmp_p;
				ControlBlock* tmp_c;
				tmp_p = _ptr;
				tmp_c = _controlBlock;
				_ptr = ori._ptr;
				_controlBlock = ori._controlBlock;
				ori._ptr = tmp_p;
				ori._controlBlock = tmp_c;
			}
			element_type* get() const {
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
					_controlBlock->sub();
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

	template <typename _T>
	class SharedPtr<_T[]>
	{
		public:
			typedef _T element_type;

		public:
			SharedPtr()
			: _ptr(NULL), _controlBlock(new ControlBlock())
			{}
			SharedPtr(element_type* ptr)
			: _ptr(ptr), _controlBlock(new ControlBlock())
			{}
			SharedPtr(const SharedPtr<element_type>& ori)
			: _ptr(ori._ptr), _controlBlock(ori._controlBlock) {
				_controlBlock->add();
			}
			~SharedPtr() {
				clear();
			}
			SharedPtr& operator=(const SharedPtr<element_type>& ori) {
				clear();
				_ptr = ori._ptr;
				_controlBlock = ori._controlBlock;
				_controlBlock->add();
				return *this;
			}
			void reset(element_type* ptr) {
				clear();
				_ptr = ptr;
				_controlBlock = new ControlBlock();
			}
			void swap(SharedPtr& ori) {
				element_type* tmp_p;
				ControlBlock* tmp_c;
				tmp_p = _ptr;
				tmp_c = _controlBlock;
				_ptr = ori._ptr;
				_controlBlock = ori._controlBlock;
				ori._ptr = tmp_p;
				ori._controlBlock = tmp_c;
			}
			element_type* get() const {
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
					_controlBlock->sub();
					if (_controlBlock->getRefCount() == 0) {
						delete[] _ptr;
						delete _controlBlock;
					}
				}
			}

		private:
			element_type* _ptr;
			ControlBlock* _controlBlock;
	};
}

#endif
