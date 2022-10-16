import re

def regexmatch(pattern, file):
    file = open(file, "r")
    data = file.read()
    file.close()
    
    result = []

    for match in re.finditer(pattern, data, re.MULTILINE):
        result.append(match.group())
        #print(match.span())

    return result


def main():

    ''' 
    1. substring ending with a semicolon
    '''
    fileName = "somefile.txt"
    pattern = r".*;"
    result = regexmatch(pattern, fileName)
    print("Question 1: ", result)

    '''
    2. all characters inside a pair of parentheses
    '''
    pattern = r"\(.*?\)"
    result = regexmatch(pattern, fileName)
    print("\nQuestion 2: ", result)

    '''
    3. Valid variable names, which start with a letter or underscore, and contain only letters, numbers, and underscores
    '''
    pattern = r"[_a-zA-Z]\w*"
    result = regexmatch(pattern, fileName)
    print("\nQuestion 3: ", result)

    '''
    4. All phone numbers in the format 1-800-555-1212 or 800-555-1212 with or without dashes
    '''
    pattern = r"1?-?\d{3}[- ]?\d{3}[- ]?\d{4}"
    result = regexmatch(pattern, fileName)
    print("\nQuestion 4: ", result)

    '''
    5. All lines beginning with "DEPOSIT"
    '''
    pattern = r"^DEPOSIT.*"
    result = regexmatch(pattern, fileName)
    print("\nQuestion 5: ", result)



if __name__ == '__main__':
    main()