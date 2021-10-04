#include <iostream>
#include <stdexcept>
#include "matrix.h"
#include "point.h"

int main() {
	Matrix<Point> mp(2, 2);
	Matrix<Point> mp1(2, 2);
	Matrix<Point> sp;
	Matrix<int> m(3, 4);
	Matrix<int> m1(3, 4);
	Matrix<int> s;
	try {
		std::cout << "Int example\n";
		int k = 1, l = 1;
		for (int i = 0; i < m.rows(); i++) {
			for (int j = 0; j < m.columns(); j++) {
				m.set(k, i, j); 
				k++;
			}
		}
		m.print();
		std::cout << '+' << '\n';

		for (int i = 0; i < m1.rows(); i++) {
			for (int j = 0; j < m1.columns(); j++) {
				m1.set(l * l, i, j); 
				l++;
			}
		}
		m1.print();
		std::cout << '=' << '\n';
		s = m.sum(m1);
		s.print();
		
		std::cout << "\nPoint example\n";
		int x = 1, y = 2, z = 3, x1 = 1, y1 = 2, z1 = 3;
		for (int i = 0; i < mp.rows(); i++) {
			for (int j = 0; j < mp.columns(); j++) {
				Point p(x, y, z);
				mp.set(p, i, j);
				x++; y++; z++;
			}
		}
		mp.print();
		std::cout << '+' << '\n';
		for (int i = 0; i < mp1.rows(); i++) {
			for (int j = 0; j < mp1.columns(); j++) {
				Point p1(x1 * x1, y1 * y1, z1 * z1);
				mp1.set(p1, i, j);
				x1++; y1++; z1++;
			}
		}

		mp1.print();
		std::cout << '=' << '\n';
		sp = mp.sum(mp1);
		sp.print(); 
		
	}

	catch (std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
	catch (std::range_error& e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}