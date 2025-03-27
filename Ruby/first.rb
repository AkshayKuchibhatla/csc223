hello = "Hello message"

puts hello

def goodbye(name)
  puts "Good bye, #{name}."
end

def staircase(integer)
  i = 1
  while i <= integer
    for a in 1..i do
      print a
      print " "
    end
    print "\n"
    i = i + 1
  end
end

staircase(5)
staircase(10)