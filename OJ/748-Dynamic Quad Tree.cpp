/*****************************************
 * (This comment block is added by the Judge System)
 * Submission ID: 237651
 * Submitted at:  2022-12-03 21:01:13
 *
 * User ID:       1991
 * Username:      57153680
 * Problem ID:    748
 * Problem Name:  dynamic quad tree
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Image {
public:
	int n3, imgSize;
	int*** L;

	Image(int);
	~Image() { delete[] L; }
	void count();
	void print(int, int);
};

Image::Image(int size) {
	this->n3 = size + 1;
	this->L = new int** [n3];

	this->imgSize = pow(2, size);
	int** PL = new int* [imgSize];

	for (int i = 0; i < imgSize; i++) {
		int* PR = new int[imgSize];

		string PRString;
		cin >> PRString;

		for (int j = 0; j < imgSize; j++)
			PR[j] = PRString[j] - 48;

		PL[i] = PR;
	}

	L[0] = PL;

	count();
}

void Image::count() {
	if (this->imgSize == 1) {
		L[0][0][0] = 1;
		return;
	}

	int LSize = this->imgSize;

	for (int i = 1; i < n3; ++i) {
		LSize /= 2;
		int** UL = new int* [LSize];

		for (int j = 0; j < LSize; ++j) {
			int* upr = new int[LSize];
			//
			for (int k = 0; k < LSize; ++k) {
				int q1 = L[i - 1][2 * j][2 * k];
				int q2 = L[i - 1][2 * j][2 * k + 1];
				int q3 = L[i - 1][2 * j + 1][2 * k];
				int q4 = L[i - 1][2 * j + 1][2 * k + 1];

				if (q1 == 0 && q2 == 0 && q3 == 0 && q4 == 0) {
					if (i == n3 - 1)
						upr[k] = 1;
					else
						upr[k] = 0;
				}
				else if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1)
					upr[k] = 1;
				else {
					upr[k] = q1 + q2 + q3 + q4 + 1;

					if (q1 == 0)
						++upr[k];
					if (q2 == 0)
						++upr[k];
					if (q3 == 0)
						++upr[k];
					if (q4 == 0)
						++upr[k];
				}
			}

			UL[j] = upr;
		}

		L[i] = UL;
	}
}

void Image::print(int row, int col) {
	int r = row, c = col;
	this->L[0][r][c] = (this->L[0][r][c] + 1) % 2;

	if (this->imgSize == 1)
		L[0][0][0] = 1;

	for (int i = 1; i < n3; ++i) {
		r /= 2;	c /= 2;
		int n4 = L[i][r][c], n5;

		int q1 = L[i - 1][2 * r][2 * c];
		int q2 = L[i - 1][2 * r][2 * c + 1];
		int q3 = L[i - 1][2 * r + 1][2 * c];
		int q4 = L[i - 1][2 * r + 1][2 * c + 1];

		if (q1 == 0 && q2 == 0 && q3 == 0 && q4 == 0)
			if (i == n3 - 1)
				n5 = 1;
			else
				n5 = 0;
		else if (q1 == 1 && q2 == 1 && q3 == 1 && q4 == 1)
			n5 = 1;
		else {
			n5 = q1 + q2 + q3 + q4 + 1;

			if (q1 == 0)
				++n5;
			if (q2 == 0)
				++n5;
			if (q3 == 0)
				++n5;
			if (q4 == 0)
				++n5;
		}

		if (n4 == n5)
			break;
		else
			L[i][r][c] = n5;
	}

	cout << L[n3 - 1][0][0] << endl;
}

int main() {
	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		int size;
		cin >> size;

		Image* image = new Image(size);

		int n2;
		cin >> n2;

		for (int j = 0; j < n2; ++j) {
			int row, col;
			cin >> row >> col;

			image->print(row - 1, col - 1);
		}

		delete image;
	}

	return 0;
}