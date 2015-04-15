module Input
	def useInput
		fillStartGrid
		fillEndGrid
	end

	def fillStartGrid
		File.read(filename).each_line do |line|
			line.chomp!
			next if line[0] == '#'
			if @size < 3
				@size = line.to_i
			else
				line.split(' ').each { |n| @startGrid << n.to_i}
			end
		end
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
	end
end
