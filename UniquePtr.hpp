#ifndef UNIQUEPTR_HPP
#define UNIQUEPTR_HPP

#include <cstddef>

namespace ft
{
	template <typename T>
	class UniquePtr
	{
		public:
			typedef T element_type;

		public:
			UniquePtr()
			{
				_addr = nullptr;
				_isMaster = false;
				_isArray = false;
			}
			UniquePtr(element_type* addr, bool isArray = false)
			{
				_addr = addr;
				_isMaster = true;
				_isArray = isArray;
			}
			UniquePtr(const UniquePtr<element_type>& ori)
			{
				// _addr = ori._getAddr();
				// _isMaster = false;
				// _isArray = ori._getIsArray();

				// error
			}
			~UniquePtr()
			{
				clear();
			}
			UniquePtr& operator=(const UniquePtr<element_type>& ori)
			{
				// clear();
				// _addr = ori._getAddr();
				// _isMaster = true;
				// ori._setIsMaster(false);
				// _isArray = ori._getISArray()

				// error
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
			bool _getIsArray() const
			{
				return _isArray;
			}
			void _setIsMaster(bool& state)
			{
				_isMaster = state;
			}
			void clear()
			{
				if (_isMaster)
				{
					if (_isArray)
						delete[] _addr;
					else
						delete _addr;
				}
			}

		private:
			element_type*	_addr;
			bool			_isMaster;
			bool			_isArray;
	};
}

#endif
