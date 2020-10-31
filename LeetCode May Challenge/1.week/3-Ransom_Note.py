class Solution(object):
    def canConstruct(self, ransomNote, magazine): 
        def rec(ran,mag):
            if ran == "":
                return True;
            if mag.count(ran[0]) == 0:
                return False
            x = mag.find(ran[0])
            mag = mag[:x] + mag[x+1:]
            return rec(ran[1:],mag)
        return rec(ransomNote,magazine)
