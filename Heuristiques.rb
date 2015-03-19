module Heuristiques
	def manhattan(grid1, grid2)
		distance = 0
		(0...size * size).each do |m|
			x1, y1 = b(m)
			x2, y2 = b(findPos(grid2, grid1[m]))
			distance += (x1 - x2).abs
			distance += (y1 - y2).abs
		end

		distance
	end
end
