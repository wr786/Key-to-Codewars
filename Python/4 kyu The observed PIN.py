def get_pins(observed):
  adjacents = [(8,0),(1,2,4),(1,2,3,5),(2,3,6),(1,4,5,7),(2,4,5,6,8),(3,5,6,9),(4,7,8),(5,7,8,9,0),(6,8,9)]
  ret = []
  def generatePIN(pos, pin):
      if pos == len(observed): ret.append(pin)
      else:
          for fuzzyPIN in adjacents[int(observed[pos])]: generatePIN(pos+1, pin+str(fuzzyPIN))
  generatePIN(0,'')
  return ret  