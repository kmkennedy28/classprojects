#pragma once

//looks for sub in target
//returns 0 if not found or number of occurances
int myFind(const char* targetStr, const char* subStr) {
    int i = 0;
    int j = 0;
    int count = 0; //number of times substr is found
    //loops through str until end
    while (targetStr[i] != '\0') {
        //if each charecter matches the substr add it to the count
        if (targetStr[i] == subStr[j]) {
            j++;
            if (subStr[j] == 0) {
                count++;
                j = 0;
            }
        }
        else {
            j = 0;
        }
        i++;
    }
    return count;
}

//removes redundant blank spaces
void improveFormat(char* targetStr) {

    int length = strlen(targetStr);
    int index = 0;

    //iterate through the str
    for (int i = 0; i < length; i++) {
        //if a char is not a space keep it
        if (targetStr[i] != ' ') {
            targetStr[index] = targetStr[i];
            index++;
        }
        //if it is a space move the next char up
        else if (targetStr[i] == ' ' && targetStr[i + 1] != ' ') {
            targetStr[index] = targetStr[i];
            index++;
        }
    }
    //add the end char array
    targetStr[index] = '\0';
    
    
}


