require "./Annexe.rb"
require "./Input.rb"
require "./Solver.rb"
require "./Node.rb"
require "./Heuristiques.rb"

class Npuzzle
	include Annexe
	include Input
	include Solver
	include Heuristiques
	attr_accessor :startGrid, :endGrid, :size, :open, :close, :nbOpen, :nbTotal

	def initialize
		@startGrid 		= Array.new
		@endGrid 		= Array.new
		@size 			= 0
		@open 			= Hash.new
		@close 			= Hash.new
		@nbOpen			= 0
		@nbTotal		= 0
	end

	def start
		useInput
		solvePuzzle
	end
end
