SUIT = {
  NONE: 0,
  CLUBS: 1,
  DIAMONDS: 2,
  HEARTS: 3,
  SPADES: 4
}

RANK = {
  JOKER: 1,
  TWO: 2,
  THREE: 3,
  FOUR: 4,
  FIVE: 5,
  SIX: 6,
  SEVEN: 7,
  EIGHT: 8,
  NINE: 9,
  TEN: 10,
  JACK: 11,
  QUEEN: 12,
  KING: 13,
  ACE: 14
}

class Card
  attr_accessor :rank, :suit

  def initialize(rank, suit)
    @rank = rank
    @suit = suit
  end

  def to_s
    RANK.key(@rank).to_s + " of " + SUIT.key(@suit).to_s
  end

  def == (crd)
    @rank == crd.rank && @suit == crd.suit
  end

  def > (crd)
    if @suit > crd.suit then return true end
    if @suit < crd.suit then return false end
    
    if @rank > crd.rank then return true end
    if @rank < crd.rank then return false end
    
    return false
  end

  def < (crd)
    if @suit < crd.suit then return true end
    if @suit > crd.suit then return false end
    
    if @rank < crd.rank then return true end
    if @rank > crd.rank then return false end
    
    return false
  end
end

class Deck
  attr_accessor :cardsList

  def initialize()
    @cardsList = []
    suitValue = 1
    
    until suitValue == SUIT.length
      rankValue = 2
      until rankValue == RANK.length + 1
        c = Card.new(rankValue, suitValue)
        @cardsList.push(c)
        rankValue += 1
      end
      suitValue += 1
    end
  end

  def printDeck()
    @cardsList.each do |card|
      puts(card.to_s)
    end 
  end

  def subDeck(firstIndex, lastIndex)
    newDeck = Deck.new
    newDeck.cardsList = self.cardsList[firstIndex..lastIndex]
    return newDeck
  end
end