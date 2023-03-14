#include "ControlBlock.hpp"


// Construct
ft::ControlBlock::ControlBlock()
: _refCount(1)
{}

ft::ControlBlock::ControlBlock(std::size_t rc)
: _refCount(rc)
{}

ft::ControlBlock::ControlBlock(const ControlBlock& ori)
: _refCount(ori.getRefCount())
{}

// destruct
ft::ControlBlock::~ControlBlock()
{}

// operator=
ft::ControlBlock& ft::ControlBlock::operator=(const ControlBlock& ori) {
	_refCount = ori.getRefCount();
	return *this;
}

// getter setter
std::size_t ft::ControlBlock::getRefCount() const {
	return _refCount;
}

void ft::ControlBlock::setRefCount(std::size_t rc) {
	_refCount = rc;
}

// add sub
void ft::ControlBlock::add() {
	_refCount++;
}
void ft::ControlBlock::sub() {
	_refCount--;
}
