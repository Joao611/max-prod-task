#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Limitations:
 * - Array values may not be either INT_MIN or INT_MAX
 * - Cases with no solution are not supported
 */

bool isMultipleOf3(int n) {
    return n % 3 == 0;
}

int main()
{
    //int a[] = {100, 43, 24, 39, 6, 12}; // all pos
    //int a[] = {100, 43, 0, 39, 6, 12}; // all pos w/ 0
    //int a[] = {-100, -43, -24, -39, -6, -12}; // all negs
    //int a[] = {-100, -43, 0, -39, -6, -12}; // all negs w/ 0
    //int a[] = {1, 0, -3, 4, 5, 30}; // mix w/ solution > 0
    //int a[] = {1, 0, -3, 4, 5, 30, -60}; // mix w/ solution > 0
    //int a[] = {1, -3, 4, 5, 20}; // mix w/ solution < 0
    //int a[] = {1, -3, 0, 4, 5, 20}; // mix w/ solution == 0

    // Custom
    int a[] = {3, 3};

    int pos3 = INT_MIN, high = INT_MIN;
    int neg3 = INT_MAX, low = INT_MAX;
    int pos3CloseTo0 = INT_MAX, neg3CloseTo0 = INT_MIN, posCloseTo0 = INT_MAX, negCloseTo0 = INT_MIN;

    for (int x : a) {
        if (x >= 0) {
            // Highest positive factors
            if (isMultipleOf3(x) && x > pos3) {
                if (pos3 > high) {
                    // save as second best value
                    high = pos3;
                }
                pos3 = x;
            } else if (x > high) {
                high = x;
            }

            // Lowest positive values
            // Used with other values to calculate negative products with the highest value (closest to 0)
            if (isMultipleOf3(x) && x < pos3CloseTo0) {
                if (pos3CloseTo0 < posCloseTo0) {
                    // save as second best value
                    posCloseTo0 = pos3CloseTo0;
                }
                pos3CloseTo0 = x;
            } else if (x < posCloseTo0) {
                posCloseTo0 = x;
            }
        } else if (x < 0) {
            // Lowest negative factors
            if (isMultipleOf3(x) && x < neg3) {
                if (neg3 < low) {
                    // save as second best value
                    low = neg3;
                }
                neg3 = x;
            } else if (x < low) {
                low = x;
            }

            // Highest negative values
            // Used with other values to calculate negative products with the highest value (closest to 0)
            if (isMultipleOf3(x) && x > neg3CloseTo0) {
                if (neg3CloseTo0 > negCloseTo0) {
                    // save as second best value
                    negCloseTo0 = neg3CloseTo0;
                }
                neg3CloseTo0 = x;
            } else if (x > negCloseTo0) {
                negCloseTo0 = x;
            }
        }
    }

    // Sanitize output to filter out default values that to do not exist in the array
    int posProd = (pos3 != INT_MIN && high != INT_MIN) ? pos3 * high : INT_MIN;
    int negProd = (neg3 != INT_MAX && low != INT_MAX) ? neg3 * low : INT_MIN;
    int mixProd1 = (pos3CloseTo0 != INT_MAX && negCloseTo0 != INT_MIN) ? pos3CloseTo0 * negCloseTo0 : INT_MIN;
    int mixProd2 = (neg3CloseTo0 != INT_MIN && posCloseTo0 != INT_MAX) ? neg3CloseTo0 * posCloseTo0 : INT_MIN;

    int maxRes = max(max(max(posProd, negProd), mixProd1), mixProd2);

    std::cout << "Result: " << maxRes << "\n";
    
    return 0;
}
