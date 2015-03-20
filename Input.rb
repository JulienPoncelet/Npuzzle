module Input
	def useInput
		checkFile
		fillStartGrid
		fillEndGrid
	end

	def checkFile
		# TODO
	end

	def fillStartGrid
		@size = 4
		# @startGrid = [7, 6, 3,
		# 			  			8, 0, 5,
		# 						  1, 4, 2]
		# @startGrid = [1, 5, 6,
		# 			  			3, 7, 4,
		# 						  8, 2, 0]
		@startGrid = [4, 15, 1, 2,
					  0, 14, 8, 13,
					  10, 12, 3, 9,
					  11, 5, 7, 6]
		# @startGrid = [3, 7, 0,
		# 			  			2, 8, 6,
		# 						  4, 5, 1]
	end


	def fillEndGrid
		i = 0;
		j = 0;
		n = 1;
		state = 0;

		@endGrid = Array.new(9) { |i| i = -1 }

		(1..size * size).each do |n|
			@endGrid[i * size + j] = n

			case state
			when 0
				if j + 1 >= size or endGrid[a(i, j + 1)] != -1
					state = 1
					i += 1
				else
					j += 1
				end
			when 1
				if i + 1 >= size or endGrid[a(i + 1, j)] != -1
					state = 2
					j -= 1
				else
					i += 1
				end
			when 2
				if j - 1 < 0 or endGrid[a(i, j - 1)] != -1
					state = 3
					i -= 1
				else
					j -= 1
				end
			when 3
				if i - 1 < 0 or endGrid[a(i - 1, j)] != -1
					state = 0
					j += 1
				else
					i -= 1
				end
			end
		end


		@endGrid[findPos(endGrid, size * size)] = 0
		@endGrid = [1, 2, 3, 4, 12, 13, 14, 5, 11, 0, 15, 6, 10, 9, 8, 7]
	end
end
