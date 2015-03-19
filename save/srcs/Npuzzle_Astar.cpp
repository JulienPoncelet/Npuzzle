#include <main.hpp>

void					Npuzzle::openToClosed(Grid current){
	mapNode				mapOpen = getMapOpen();
	mapNode				mapClosed = getMapClosed();
    Node 				node = mapOpen[current];

    mapOpen.erase(current);
    mapClosed[current] = node;

   	setMapOpen(mapOpen);
	setMapClosed(mapClosed);
    return ;
}

void 					Npuzzle::checkAdjacent(Grid current){
	listGrid			adjacents;
	Grid 				tmpGrid;
	int					size = getGridSize();
	Point 				zeroPos = findPos(current, 0);

	if ((tmpGrid = moveUp(current, zeroPos, size)) != NULL)
		adjacents.push_back(tmpGrid);
	if ((tmpGrid = moveRight(current, zeroPos, size)) != NULL)
		adjacents.push_back(tmpGrid);
	if ((tmpGrid = moveDown(current, zeroPos, size)) != NULL)
		adjacents.push_back(tmpGrid);
	if ((tmpGrid = moveLeft(current, zeroPos, size)) != NULL)
		adjacents.push_back(tmpGrid);

	listGrid::iterator	it = adjacents.begin();
	listGrid::iterator	ite = adjacents.end();
	mapNode				mapOpen = getMapOpen();
	mapNode				mapClosed = getMapClosed();
	Grid 				soluce = getSoluce();

	for (; it != ite; it++) {
		if (not onMap(*it, mapClosed)) {
			Node 		tmp;

			tmp.gCost  = mapClosed[current].gCost + manhattan(*it, current);
			tmp.hCost  = manhattan(*it, soluce);
			tmp.fCost  = tmp.gCost + tmp.hCost;
			tmp.parent = current;

			if (onMap(*it, mapOpen)) {
				if (tmp.fCost < mapOpen[*it].fCost) {
					mapOpen[*it] = tmp;
					setMapOpen(mapOpen);
				}
			}
			else {
				mapOpen[*it] = tmp;
				setMapOpen(mapOpen);
			}
		}
	}
}

bool 					Npuzzle::equalGrid(Grid grid1, Grid grid2, int size) {
	for (int j = 0; j < size; j++) {
		for (int i = 0; i < size; i++) {
			if (grid1[j][i] != grid2[j][i])
				return false;
		}
	}
	return true;
}

Grid 					Npuzzle::copyGrid(Grid src, int size) {
	Grid 				newGrid = new int * [size];

	for (int j = 0; j < size; j++) {
		newGrid[j] = new int [size];
		for (int i = 0; i < size; i++)
			newGrid[j][i] = src[j][i];
	}

	return newGrid;
}

Grid 					Npuzzle::moveUp(Grid current, Point zeroPos, int size) {
	Grid 				newGrid;
	int					x = zeroPos.x;
	int					y = zeroPos.y - 1;

	if (y < 0)
		return NULL;

	newGrid = copyGrid(current, size);
	newGrid[y + 1][x] = newGrid[y][x];
	newGrid[y][x] = 0;

	return newGrid;
}

Grid 					Npuzzle::moveRight(Grid current, Point zeroPos, int size) {
	Grid 				newGrid;
	int					x = zeroPos.x + 1;
	int					y = zeroPos.y;

	if (x >= size)
		return NULL;

	newGrid = copyGrid(current, size);
	newGrid[y][x - 1] = newGrid[y][x];
	newGrid[y][x] = 0;

	return newGrid;
}

Grid 					Npuzzle::moveDown(Grid current, Point zeroPos, int size) {
	Grid 				newGrid;
	int					x = zeroPos.x;
	int					y = zeroPos.y + 1;

	if (y >= size)
		return NULL;

	newGrid = copyGrid(current, size);
	newGrid[y - 1][x] = newGrid[y][x];
	newGrid[y][x] = 0;

	return newGrid;
}

Grid 					Npuzzle::moveLeft(Grid current, Point zeroPos, int size) {
	Grid 				newGrid;
	int					x 		= zeroPos.x - 1;
	int					y 		= zeroPos.y;

	if (x < 0)
		return NULL;

	newGrid = copyGrid(current, size);
	newGrid[y][x + 1] = newGrid[y][x];
	newGrid[y][x] = 0;

	return newGrid;
}

bool					Npuzzle::onMap(Grid current, mapNode map) {
	mapNode::iterator	it  		= map.begin();
	mapNode::iterator	ite 		= map.end();

	for (; it != ite; it++) {
		if (equalGrid(current, it->first, getGridSize()))
			return true;
	}
	return false;
}

Node 					Npuzzle::findOnMap(Grid grid, mapNode map) {
	mapNode::iterator	it  		= map.begin();
	mapNode::iterator	ite 		= map.end();

	for (; it != ite; it++) {
		if (equalGrid(grid, it->first, getGridSize()))
			return it->second;
	}
	exit(1);
}

Grid 					Npuzzle::bestGridInMap(mapNode map) {
	mapNode::iterator	it  		= map.begin();
	mapNode::iterator	ite 		= map.end();
	Grid 				bestNode 	= it->first;
	int					bestFCost 	= it->second.fCost;

	for (; it != ite; it++) {
		if (it->second.fCost < bestFCost) {
			bestNode  = it->first;
			bestFCost = it->second.fCost;
		}
	}
	return bestNode;
}
