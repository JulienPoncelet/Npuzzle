#include <main.hpp>

void						Npuzzle::printEnd(listGrid path) {
	listGrid::iterator		it  = path.begin();
	listGrid::iterator		ite = path.end();
	
	for (; it != ite; it++)
		printGrid(*it);

	return ;
}
