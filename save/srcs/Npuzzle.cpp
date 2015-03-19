#include <main.hpp>

Npuzzle::Npuzzle(void) {}
Npuzzle::Npuzzle(Grid grid) { setGrid(grid); }
Npuzzle::~Npuzzle(void) {}

void					Npuzzle::setGrid(Grid const & grid) { _grid = grid; }
void					Npuzzle::setSoluce(Grid const & soluce) { _soluce = soluce; }
void					Npuzzle::setGridSize(int const & gridSize) { _gridSize = gridSize; }
void					Npuzzle::setMapOpen(mapNode const & mapOpen) { _mapOpen = mapOpen; }
void					Npuzzle::setMapClosed(mapNode const & mapClosed) { _mapClosed = mapClosed; }

Grid 	 Npuzzle::getGrid(void) const { return _grid; }
Grid 	 Npuzzle::getSoluce(void) const { return _soluce; }
int 	 Npuzzle::getGridSize(void) const { return _gridSize; }
mapNode  Npuzzle::getMapOpen(void) const { return _mapOpen; }
mapNode  Npuzzle::getMapClosed(void) const { return _mapClosed; }

void					Npuzzle::fillGrid(char * filename) {
	std::ifstream 		infile(filename);
	std::string 		line;
	int 				size = 0;

	while (size == 0 and std::getline(infile, line)) {
		std::istringstream iss(line);
		line = line.substr(0, line.find('#'));
		size = atoi(line.c_str());
	}

	if (size < 3)
		throw SizeError();

	setGridSize(size);

	Grid 				grid = new int * [size];
	int 				i;
	int 				j;

	j = 0;
	while (std::getline(infile, line)) {
		grid[j] = new int [size];
		i = 0;
		while (i < size) {
			while (line[0] == ' ')
				line = line.substr(1, line.size());
			grid[j][i] = atoi(line.substr(0, line.find(' ')).c_str());
			line = line.substr(line.find(' ') + 1, line.size());
			i++;
		}
		j++;
	}
	setGrid(grid);

	return ;
}

void					Npuzzle::printGrid(Grid grid) const {
	int 				size = getGridSize();

	printf("   |");
	for (int i = 0; i < size; i++) {
		printf("%5d", i);
	}
	printf("  |\n");

	for (int i = 0; i < (size * 5) + 10; i++) {
		printf("+");
	}
	printf("\n");

	for (int j = 0; j < size; j++) {
		printf("%3d|", j);
		for (int i = 0; i < size; i++)
			printf("%5d", grid[j][i]);
		printf("  |%d\n", j);
	}

	for (int i = 0; i < (size * 5) + 10; i++) {
		printf("+");
	}
	printf("\n");

	printf("   |");
	for (int i = 0; i < size; i++) {
		printf("%5d", i);
	}
	printf("  |\n");
	return ;
}

void				Npuzzle::printMap(mapNode map) const {
	mapNode::iterator	it = map.begin();
	mapNode::iterator	ite = map.end();

	printf("%s\n", "****");
	for (; it != ite; it++)
		printGrid(it->first);
	printf("%s\n", "----");
	return;
}
