#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int getNumber();
int getOption();
int *createArray(int number);
int *generateNumbers(int number);
int *generateUnsortedNumbers(int number, int rangeUpToNumber, int *unsortedArray);
void sortNumbers(int number, int *unsortedNumbers, int option);

int main()
{
  int number, option;
  int *unsortedNumbers;

  number = getNumber();
  unsortedNumbers = generateNumbers(number);
  option = getOption();

  switch (option)
  {
  case 1:
    printf("Sorting in ascending order:\n");
    sortNumbers(number, unsortedNumbers, option);
    break;
  case 2:
    printf("Sorting in descending order:\n");
    sortNumbers(number, unsortedNumbers, option);
    break;
  default:
    printf("All right. We will see you when we see you!");
    break;
  }

  printf("\n");
  free(unsortedNumbers);
  return 0;
}

int getNumber()
{
  int number;

  do
  {
    printf("Enter how many numbers you would like.\n-> ");
    scanf("%d", &number);
  }while(number <= 0);

  return number;
}

int *generateNumbers(int number)
{
  int rangeUpToNumber = 100;
  int *unsortedNumbers;
  int *unsortedArray = createArray(number);

  printf("We are generating randum numbers in the range of 0 to %d.\n", rangeUpToNumber);
  sleep(3);
  unsortedNumbers = generateUnsortedNumbers(number, rangeUpToNumber, unsortedArray);

  return unsortedNumbers;
}

int *createArray(int number)
{
  int *array = (int *)malloc(number * sizeof(int));

  if (array == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  return array;
}

int *generateUnsortedNumbers(int number, int rangeUpToNumber, int *unsortedArray)
{
  srand(time(NULL));
  int randumNumber, index;

  for (index = 0; index < number; index++)
  {
    randumNumber = rand() % (rangeUpToNumber + 1);
    unsortedArray[index] = randumNumber;
  }

  printf("Here is the unsorted numbers;\n");

  for (index = 0; index < number; index++)
  {
    printf("%d ", unsortedArray[index]);
  }

  printf("\n");

  return unsortedArray;
}

int getOption()
{
  int option;

  do
  {
    printf("\nHow would you like to sort the unsorted numbers?\n1: Ascending order 2: Descending order 3: Well, it is fine as it is.\n-> ");
    scanf("%d", &option);
  } while (option <= 0 || 4 <= option);

  return option;
}

void sortNumbers(int number, int *unsortedNumbers, int option)
{
  int count, index, tmp;

  if (option == 1)
  {
    for (count = 1; count < number; count++)
    {
      for (index = count - 1; index >= 0; index--)
      {
        if (unsortedNumbers[index] > unsortedNumbers[index + 1])
        {
          tmp = unsortedNumbers[index];
          unsortedNumbers[index] = unsortedNumbers[index + 1];
          unsortedNumbers[index + 1] = tmp;
        }
        else
        {
          break;
        }
      }
    }

    for (index = 0; index < number; index++)
    {
      printf("%d ", unsortedNumbers[index]);
    }
  }
  else
  {
    for (count = 1; count < number; count++)
    {
      for (index = count - 1; index >= 0; index--)
      {
        if (unsortedNumbers[index] < unsortedNumbers[index + 1])
        {
          tmp = unsortedNumbers[index];
          unsortedNumbers[index] = unsortedNumbers[index + 1];
          unsortedNumbers[index + 1] = tmp;
        }
        else
        {
          break;
        }
      }
    }

    for (index = 0; index < number; index++)
    {
      printf("%d ", unsortedNumbers[index]);
    }
  }
}
