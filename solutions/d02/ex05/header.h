#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/

/*--------------------------------
  :) function you must implement
  --------------------------------*/
int	searchShifted(int *rocks, int length, int value);

/*--------------------------------
  ?? test function used in main
  --------------------------------*/
int *createRandomArray(int n);
void printArray(int *arr, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/
int binarySearch(int *rocks, int low, int high, int value);
int findPivot(int *rocks, int low, int high);

#endif
