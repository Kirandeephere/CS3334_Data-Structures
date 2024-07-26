/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 293118
 * Submitted at:  2024-07-24 14:06:38
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    394
 * Problem Name:  Binary
 */

#include <iostream>
#include <bitset>
#include <string>

int main() {
    unsigned int number;

    // Read numbers until end of file
    while (std::cin >> number) {
        // Convert number to binary string using bitset<16>
        std::string binaryString = std::bitset<16>(number).to_string();

        // Remove leading zeros
        size_t firstOne = binaryString.find('1');
        if (firstOne != std::string::npos) {
            binaryString = binaryString.substr(firstOne);
        } else {
            binaryString = "0";  // Handle case for 0 explicitly
        }

        // Print the binary string
        std::cout << binaryString << std::endl;
    }

    return 0;
}