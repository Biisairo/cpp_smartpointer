#ifndef __CONTROLBLOCK_HPP__
#define __CONTROLBLOCK_HPP__

#include <cstddef>

namespace ft {
	class ControlBlock {
		public:
			ControlBlock();
			ControlBlock(std::size_t rc);
			ControlBlock(const ControlBlock& ori);
			~ControlBlock();
			ControlBlock& operator=(const ControlBlock& ori);

			std::size_t getRefCount() const;
			void setRefCount(std::size_t rc);

			void add();
			void sub();

		private:
			std::size_t _refCount;
	};
}

#endif
