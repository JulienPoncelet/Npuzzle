module Annexe
	def a(x, y)
		x * size + y
	end

	def b(n)
		return n / size, n % size
	end

	def printGrid(grid)
		grid.each_slice(size) do |row|
			pp row
		end
		puts "-------------------"
	end

	def printOpen
		printList(open)
	end

	def printClose
		printList(close)
	end

	def printList(list)
		list.each do |k, v|
			puts "G = #{v.g} - H = #{v.h} - F = #{v.f}"
			printGrid(k)
		end
		puts "+++++++++++++++++++"
	end

	def findPos(grid, value)
		hash = Hash[grid.map.with_index.to_a]
		hash[value]
	end
end