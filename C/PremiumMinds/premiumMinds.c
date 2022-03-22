#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Definition of function do here to make sure there are none undifined references
char *read(int *number, char *string, int *arrayControler, int *stringLenght);
int getLetterValue(char letter);
void processData(char *string, int arrayControler, int stringLenght);
int getFirstIndex(char *string, int stringLenght, int start);

/**
 * Stages of the program
 *   - Reading of the string - Done
 *   - Processing of the string - To Do -> right now best algorithm is O(N²) trying to optimize to maybe O(N * log(N))
 *   - Writting output - To Do
 */

/**
 * @brief This function is going to read and set the input in the variable that later will be used to make operation in the string
 *
 * @param number -> pointer to the variable where the number that comes in the string will be stored
 * @param string -> pointer to the variable where the full input string will be stored
 * @param arrayControler -> pointer to a varible where it will be store the place where the letters in the array start
 * @param stringLenght -> pointer to a variable where we will stote the string length in order to not have to calculate it again
 *
 * @return string -> string read
 */
char *read(int *number, char *string, int *arrayControler, int *stringLenght)
{
    // Declares variables
    int aux = 0, aux2 = 0, aux1 = 0;

    scanf("%ms", &string); // Reads a string of unknow size -> this memory is allocated int the heap and will need to be cleaned up

    sscanf(string, "%d", &*number); // Gets the number that is contained in the string

    if (*(number) == 0)
    {                // There was no letter in the array -> the output sequence will be none
        printf(" "); // Writes the sequence output
        exit(0);     // leaves the program
    }

    aux1 = *number;                 // this variable is just going to be used in the next loop in order to calculate the number of digits the int "*number" has
    *stringLenght = strlen(string); // Get the string lenght and stores it so that we cont have to calculate it later

    do
    {
        aux1 /= 10;          // Removes one digit from the variable aux1 -> in doubt see the way that division works in C
        ++(*arrayControler); // moves array Controler to not count with the number
    } while (aux1 != 0);     // Gets the number of digits the the variable *number contains

    return string; // Makes sure we exit the function correctly
}
/**
 * @brief Get the Letter Value object
 *
 * @param letter -> Character that wants its value
 * @return int -> value of the letter
 */
int getLetterValue(char letter)
{
    switch (letter) // Switch case with the values of the letters
    {
    case 'F': // FIRE
        return -1;
        break;
    case 'W': // WATER
        return 1;
        break;
    case 'E': // EARTH
        return -2;
        break;
    case 'A': // AIR
        return 2;
        break;
    case 'N': // NONE -> meaning it has already been cleared by another element
        return 0;
        break;
    default: // i
        printf("There was a wrong letter in the array :/");
        exit(0);
    }
}

void processData(char *string, int arrayControler, int stringLenght)
{
    int flag = 1;
    // char last = ' ';
    int lastIndexUsed;
    int lastValue = 0, nowValue = 0;

    while (flag) // We keep in this loop while the last iteration through the array change something after that the string is as short as possible
    {
        flag = 0; // Forces The flag to be zero, if by the end of the 'for loop' it is not zero then a change was made, meaning another iteration is needed

        lastIndexUsed = getFirstIndex(string, stringLenght, arrayControler - 1);
        lastValue = getLetterValue(string[lastIndexUsed]);

        for (int i = getFirstIndex(string, stringLenght, lastIndexUsed); i < stringLenght && i > 0; i = getFirstIndex(string, stringLenght, i)) // Iteration Throug the arrray
        {
            if (i == -1)
                break;
            nowValue = getLetterValue(string[i]);
            if ((nowValue + lastValue) == 0)
            {
                string[lastIndexUsed] = string[i] = 'N';
                lastIndexUsed = i = -1;
                flag = 1;
                break;
            }
            else
            {
                // Update Values of the "last" variables
                lastIndexUsed = i;
                lastValue = nowValue;
            }
        }
    }

    for (int i = arrayControler; i < stringLenght + 1; i++) // Test if it doing what is needs;
        if (string[i] != 'N')
            printf("%c ", string[i]);
    return;
}

/**
 * @brief Get the Next Value - Return the index of position of the next no processed letter
 *
 * @param string -> String containig the input word
 * @param stringLenght -> Total lenght of the input string
 * @param start -> Index of the string where it is suposed to start looking again
 * @return int -> Index of the first letter that has not been "deleted" from the string
 */
int getFirstIndex(char *string, int stringLenght, int start)
{
    for (int i = start + 1; i < stringLenght; i++) // Goes to the end of the string
        if (string[i] != 'N')                      // Check if the letter has been processed
            return i;                              // Return the Index
    return -1;                                     // Return -1 to know that is the last letter
}

/**
 * @brief Simple main function -> controls the program
 */
int main()
{
    // Declares variables
    int number = 0, arrayControler = 0, stringLenght = 0;
    char *string = NULL;

    string = read(&number, string, &arrayControler, &stringLenght); // Reads the input from Konsole

    processData(string, arrayControler, stringLenght);

    free(string); // Deletes all the allocated memory

    return 0; // Ends Program  correctly
}