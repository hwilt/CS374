import re

keyword_re = r"[a-zA-Z]+"
count_re = r"count"
find_re = r"find"


def readInput():
  """
  Reads the file and returns it in a string.
  
  Parameters:
  None
  
  Returns:
  val -> str;
    the file string
  """
  f = open("inputfile.txt", "r")
  return f.read().lower()


def checkUserInput(user):
  """
  Makes sure the user input has both the keyword and the correct function call, 
  if not prints out the error in the input then returns if true or false

  Parameters:
  user -> str;

  Returns:
  returnValue -> boolean;
    true if all good
    false if thing is bad
  """
  returnValue = False
  user = user.lower().split(" ")
  if len(user) != 2:
    print("You can only have one keyword and one function call.")
  else:
    if user[0] == "count" or user[0] == "find" and re.search(keyword_re, user[1]):
      returnValue = True
    else:
      if not user[0] == "count" or user[0] == "find":
        print("Your function call is not one contained within this program, please choose count or find.")
      if not re.search(keyword_re, user[1]):
        print("Your keyword contains invalid characters, please only use lowercase or uppercase english characters.")
  #print(returnValue)
  return returnValue


def readUserInput():
  """
  Reads the input from console, then converts it to lowercase

  Parameters:
  None

  Returns:
  user -> str array;
    [<function>, <keyword>], the user 
  """

  user = input("<Count or Find> <keyword>: ")
  isValid = checkUserInput(user)
  while (not isValid):
    user = input("<Count or Find> <keyword>: ")
    isValid = checkUserInput(user)
  user = user.lower().split(" ")
  return user


def find_first(keyword, file):
  """
  This method will find the first position of the keyword from the file
  
  Parameters:
  keyword -> str; 
    this is the variable that this method will find the position of keywords
  file -> str;
    variable that the method will search through
    
  Return:
  None
  """
  first = re.search(r"\b"+keyword, file)
  position = first.span()
  print(f"The first occurence of {keyword} is {position}")
  sentence = file[position[0]:position[1]+file.find("\n", position[1])-3]
  print(f"This the sentence around the first instance;\n{sentence}")


def find_all(keyword, file):
  """
  This method will find all the positions of the keyword from the file

  Parameters:
  keyword -> str;
    this is the variable that this method will find all of the positions of the keyword
  file -> str;
    variable that the method will search through

  Return: 
  None
  """
  find_all = re.findall(r"\b"+keyword, file)
  for match in find_all:
    position = match.span()
    print(f"Word match ({keyword}) found at {position},")
    


def count(keyword, file):
  """
  This method will count up all the keyword occurences

  Parameters:
  keyword -> str; 
    this is the variable that this method will count up
  file -> str;
    variable that the method will search through

  Return:
  None
  """
  count = 0
  findall = re.findall(r"\b"+keyword, file)
  count = len(findall)
  #print(findall)
  print(f"There are {count} <{keyword}> in the file.")


def main():
  file = readInput()  # str
  user_Split = readUserInput()  # [<FUNCTION>, <KEYWORD>]
  if user_Split[0] == "find":
    find_first(user_Split[1], file)
  elif user_Split[0] == "count":
    count(user_Split[1], file)
  else:
    print("Your input is wrong, :(")


if __name__ == '__main__':
  main()
