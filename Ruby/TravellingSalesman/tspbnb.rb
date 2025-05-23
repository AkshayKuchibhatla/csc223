require 'ruby2d'
require 'pqueue'

# Solves traveling salesman problem using branch and bound

class City
  attr_accessor :label, :x, :y

  def initialize(label, x, y)
    @label = label
    @x = x
    @y = y
  end

  def draw()
    Circle.new(
      x: @x, y: @y,
      radius: 15,
      sectors: 32,
      color: 'green',
      z: 10
    )

    Text.new(
      @label,
      x: @x - 8, y: @y - 15,
      font: 'fonts/DMSerifText-Regular.ttf',
      style: 'bold',
      size: 20,
      color: 'black',
      rotate: 0,
      z: 10
    )
  end

  def to_s()
    return label + "(" + x.to_s + ", " + y.to_s + ")"
  end
end

def costMatrix(cities)
  for city in cities
    city.draw
  end

  # First, generate the array of distances between
  # the cities:
  dists = []
  cost = 0
  for i in 0..cities.length - 1
    distRow = []
    for j in 0..cities.length - 1
      cost = (((cities[i].x - cities[j].x) ** 2 + (cities[i].y - cities[j].y) ** 2) ** 0.5).round()
      distRow.append(cost)
    end
    dists.append(distRow)
  end
  return dists
end

class TSPNode
  attr_reader :path, :cost, :lower_bound

  def initialize(path, cost, lower_bound)
    @path = path
    @cost = cost
    @lower_bound = lower_bound
  end
end

class BranchAndBoundTSP
  def solve_tsp(graph)
    num_cities = graph.length
    initial_lower_bound = calculate_initial_lower_bound(graph)
    best_cost = Float::INFINITY

    # Priority queue to store nodes, sorted by lower bound
    pq = PQueue.new([]) {|a,b| a < b}
    pq.push(TSPNode.new([0], 0, initial_lower_bound))

    while !pq.empty?
      current = pq.shift

      if current.lower_bound >= best_cost
        next # Prune if the lower bound is not promising
      end

      if current.path.length == num_cities
        final_cost = current.cost + graph[current.path[-1]][0]
        best_cost = [best_cost, final_cost].min
        next
      end

      last_city = current.path[-1]
      num_cities.times do |next_city|
        unless current.path.include?(next_city)
          new_path = current.path + [next_city]
          new_cost = current.cost + graph[last_city][next_city]
          new_lower_bound = new_cost + calculate_remaining_lower_bound(graph, new_path)

          if new_lower_bound < best_cost
            pq.push(TSPNode.new(new_path, new_cost, new_lower_bound))
            pq.sort_by!(&:lower_bound) # Keep the queue sorted by lower bound
          end
        end
      end
    end
    best_cost
  end

  private

  def calculate_initial_lower_bound(graph)
    num_cities = graph.length
    lower_bound = 0
    num_cities.times do |i|
      min1 = Float::INFINITY
      min2 = Float::INFINITY
      num_cities.times do |j|
        next if i == j

        if graph[i][j] < min1
          min2 = min1
          min1 = graph[i][j]
        elsif graph[i][j] < min2
          min2 = graph[i][j]
        end
      end
      lower_bound += min1 + min2
    end
    lower_bound / 2
  end

  def calculate_remaining_lower_bound(graph, path)
    num_cities = graph.length
    remaining_lower_bound = 0
    current_cost = 0

    (0...path.length - 1).each do |i|
      current_cost += graph[path[i]][path[i + 1]]
    end
    remaining_lower_bound += current_cost

    num_cities.times do |i|
      unless path.include?(i)
        min1 = Float::INFINITY
        min2 = Float::INFINITY
        num_cities.times do |j|
          next if i == j || path.include?(j)

          if graph[i][j] < min1
            min2 = min1
            min1 = graph[i][j]
          elsif graph[i][j] < min2
            min2 = graph[i][j]
          end
        end
        remaining_lower_bound += min1 + min2
      end
    end
    remaining_lower_bound / 2
  end
end

cityArr = [
  City.new('A', 400, 500), 
  City.new('B', 350, 530), 
  City.new('C', 470, 560),
  City.new('D', 480, 590)
]
# City.new('E', 670, 660)
# Example usage:
# graph = [
#   [0, 10, 15, 20],
#   [10, 0, 35, 25],
#   [15, 35, 0, 30],
#   [20, 25, 30, 0]
# ]

puts(costMatrix(cityArr).to_s)

graph = costMatrix(cityArr)

tsp_solver = BranchAndBoundTSP.new
min_cost = tsp_solver.solve_tsp(graph)
puts "Minimum cost for TSP: #{min_cost}"
