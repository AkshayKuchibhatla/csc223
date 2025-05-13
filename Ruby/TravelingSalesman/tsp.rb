require 'ruby2d'

class City
  attr_accessor :label, :children, :x, :y

  def initialize(label, x, y)
    @label = label
    @x = x
    @y = y
    @children = []
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
end

# Set the window size
set width: 1024, height: 783


c = City.new('A', 400, 500)
c1 = City.new('B', 350, 530)
c2 = City.new('C', 470, 560)

c.draw
c1.draw
c2.draw

# Show the window
show