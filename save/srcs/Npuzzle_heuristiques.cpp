#include <main.hpp>

int					Npuzzle::manhattan(Grid src, Grid dest) {
	int				size = getGridSize();
	int 			distance = 0;
	Point			currentPos;
	Point			wantedPos;


	for (int current = 1; current < size * size; current++) {
		currentPos = findPos(src, current);
		wantedPos = findPos(dest, current);
		distance += abs(currentPos.x - wantedPos.x);
		distance += abs(currentPos.y - wantedPos.y);
	}

	return distance;
}

int					Npuzzle::euclidien(Grid src, Grid dest) {
	int				size = getGridSize();
	int 			distance = 0;
	Point			currentPos;
	Point			wantedPos;
	int				dx;
	int				dy;

	for (int current = 1; current < size * size; current++) {
		currentPos = findPos(src, current);
		wantedPos = findPos(dest, current);
		dx = currentPos.x - wantedPos.x;
		dy = currentPos.y - wantedPos.y;
		distance += (dx * dx) + (dy * dy);
	}

	return distance;
}
