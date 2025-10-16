#include <iostream>

int main() {
    int codeArray[48] = {16, 6, 19, 24, 14, 11, 18, 12, 15, 17, 2, 13, 22, 7, 10, 3, 23, 5, 20, 8, 9, 1, 4, 21, 116, 108, 32, 33, 104, 119, 101, 105, 32, 104, 111, 116, 97, 117, 32, 111, 109, 32, 101, 99, 107, 71, 100, 120};
    int* pointerArray[24] = {};
    const int n = 24;

    // 1) Build an index map:
    //    Scan the first half of codeArray (indices 0 to n-1).
    //    codeArray[p] contains a rank (from 1 to n).
    //    We want pointerArray[rank - 1] to point to the element n positions ahead of p.
    for (int p = 0; p < n; ++p) {

        int rank = codeArray[p];


        int pointer_index = rank - 1;


        pointerArray[pointer_index] = &codeArray[p + n];
    }

    std::cout << "The secret code is:\n";
    for (int i = 0; i < n; ++i) {

        int ascii_code = *pointerArray[i];


        std::cout << (char)ascii_code;
    }
    std::cout << std::endl;

    return 0;
}