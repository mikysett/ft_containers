#include "ft_containers.hpp"

int main(void) {
	std::cout << YEL << " --> test utility" << WHT << std::endl;
	test_utility();
	std::cout << YEL << " --> test vector" << WHT << std::endl;
	test_vector();
	std::cout << YEL << " --> test map" << WHT << std::endl;
	test_map();
	
	return (0);
}
