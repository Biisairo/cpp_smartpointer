#ifndef SHAREDPTR_HPP
#define SHAREDPTR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	class SharedPtr
	{
		public:
			typedef T element_type;

		public:
			SharedPtr()
			{
				_addr = nullptr;
				_link = new std::size_t(0);
				_isArray = false;
			}
			SharedPtr(element_type* addr, bool isArray = false)
			{
				_addr = addr;
				_link = new std::size_t(1);
				_isArray = isArray;
			}
			SharedPtr(const SharedPtr<element_type>& ori)
			{
				_addr = ori._getAddr();
				_link = ori._getLink();
				_isArray = ori._getIsArray();
				(*_link)++;
			}
			~SharedPtr()
			{
				(*_link)--;
				if (*_link == 0)
					clear();
			}
			SharedPtr& operator=(const SharedPtr<element_type>& ori)
			{
				if (_addr != nullptr)
				{
					(*_link)--;
					if (*_link == 0)
						clear();
				}
				_addr = ori._getAddr();
				_link = ori._getLink();
				_isArray = ori.getIsArray();
				(*_link)++;
			}
			std::size_t use_count()
			{
				return *_link;
			}
			element_type& operator*()
			{
				return *_addr;
			}
			element_type& operator[](std::size_t n)
			{
				return *(_addr + n);
			}

		private:
			element_type* _getAddr() const
			{
				return _addr;
			}
			std::size_t* _getLink() const
			{
				return _link;
			}
			bool _getIsArray() const
			{
				return _isArray;
			}
			void clear()
			{
				if (_isArray)
					delete[] _addr;
				else
					delete _addr;
				delete _link;
			}

		private:
			element_type*	_addr;
			std::size_t*	_link;
			bool		_isArray;
	};
}

#endif
