module Solver
	def solvePuzzle
		currentGrid = startGrid
		raise "Already soluced" if (currentGrid == endGrid)

		@close[currentGrid] = Node.new
		@close[currentGrid].g = 0
		checkAdjacents(currentGrid)
		while 42
			currentGrid = open.min_by { |k, v| v.f}.first
			close[currentGrid] = open.delete currentGrid
			checkAdjacents(currentGrid)

			if currentGrid == endGrid
				puts "WIN"
				exit
			end

			if open.size == 0
				puts "FAIL"
				exit
			end
		end
	end

	def checkAdjacents(parent)
		adjacents = generateAdjacents(parent)

		adjacents.each do |adj|
			next if not close[adj].nil?

			adjNode = Node.new
			adjNode.g = close[parent].g + 2
			adjNode.h = manhattan(adj, endGrid)
			adjNode.f = adjNode.g + adjNode.h
			adjNode.parent = Array.new(parent)

			if open[adj].nil?
				open[adj] = adjNode
			else
				open[adj] = adjNode if (adjNode.f < open[adj].f)
			end
		end
	end

	def generateAdjacents(grid)
		adjacents = Array.new
		x, y 			= b(findPos(grid, 0))

		if (y + 1 < size) # Can go Right
			newGrid = Array.new(grid)
			tmp = grid[a(x, y + 1)]
			newGrid[a(x, y)] = tmp
			newGrid[a(x, y + 1)] = 0
			adjacents << newGrid
		end

		if (x - 1 >= 0) # Can go Up
			newGrid = Array.new(grid)
			tmp = grid[a(x - 1, y)]
			newGrid[a(x, y)] = tmp
			newGrid[a(x - 1, y)] = 0
			adjacents << newGrid
		end

		if (y - 1 >= 0) # Can go Left
			newGrid = Array.new(grid)
			tmp = grid[a(x, y - 1)]
			newGrid[a(x, y)] = tmp
			newGrid[a(x, y - 1)] = 0
			adjacents << newGrid
		end

		if (x + 1 < size) # Can go Down
			newGrid = Array.new(grid)
			tmp = grid[a(x + 1, y)]
			newGrid[a(x, y)] = tmp
			newGrid[a(x + 1, y)] = 0
			adjacents << newGrid
		end

		adjacents
	end
end
