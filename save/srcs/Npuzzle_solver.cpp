#include <main.hpp>

listGrid			Npuzzle::solver(void) {
	Grid 			current 	= getGrid();
	Grid 			startGrid	= getGrid();
	int				size    	= getGridSize();
	Grid 			soluce  	= generateSoluce(size);
	Node			startNode;
	mapNode			mapOpen;
	mapNode			mapClosed;

	mapClosed[current] = startNode;

	setMapOpen(mapOpen);
	setMapClosed(mapClosed);

	checkAdjacent(current);

	mapOpen = getMapOpen();
	mapClosed = getMapClosed();
	
	while (true) {
		current = bestGridInMap(mapOpen);

		openToClosed(current);
		checkAdjacent(current);
		mapOpen = getMapOpen();

		if (equalGrid(current, soluce, size)) {
			mapClosed = getMapClosed();
			printf("%lu\n", mapOpen.size());
			printf("%lu\n", mapClosed.size());
			return recoverPath(mapClosed, startGrid);
		}

		if (getMapOpen().empty()) {
			printf("%s\n", "No solution found");
			exit(1);
		}
	}
	exit(1);
}

Grid 				Npuzzle::generateSoluce(int size) {
	Grid 			soluce = new int * [size];

	for (int j = 0; j < size; j++) {
		soluce[j] = new int [size];
		for (int i = 0; i < size; i++)
			soluce[j][i] = -1;
	}

	int				i = 0;
	int				j = 0;
	int 			n = 1;
	int 			state = 0;

	while (n <= size * size) {
		soluce[j][i] = n++;
		if (n - 1 == size * size)
			soluce[j][i] = 0;

		if (state == 0) { // left 
			if (i + 1 >= size or soluce[j][i + 1] != -1) {
				state = 1;
				j++;
			}
			else
				i++;
		}
		else if (state == 1) {// down
			if (j + 1 >= size or soluce[j + 1][i] != -1) {
				state = 2;
				i--;
			}
			else
				j++;
		}
		else if (state == 2) {// right
			if (i - 1 >= size or soluce[j][i - 1] != -1) {
				state = 3;
				j--;
			}
			else
				i--;
		}
		else { // = 3 up
			if (j - 1 >= size or soluce[j - 1][i] != -1) {
				state = 0;
				i++;
			}
			else
				j--;
		}
	}

	setSoluce(soluce);

	return soluce;
}

Point 				Npuzzle::findPos(Grid grid, int target) {
	Point 			targetPos;

	for (int j = 0; j < getGridSize(); j++) {
		for (int i = 0; i < getGridSize(); i++) {
			if (grid[j][i] == target) {
				targetPos.y = j;
				targetPos.x = i;
				return targetPos;
			}
		}
	}
	return targetPos;
}

listGrid			Npuzzle::recoverPath(mapNode mapClosed, Grid startGrid) {
	Grid 			currentGrid = getSoluce();
	Node 			currentNode = findOnMap(currentGrid, mapClosed);
	listGrid 		path;
int i = 0;
	while (not equalGrid(currentGrid, startGrid, getGridSize())) {
		path.push_front(currentGrid);

		currentGrid = currentNode.parent;
		printf("%d\n", i);
		currentNode = findOnMap(currentGrid, mapClosed);
		printf("%d\n", i++);
	}
	path.push_front(currentGrid);

	return path;
}