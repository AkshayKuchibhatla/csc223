require 'ruby2d'

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

# This tree is needed to solve the problem
class StateSpaceTree
  attr_accessor :root

  def initialize
    @root = nil
  end
end

# This
class StateSpaceNode
  attr_accessor :cost, :children

  def initialize()
    @cost = 0
    @children = []
  end

  def appendChild(childNode)
    @children.append(childNode)
  end
end

# Reduces the given matrix and returns
# the reduction cost
def reduceMatrix(matrix)
  reductionCost = 0
  least = 0
  for row in matrix
    least = row[0]
    for cost in row
      if cost == Float::INFINITY
        next
      end
      if cost < least
        least = cost
      end

    end

  end
end

# Function that will take an array of cities,
# render them, then find the optimal path between
# all of them:

def branchNBound(cities)
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

cityArr = [
  City.new('A', 400, 500), 
  City.new('B', 350, 530), 
  City.new('C', 470, 560),
  City.new('D', 480, 590),
  City.new('E', 670, 660)
]

# Set the window size
set width: 1024, height: 783

things = branchNBound(cityArr)

puts(things.to_s)

# Show the window
show