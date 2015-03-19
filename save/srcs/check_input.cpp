#include <main.hpp>

void				check_input(int ac, char **av) {
	if (ac != 1)
		throw Usage();

	struct stat 	buffer;

	if (stat(av[0], &buffer) != 0)
		throw FileNotExist();
}
