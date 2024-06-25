#include <stdio.h>

int main(void)
{
  int numOfEle, length;
  int array[] = {25, 43, 34, 61, 85, 90, 37, 12};

  length = sizeof(array) / sizeof(array[0]);

  for (numOfEle = length; numOfEle >= 2; numOfEle--)
  {
    for (int index = 0; index <= numOfEle; index++)
    {
      if (array[index] > array[index + 1])
      {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
      }
    }
  }

  for (int index = 0; index < length; index++)
  {
    printf("%d ", array[index]);
  }

  printf("\n");

  return 0;
}
