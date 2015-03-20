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

			if nbTotal < open.size + close.size
				@nbTotal = open.size + close.size
			end

			if currentGrid == endGrid
				puts "WIN"
				path = recoverPath
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
			adjNode.h = manhattan(adj, endGrid) * 10
			adjNode.f = adjNode.g + adjNode.h
			adjNode.parent = Array.new(parent)

			if open[adj].nil?
				open[adj] = adjNode
				@nbOpen  += 1
			else
				if (adjNode.f < open[adj].f)
					open[adj] = adjNode
					@nbOpen  += 1
				end
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

	def recoverPath
		path = Array.new
		currentGrid = endGrid
		while currentGrid != startGrid
			path << currentGrid
			currentGrid = close[currentGrid].parent
		end
		puts nbOpen
		puts nbTotal
		puts path.size
	end
end
