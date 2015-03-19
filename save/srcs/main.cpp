#include <main.hpp>

int				main(int ac, char **av) {
	Npuzzle 	* project = new Npuzzle();
	listGrid	path;

	try {
		check_input(--ac, ++av);
		project->fillGrid(av[0]);
		path = project->solver();
		project->printEnd(path);
	}
	catch (std::exception & e) {
		printf("%s\n", e.what());
	}
	return EXIT_SUCCESS;
}