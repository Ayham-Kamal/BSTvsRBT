#ifndef INCLUDED_UTILITY
#define INCLUDED_UTILITY


// PRE: num, low, high are defined as an integer, array[0]..array[size-1]
// are defined.
// POST: find the index where num lies before.
// RV = index where num lies before.
int modifiedBinarySearch(double num, int low, int high, double array[]);

// PRE: low < high are defined
// POST: RV = a number x, low <= x <= high with uniform
//             probability.
double myRandom (int low, int high);


// PRE: low < high are defined.
//      percentages[0]..percentages[high-low] are defined,
//          and > 0, and
//      percentages[0] + percentages[1] + ... +
//         percentages[high-low] = 100.
// POST: RV = x, low <= x <= high, and x is generated with
//         percentages[x-low] percent of the time.
int myRandom2 (int low, int high, double percentages[]);

// PRE: frac is declared and defined as a list of characters.
// POST: Convert the fraction to a double.
// RV = the double value of the fraction.
double getFraction(char frac[]);


#endif
