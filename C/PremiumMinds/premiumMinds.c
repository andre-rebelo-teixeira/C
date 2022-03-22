#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Definition of function do here to make sure there are none undifined references
void read(int *number, char *string, int *arrayControler, int *stringLenght);
int getLetterValue(char letter);
void processDate(char *string, int *arrayControler, int *stringLenght);

/**
 * Stages of the program
 *   - Reading of the string - Done
 *   - Processing of the string - To Do
 *   - Writting output - To Do
 */

/**
 * @brief This function is going to read and set the input in the variable that later will be used to make operation in the string
 * @param number -> pointer to the variable where the number that comes in the string will be stored
 * @param string -> pointer to the variable where the full input string will be stored
 * @param arrayControler -> pointer to a varible where it will be store the place where the letters in the array start
 * @param stringLenght -> pointer to a variable where we will stote the string length in order to not have to calculate it again
 */
void read(int *number, char *string, int *arrayControler, int *stringLenght)
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

    return; // Makes sure we exit the function correctly
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
    case 'F':
        return -1;
        break;
    case 'W':
        return 1;
        break;
    case 'E':
        return 2;
        break;
    case 'A':
        return 2;
        break;
    case 'N':
        return 0;
        break;
    default:
        printf("There was a wrong letter in the array :/");
        exit(0);
    }
}

void processDate(char *string, int *arrayControler, int *stringLenght)
{
    int flag = 1;
}

/**
 * @brief Simple main function -> controls the program
 */
int main()
{
    // Declares variables
    int number = 0, arrayControler = 0, stringLenght = 0;
    char *string = NULL;

    read(&number, string, &arrayControler, &stringLenght); // Reads the input from Konsole

    free(string); // Deletes all the allocated memory

    return 0; // Ends Program  correctly
}