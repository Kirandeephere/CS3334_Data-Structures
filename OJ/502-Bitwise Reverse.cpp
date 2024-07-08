/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293092
 * Submitted at:  2024-07-08 22:04:33
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    502
 * Problem Name:  Bitwise Reverse
 */

#include <iostream>
using namespace std;

// Function to reverse the bits of the given number
int reverseBits(int num) {
    int reversedNum = 0;
    while (num > 0) {
        reversedNum = (reversedNum << 1) | (num & 1);
        num >>= 1;
    }
    return reversedNum;
}

int main() {
    int num;
    
    while (cin >> num) {
        if (num == 0) break;
        
        int encrypted_num = reverseBits(num);
        
        // Output the encrypted number
        cout << encrypted_num << endl;
    }
    
    return 0;
}