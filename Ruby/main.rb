require_relative 'Card'

# This is a test file for the card class defined
# in Card.rb. If all these tests pass, It should
# just print "true" a bunch of times.

passed = true

puts ("\e[46m  Test to_s  \e[0m")
c1 = Card.new(11, 4)
puts(c1.to_s == "JACK of SPADES")
unless c1.to_s == "JACK of SPADES" then passed = false end
puts()

puts ("\e[46m  Test > and <  \e[0m")
c2 = Card.new(12, 1)
puts(c2.to_s == "QUEEN of CLUBS")
puts(c1 > c2)
puts(c2 < c1)
unless c1 > c2 and c2 < c1 then passed = false end
puts()

puts ("\e[46m  Test ==  \e[0m")
c3 = Card.new(11, 4)
puts(c1.to_s == "JACK of SPADES")
puts(c1 == c3)
unless c1 == c3 then passed = false end
puts()

puts ("\e[46m  Test Deck initialize  \e[0m")
deckck = Deck.new

for i in 0..51 do
  c = Card.new((i % 13) + 2, (i / 13) + 1)
  puts(deckck.cardsList[i] == c)
  unless deckck.cardsList[i] == c then passed = false end
end
puts()

puts("\e[46m  Test subDeck  \e[0m")
subDeckck = deckck.subDeck(0,12) # Subdeck containing all of the clubs cards
for i in 2..14 do
  c = Card.new(i,1)
  puts(subDeckck.cardsList[i - 2] == c)
  unless subDeckck.cardsList[i - 2] == c then passed = false end
end
puts()

if passed
  puts "\e[32mSUCCESS!\e[0m"
else
  puts "\e[31mFAILED!\e[0m"
end