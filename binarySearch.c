#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM 101
#define LENGTH 20

int *createArray();
int *createRandumNumbers(int *pNumbers);
int *sortNumbers(int *pNumbers);
void printNumbers(int *sortedNumbers);
int userInput();
int binarySearch(int *pNumbers, int targetNumber);
void printResult(int result, int targetNumber);

int main(void)
{
  int *pArray, *pNumbers, *pSortedNumbers;
  int targetNumber, result;

  pArray = createArray();
  pNumbers = createRandumNumbers(pArray);
  pSortedNumbers = sortNumbers(pNumbers);
  printNumbers(pSortedNumbers);
  targetNumber = userInput();
  result = binarySearch(pNumbers, targetNumber);
  printResult(result, targetNumber);
  free(pNumbers);
  return 0;
}

int *createArray()
{
  int *pArray = (int *)malloc(LENGTH * sizeof(int));

  if (pArray == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  return pArray;
}

int *createRandumNumbers(int *pNumbers)
{
  srand(time(NULL));

  int randumNumber, index, flag;
  int element = 0;

  while (element < LENGTH)
  {
    flag = 1;

    randumNumber = rand() % NUM;

    for (index = 0; index < element; index++)
    {
      if (randumNumber == pNumbers[index])
      {
        flag = 0;
        break;
      }
    }

    if (flag == 1)
    {
      pNumbers[element] = randumNumber;
      element++;
    }
  }

  return pNumbers;
}

int *sortNumbers(int *pNumbers)
{
  int count, index, tmp;

  for (count = 0; count < LENGTH; count++)
  {
    for (index = count - 1; index >= 0; index--)
    {
      if (pNumbers[index] > pNumbers[index + 1])
      {
        tmp = pNumbers[index];
        pNumbers[index] = pNumbers[index + 1];
        pNumbers[index + 1] = tmp;
      }
      else
      {
        break;
      }
    }
  }

  return pNumbers;
}

void printNumbers(int *pSortedNumbers)
{
  int index;

  printf("Here is the sorted numbers:\n");

  for (index = 0; index < LENGTH; index++)
  {
    printf("%d ", pSortedNumbers[index]);
  }
}

int userInput()
{
  int targetNumber;

  do
  {
    printf("\nEnter a number in range of 0 to 100.\n-> ");
    scanf("%d", &targetNumber);
  } while (targetNumber < 0 || 100 < targetNumber);

  return targetNumber;
}

int binarySearch(int *pNumbers, int targetNumber)
{
  int low = 0;
  int high = LENGTH - 1;
  int middle;

  while (low <= high)
  {
    middle = (low + high) / 2;

    if (targetNumber == pNumbers[middle])
    {
      return middle;
    }
    else
    {
      if (targetNumber < pNumbers[middle])
      {
        high = middle - 1;
      }
      else
      {
        low = middle + 1;
      }
    }
  }

  return -1;
}

void printResult(int result, int targetNumber)
{
  if (result == -1)
  {
    printf("%d not found", targetNumber);
  }
  else
  {
    printf("%d found at: %d", targetNumber, result + 1);
  }
}
