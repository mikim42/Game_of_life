def count_life(board, y, x)
	cnt = 0

	# TOP LEFT
	board[y - 1][x - 1] == '1' ? cnt += 1 : 0

	# TOP MIDDLE
	board[y - 1][x] == '1' ? cnt += 1 : 0

	# TOP RIGHT
	if (board[y - 1][x + 1])
		board[y - 1][x + 1] == '1' ? cnt += 1 : 0
	else
		board[y - 1][0] == '1' ? cnt += 1 : 0
	end
	

	# LEFT
	board[y][x - 1] == '1' ? cnt += 1 : 0

	# RIGHT
	if (board[y][x + 1])
		board[y][x + 1] == '1' ? cnt += 1 : 0
	else
		board[y][0] == '1' ? cnt += 1 : 0
	end


	# BOTTOM
	if (board[y + 1])
		# BOTTOM LEFT
		board[y + 1][x - 1] == '1' ? cnt += 1 : 0

		# BOTTOM MIDDLE
		board[y + 1][x] == '1' ? cnt += 1 : 0

		# BOTTOM RIGHT
		if (board[y + 1][x + 1])
			board[y + 1][x + 1] == '1' ? cnt += 1 : 0
		else
			board[y + 1][0] == '1' ? cnt += 1 : 0
		end
	else
		# BOTTOM LEFT
		board[0][x - 1] == '1' ? cnt += 1 : 0

		#BOTTOM MIDDLE
		board[0][x] == '1' ? cnt += 1 : 0

		#BOTTOM RIGHT
		if (board[0][x + 1])
			board[0][x + 1] == '1' ? cnt += 1 : 0
		else
			board[0][0] == '1' ? cnt += 1 : 0
		end
	end

	return cnt
end

def dead_cell(board, y, x, cnt)
	if (cnt == 3)
		board[y][x] = '1'
	else
		board[y][x] = '0'
	end
end

def live_cell(board, y, x, cnt)
	if cnt == 2 || cnt == 3
		board[y][x] = '1'
	else
		board[y][x] = '0'
	end
end

def next_generation(prev_b, next_b)
	for y in 0...prev_b.length do
		for x in 0...prev_b[y].length do
			cnt = count_life(prev_b, y, x)
			if prev_b[y][x] == '1'
				live_cell(next_b, y, x, cnt)
			else
				dead_cell(next_b, y, x, cnt)
			end
		end
	end
end

def main()
	board1 = Array.new
	board2 = Array.new

	# READ FILE
	File.open(ARGV[0], "r") do |f|
		f.each_line do |line|
			board1.push line.chomp.dup
			board2.push line.chomp.dup
		end
	end

	board1.flatten
	board2.flatten

	# GAME OF LIFE
	system "clear"
	loop do
		puts board1
		next_generation(board1, board2)
		puts "-"
		sleep 0.1
		system "clear"
		puts board2
		next_generation(board2, board1)
		puts "|"
		sleep 0.1
		system "clear"
	end
end

main()
