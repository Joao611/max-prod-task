#include <iostream>
#include <algorithm>

using namespace std;

bool isMultipleOf3(int n) {
    return n % 3 == 0;
}

int main()
{
    int a[] = {100, 43, 24, 39, 6, 12};

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

    int posProd = pos3 * high;
    int negProd = neg3 * low;
    int mixProd1 = pos3CloseTo0 * negCloseTo0;
    int mixProd2 = neg3CloseTo0 * posCloseTo0;

    int maxRes = max(max(max(posProd, negProd), mixProd1), mixProd2);

    std::cout << "Result: " << maxRes << "\n";
}