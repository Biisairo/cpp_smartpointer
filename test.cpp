// #include "SharedPtr.hpp"
#include "UniquePtr.hpp"
#include <iostream>
#include <memory>

int main() {
	// ft::UniquePtr<int[]> test(new int[10]);
	// ft::UniquePtr<int[]> test2 = ft::move(test);
	ft::UniquePtr<int> test(new int(10));
	ft::UniquePtr<int> test2 = ft::move(test);
}
