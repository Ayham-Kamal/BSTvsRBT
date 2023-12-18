#include <iostream>
#include <stdlib.h>
#include "utility.h"

using namespace std;

// PRE: num, low, high are defined as an integer, array[0]..array[size-1]
// are defined.
// POST: find the index where num lies before.
// RV = index where num lies before.
int modifiedBinarySearch(double num, int low, int high, double array[]){
  int index = 0;
  int mid = low + ((high - low) / 2);
  bool found = false;
  while ((low <= high) && (!found)) {

    // Check if x is present at mid
    if (array[mid] == num){
      index = mid;
      found = true;
    }

    // If x greater, ignore left half
    else if (array[mid] < num){
      low = mid + 1;
    }

    // If x is smaller, ignore right half
    else{
      high = mid - 1;
    }
    mid = low + ((high - low) / 2);
  }
  
  // If we reach here, then element was not present
  // return -1;
  if (!found){
    if (num > array[mid]){
      index = mid+1;
    }
    else {
      index = mid;
    }
  }
  return (index);

}

// PRE: low < high are defined
// POST: RV = a number x, low <= x <= high with uniform
//             probability.
double myRandom (int low, int high) {
  double x = (random() % (high - low + 1)) + low;
  // x = x/100;
  //double x = ((double) rand() / (RAND_MAX));
  
  return (x);
}

// PRE: low < high are defined.
//      percentages[0]..percentages[high-low] are defined,
//          and > 0, and
//      percentages[0] + percentages[1] + ... +
//         percentages[high-low] = 100.
// POST: RV = x, low <= x <= high, and x is generated with
//         percentages[x-low] percent of the time.
int myRandom2 (int low, int high, double percentages[]) {
  int size = (high - low +1);
  
  double * binarySearchArray = new double[size];
  
  binarySearchArray[0] = percentages[0];
  for (int loc = 1; loc < size; loc++){
    binarySearchArray[loc] = percentages[loc]+binarySearchArray[loc-1];
  }

  // Using srand() with time(0) to change
  // the random values everytime
  //srand(time(0));
  
  double num = (double)(random()) / RAND_MAX;
  int index = modifiedBinarySearch(num, 0, size, binarySearchArray);
  
  return(low+(index)); // Which operation: 1: insert, 2: delete, 3: search
}


// PRE: frac is declared and defined as a list of characters.
// POST: Convert the fraction to a double.
// RV = the double value of the fraction.
double getFraction(char frac[]){
  double num = 0;
  double den = 0;
  double fraction;
  
  int sizeNum = 0;
  int indexNum = 0;
  while (frac[indexNum] != '/'){
    sizeNum++;
    indexNum++;
  }
  int power = 1;
  for (int loc = (sizeNum - 1); loc >= 0; loc--){
    int digit = ((int)frac[loc] - (int)'0');
    num+= (digit)*(power);
    power*=10;
  }

  int sizeDen = 0;
  int indexDen = (indexNum + 1);
  while (frac[indexDen] != '\0'){
    sizeDen++;
    indexDen++;
  }
  power = 1;
  for (int loc = (sizeNum+sizeDen); loc >= (sizeNum+1); loc--){
    int digit = ((int)frac[loc] - (int)'0');
    den+= (digit)*(power);
    power*=10;
  }

  fraction = num / den;
  return(fraction);
}
