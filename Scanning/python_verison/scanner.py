import re
from dataclasses import dataclass

@dataclass
class token_struct:
    value: str
    type: str
    tokenID = 0
    counter = 0

    def __init__(self, value, type):
        self.value = value
        self.type = type
        self.tokenID = token_struct.counter
        token_struct.counter += 1

    def __str__(self):
        return f"Token ID {self.tokenID}:\nValue: {self.value}\nType: {self.type}\n"


all_tokens = []

def print_tokens():
    for token in all_tokens:
        print(token)


def regexmatch(pattern, file):
    file = open(file, "r")
    data = file.read()
    file.close()
    return re.findall(pattern, data)


def main():
    file = "example.txt"

    please_pattern = r"[p][l][e][a][s][e]"
    matches = regexmatch(please_pattern, file)
    for match in matches:
        all_tokens.append(token_struct(match, "please"))

    int_pattern = r"(?<!\.)\b[0-9]+\b(?!\.)"
    matches = regexmatch(int_pattern, file)
    for match in matches:
        all_tokens.append(token_struct(match, "int"))
    
    op_pattern = r"[\+\-\*\/]"
    matches = regexmatch(op_pattern, file)
    for match in matches:
        all_tokens.append(token_struct(match, "op"))

    float_pattern = r"[0-9]*\.[0-9]+"
    matches = regexmatch(float_pattern, file)
    for match in matches:
        all_tokens.append(token_struct(match, "float"))

    

   
    
    print_tokens()



if __name__ == '__main__':
    main()