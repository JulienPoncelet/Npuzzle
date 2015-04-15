require "pp"
require "byebug"

require "./Npuzzle.rb"

begin
	npuzzle = Npuzzle.new(ARGV[0])
	npuzzle.start
rescue => error
	puts error
end
