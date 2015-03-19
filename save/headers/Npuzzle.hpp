#ifndef NPUZZLE_HPP
# define NPUZZLE_HPP

# include <main.hpp>

class Npuzzle {

private:
	Grid				_grid;
	Grid 				_soluce;
	int					_gridSize;
	mapNode				_mapOpen;
	mapNode				_mapClosed;

public:

	/* Npuzzle.cpp */

	Npuzzle(void);
	Npuzzle(Grid grid);
	virtual ~Npuzzle(void);

	void				setGrid(Grid const & grid);
	void				setSoluce(Grid const & soluce);
	void				setGridSize(int const & gridSize);
	void				setMapOpen(mapNode const & mapOpen);
	void				setMapClosed(mapNode const & mapClosed);

	Grid getGrid(void) const;
	Grid getSoluce(void) const;
	int  getGridSize(void) const;
	mapNode  getMapOpen(void) const;
	mapNode  getMapClosed(void) const;

	void				fillGrid(char * filename);
	void				printGrid(Grid grid) const;
	void				printMap(mapNode map) const;

	/* Npuzzle_solver.cpp */

	listGrid			solver(void);
	Grid 				generateSoluce(int size);
	Point				findPos(Grid grid, int target);
	listGrid			recoverPath(mapNode mapClosed, Grid startGrid);

	/* Npuzzle_heuristiques.cpp */

	int					manhattan(Grid src, Grid dest);
	int					euclidien(Grid src, Grid dest);

	/* Npuzzle_Astar.cpp */

	void				openToClosed(Grid grid);
	void 				checkAdjacent(Grid current);
	bool 				equalGrid(Grid grid1, Grid grid2, int size);
	Grid 				copyGrid(Grid src, int size);
	Grid 				moveUp(Grid current, Point zeroPos, int size);
	Grid 				moveRight(Grid current, Point zeroPos, int size);
	Grid 				moveDown(Grid current, Point zeroPos, int size);
	Grid 				moveLeft(Grid current, Point zeroPos, int size);
	bool				onMap(Grid current, mapNode map);
	Node 				findOnMap(Grid grid, mapNode map);
	Grid 				bestGridInMap(mapNode map);

	/* Npuzzle_end.cpp */

	void 				printEnd(listGrid path);
};

#endif