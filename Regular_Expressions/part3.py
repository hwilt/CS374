import re

def regexmatch(pattern, file, replacement):
    file = open(file, "r")
    result = []
    #re.sub(pattern, replacement, data)
    for line in file:
        line = re.sub(pattern, replacement, line)
        #print(line, end="")
        result.append(line)
    
    file.close()
    return result

def main():
    '''
    replace CS374 or CS 374 with "Principles of Programing Languages"
    '''
    fileName = "part3.txt"
    pattern = r"CS ?374"
    result = regexmatch(pattern, fileName, "Principles of Programing Languages")
    print(result)

if __name__ == '__main__':
    main()
