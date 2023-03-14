#include "SharedPtr.hpp"
#include "UniquePtr.hpp"
#include "WeakPtr.hpp"
#include <iostream>
#include <memory>

template <typename T>
void print(ft::SharedPtr<T>& tmp) {
	std::cout << "Reference Count : " << tmp.use_count() << std::endl;
}

template <typename T>
void print(ft::WeakPtr<T>& tmp) {
	std::cout << "Reference Count : " << tmp.use_count() << std::endl;
}

int main() {
	// ft::UniquePtr<int[]> test(new int[10]);
	// ft::UniquePtr<int[]> test2 = ft::move(test);

	// ft::UniquePtr<int> test(new int(10));
	// std::cout << *test << std::endl;
	// ft::UniquePtr<int> test2 = ft::move(test);
	// std::cout << *test2 << std::endl;
	// std::cout << *test << std::endl;
	// ft::UniquePtr<int> err(test);

	// ft::UniquePtr<int[]> atest(new int[10]);
	// atest[0] = 1;
	// atest[1] = 2;
	// std::cout << atest[0] << std::endl;
	// std::cout << atest[1] << std::endl;
	// ft::UniquePtr<int[]> atest2 = ft::move(atest);
	// std::cout << atest2[0] << std::endl;
	// std::cout << atest2[1] << std::endl;
	// std::cout << test[0] << std::endl;
	// ft::UniquePtr<int[]> err(atest);

	// std::unique_ptr<int> st1(new int(10));
	// std::cout << *st1.get() << std::endl;
	// std::unique_ptr<int> st2(st1);

	ft::SharedPtr<int> test(new int(10));
	print(test);
	ft::SharedPtr<int> test2(test);
	print(test);
	ft::SharedPtr<int> test3(new int(42));
	test2 = test3;
	print(test);
	print(test2);
	print(test3);
	ft::WeakPtr<int> test4(test3);
	print(test4); // controlblock 에 shr refcount, weak refcount 따로?
}
