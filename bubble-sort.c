#include <stdio.h>

int main(void)
{
  int numbers[] = {23, 44, 34, 60, 85, 95, 37, 9};
  int length = sizeof(numbers) / sizeof(numbers[0]);

  for (int lastIndex = length; lastIndex >= 2; lastIndex--)
  {
    for (int index = 0; index < lastIndex - 1; index++)
    {
      if (numbers[index] > numbers[index + 1])
      {
        int aside = numbers[index];
        numbers[index] = numbers[index + 1];
        numbers[index + 1] = aside;
      }
    }
  }

  for (int index = 0; index < length; index++)
  {
    printf("%d ", numbers[index]);
  }

  printf("\n");

  return 0;
}
