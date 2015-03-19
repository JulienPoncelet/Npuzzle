#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <cstdlib>
# include <cstdio>
# include <exception>
# include <sys/stat.h>
# include <list>
# include <map>
# include <vector>
# include <sstream>
# include <fstream>

class 			Npuzzle;

struct 			Point {
	int 		x;
	int 		y;
};

// typedef std::vector<int> 		intVector;
typedef int ** 					Grid;
typedef std::list<Grid>   		listGrid;

struct 			Node{
    int 		gCost;
    int 		hCost;
    int 		fCost;
    Grid 		parent;
    Point		zero;
};

typedef std::map<Grid, Node>	mapNode;

# include <npuzzle.exceptions.hpp>
# include <Npuzzle.hpp>

/* check_input.cpp */

void				check_input(int ac, char **av);

#endif