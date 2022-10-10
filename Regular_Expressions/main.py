import re

def regexmatch(pattern, file):
    # You can append your match spans to this list
    result = []
    
    # TODO: your code here
    
    return result


file = open("somefile.txt")
data = file.read()

offset = 0
result = []

# This will return a Match object for the first semicolon in the string
match = re.search(r";", data)

# This will print a list of the starting index (from 0) and the ending index (non-inclusive) of the match
print(match.span())

result.append(match.span()) # keep track of all the matching positions, relative to the prior match position

nextIndex = match.span()
nextIndex = nextIndex[1]

offset = offset + nextIndex # keep track of the absolute position of the most recent match

# This will search the rest of the string for the next instance
# ... and return None if no match is found
match = re.search(r";", data[offset:])