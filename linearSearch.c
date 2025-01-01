#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM 7

int *generateArray();
int *generateNumbers();
int *generateRandumNumbers(int *arrayOfNumbers);
void printArray(int *numbers);
int userInput();
bool findNumber(int *numbers, int number);

int main()
{
  int *numbers, number;
  bool isFound = false;

  numbers = generateNumbers();
  printArray(numbers);
  number = userInput();
  isFound = findNumber(numbers, number);

  (isFound) ? printf("Found it!\n") : printf("Not found...\n");

  free(numbers);

  return 0;
}

int *generateNumbers()
{
  int *arrayOfNumbers = generateArray();

  arrayOfNumbers = generateRandumNumbers(arrayOfNumbers);

  return arrayOfNumbers;
}

int *generateArray()
{
  int *array = (int *)malloc(NUM * sizeof(int));

  if (array == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  return array;
}

int *generateRandumNumbers(int *arrayOfNumbers)
{
  srand(time(NULL));

  int randumNumber, index;

  for (index = 0; index < NUM; index++)
  {
    randumNumber = rand() % 1001;
    arrayOfNumbers[index] = randumNumber;
  }

  return arrayOfNumbers;
}

void printArray(int *numbers)
{
  int index;

  printf("Here is the numbers:\n");
  for (index = 0; index < NUM; index++)
  {
    printf("%d ", numbers[index]);
  }

  printf("\n\n");
}

int userInput()
{
  int number;

  printf("Enter the number that you are looking for:\n-> ");
  scanf("%d", &number);

  return number;
}

bool findNumber(int *numbers, int number)
{
  int index;
  bool isEqualTo = false;

  for (index = 0; index < NUM; index++)
  {
    if (numbers[index] == number)
    {
      return isEqualTo = true;
    }
  }

  return isEqualTo;
}
