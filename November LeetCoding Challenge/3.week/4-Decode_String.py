class Solution(object):
    def decodeString(self, s):
        while '[' in s:
            closing = s.find(']')
            opening = closing
            while True:
                if s[opening] == '[':
                    break
                opening -= 1
            ind = opening-1
            while ind >= 0 and s[ind].isnumeric():
                ind -= 1
            num = int(s[ind+1:opening])
            s = s[:ind+1] + s[opening+1:closing] * num + s[closing+1:]
        return s
        