def cypher(message)
  cypheredMessage = ""
  charInt = 0
  for index in 0..message.length() - 1
    charInt = message[index].ord
    if charInt > 64 && charInt < 91
      if charInt > 77
        charInt = charInt - 13
      else
        charInt = charInt + 13
      end
    elsif charInt > 96 && charInt < 123
      if charInt > 109
        charInt = charInt - 13
      else
        charInt = charInt + 13
      end
    end
    cypheredMessage = cypheredMessage + charInt.chr
  end
  return cypheredMessage
end

msg = gets.chomp
puts(cypher(msg))