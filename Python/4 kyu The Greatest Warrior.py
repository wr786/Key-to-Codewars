rankList = ["Pushover", "Novice", "Fighter", "Warrior", "Veteran", "Sage", "Elite", "Conqueror", "Champion", "Master", "Greatest"]  

class Warrior():
        
    def __init__(self): 
        self.experience = 100
        self.level = 1
        self.rank = "Pushover"
        self.achievements = []
    
    def update(self, exp):
        self.experience += exp
        self.experience = min(self.experience, 10000)
        self.level =  self.experience // 100
        self.rank = rankList[self.experience // 1000]
        
    def battle(self, enemy):
        if enemy < 1 or enemy > 100: return "Invalid level"
        if self.level // 10 < enemy // 10:
            if self.level // 10 + 1 == enemy // 10 and self.level > enemy - 5:
                pass
            else:
                return "You've been defeated"
        if self.level == enemy: 
            self.update(10)
            return "A good fight"
        elif self.level == enemy + 1:
            self.update(5)
            return "A good fight"
        elif self.level > enemy:
            return "Easy fight"
        else:
            self.update(20 * ((enemy - self.level) ** 2))
            return "An intense fight"
        
    def training(self, arr):
      if self.level < arr[2]:
          return "Not strong enough"
      else:
          self.update(arr[1])
          self.achievements.append(arr[0])
          return arr[0]