#include <stdio.h>
#include <stdlib.h>

unsigned short *createArray(unsigned short number);
unsigned short getNumber();
unsigned short *createNumbers(unsigned short number);
unsigned short *getNumbers(unsigned short number, unsigned short *pNumbers);
void printNumbers(unsigned short number, unsigned short *pNumbers);
void locateMinMax(unsigned short number, unsigned short *pNumbers, unsigned short *min, unsigned short *max);
float calculateAve(unsigned short number, unsigned short *pNumbers);

int main(void)
{
  unsigned short number, index, min, max;
  unsigned short *pNumbers;
  float ave;

  number = getNumber();
  pNumbers = createNumbers(number);
  getNumbers(number, pNumbers);
  printNumbers(number, pNumbers);
  locateMinMax(number, pNumbers, &min, &max);
  ave = calculateAve(number, pNumbers);

  printf("The minimum number is %hu\n", min);
  printf("The maximum number is %hu\n", max);
  printf("The average is %.2lf\n", ave);

  free(pNumbers);

  return 0;
}

unsigned short getNumber()
{
  unsigned short number;

  do
  {
    printf("Enter how many numbers you would like.\nIt should be up to 10 numbers. Enter 0 to exit.\n-> ");
    scanf("%hd", &number);

    if (0 == number)
    {
      printf("After a while, crocodile");
      exit(1);
    }
  } while (number < 0 || 10 < number);

  return number;
}

unsigned short *getNumbers(unsigned short number, unsigned short *pNumbers)
{
  unsigned short index;

  for (index = 0; index < number; index++)
  {
    scanf("%hd", &pNumbers[index]);
  }

  return pNumbers;
}

unsigned short *createNumbers(unsigned short number)
{
  unsigned short index, *pNumbers;

  printf("Enter %d numbers that you want\n", number);
  pNumbers = createArray(number);

  return pNumbers;
}

void printNumbers(unsigned short number, unsigned short *pNumbers)
{
  unsigned short index;

  printf("\nHere are your numbers:\n");
  for (index = 0; index < number; index++)
  {
    printf("%d ", pNumbers[index]);
  }

  printf("\n\n");
}

void locateMinMax(unsigned short number, unsigned short *pNumbers, unsigned short *min, unsigned short *max)
{
  unsigned short index;
  *min = pNumbers[0];
  *max = pNumbers[0];

  for (index = 0; index < number; index++)
  {
    if (pNumbers[index] < *min)
    {
      *min = pNumbers[index];
    }

    if (pNumbers[index] > *max)
    {
      *max = pNumbers[index];
    }
  }
}

float calculateAve(unsigned short number, unsigned short *pNumbers)
{
  float ave = 0.0;
  unsigned short total = 0;
  unsigned short index;

  for (index = 0; index < number; index++)
  {
    total += pNumbers[index];
  }

  ave = (float)total / (float)number;

  return ave;
}

unsigned short *createArray(unsigned short number)
{
  unsigned short *array = (unsigned short *)malloc(sizeof(unsigned short) * number);

  if (array == NULL)
  {
    printf("Memory allocation failed!\n");
    exit(1);
  }

  return array;
}
