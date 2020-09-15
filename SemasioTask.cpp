#include <iostream>
#include <algorithm>

using namespace std;

/**
 * Limitations:
 * - Array values may not be either INT_MIN or INT_MAX
 */

bool isMultipleOf3(int n) {
    return n % 3 == 0;
}

int main()
{
    int a[] = {1, 2, -3};

    int pos3 = INT_MIN, high = INT_MIN;
    int neg3 = INT_MAX, low = INT_MAX;
    int pos3CloseTo0 = INT_MAX, neg3CloseTo0 = INT_MIN, posCloseTo0 = INT_MAX, negCloseTo0 = INT_MIN;

    for (int x : a) {
        if (x >= 0) {
            if (isMultipleOf3(x) && x > pos3) {
                if (pos3 > high) {
                    // save as second best value
                    high = pos3;
                }
                pos3 = x;
            } else if (!isMultipleOf3(x) && x > high) {
                high = x;
            }

            if (isMultipleOf3(x) && x < pos3CloseTo0) {
                if (pos3CloseTo0 < posCloseTo0) {
                    // save as second best value
                    posCloseTo0 = pos3CloseTo0;
                }
                pos3CloseTo0 = x;
            } else if (!isMultipleOf3(x) && x < posCloseTo0) {
                posCloseTo0 = x;
            }
        } else if (x < 0) {
            if (isMultipleOf3(x) && x < neg3) {
                if (neg3 < low) {
                    // save as second best value
                    low = neg3;
                }
                neg3 = x;
            } else if (!isMultipleOf3(x) && x < low) {
                low = x;
            }

            if (isMultipleOf3(x) && x > neg3CloseTo0) {
                if (neg3CloseTo0 > negCloseTo0) {
                    // save as second best value
                    negCloseTo0 = neg3CloseTo0;
                }
                neg3CloseTo0 = x;
            } else if (!isMultipleOf3(x) && x > negCloseTo0) {
                negCloseTo0 = x;
            }
        }
    }

    // Sanitize output to filter out default values that to do not exist in the array
    int posProd = (pos3 != INT_MIN && high != INT_MIN) ? pos3 * high : INT_MIN;
    int negProd = (neg3 != INT_MIN && low != INT_MIN) ? neg3 * low : INT_MIN;
    int mixProd1 = (pos3CloseTo0 != INT_MIN && negCloseTo0 != INT_MIN) ? pos3CloseTo0 * negCloseTo0 : INT_MIN;
    int mixProd2 = (neg3CloseTo0 != INT_MIN && posCloseTo0 != INT_MIN) ? neg3CloseTo0 * posCloseTo0 : INT_MIN;

    int maxRes = max(max(max(posProd, negProd), mixProd1), mixProd2);

    std::cout << "Result: " << maxRes << "\n";
}