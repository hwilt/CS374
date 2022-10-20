#include<iostream>
using namespace std;

char* userInput(){
    cout << "Enter a string of zeros and ones: ";
    char* input = new char[100]; // allocate memory for the string no more than 100 characters
    cin >> input;
    return input;
}

//* Function: checkInput
//* Description: checks if the input is valid, valid being there are an odd number of 0's and 1's
//* Parameters: char* input
bool isAcceptable(char* s){
    bool isZeroOdd = false;
    bool isOneOdd = false;
    bool isOnes = false;
    bool isZeros = false;
    for(int i = 0; s[i] != '\0'; i++){
        if(s[i] == '0'){
            isZeroOdd = !isZeroOdd;
            isZeros = true;
        }
        else if(s[i] == '1'){
            isOneOdd = !isOneOdd;
            isOnes = true;
        }
    }
    if(!isZeros){
        isZeroOdd = true;
    }
    if(!isOnes){
        isOneOdd = true;
    }
    return isZeroOdd && isOneOdd;

}

int main() {
    char* input = userInput();
    cout << "You entered: " << input << endl;
    bool acceptable = isAcceptable(input);
    if (acceptable) {
        cout << "The string does end in an accepting state." << endl;
    } else {
        cout << "The string does not end in an accepting state." << endl;
    }
    delete[] input; // free the memory
    return 0;
}