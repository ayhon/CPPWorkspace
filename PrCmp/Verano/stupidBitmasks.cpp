#include <iostream>
using namespace std;

class BitMask{
	private:
		signed long long bitmask = 0;
	public:
		BitMask(signed long long num): bitmask(num){};

		signed long long * dir() {
			return &bitmask;
		}

		signed long long doble(int veces = 1) {
			return bitmask<<veces;
		}

		signed long long partir(int veces = 1) {
			return bitmask>>veces;
		}

		void set(int idx) {
			bitmask |= 1<<idx;
		}
		void set(int from = 0, int to = 63) {
			unsigned long long m1, m2; // Usamos Unsigned para poder llegar a 2⁶³-1
			m1 = (1<<from)-1;
			m2 = (1<<to)-1;
			bitmask |= (m2-m1);
		}

		void reset(int idx) {
			//bitmask &= 1<<idx;
			//^Esto no funciona. Apagaría todo menos el bit en idx
			bitmask &= ~(1<<idx);
		}
		void reset(int from = 0, int to = 64) {
			unsigned long long m1, m2;
			m1 = (1<<from)-1;
			m2 = (1<<to)-1;
			bitmask &= ~(m2-m1);
		}

		void flip(int idx) {
			bitmask ^= 1<<idx;
		}
		void flip(int from = 0, int to = 64) {
			unsigned long long m1, m2;
			m1 = (1<<from)-1;
			m2 = (1<<to)-1;
			bitmask ^= m2-m1;
		}

		bool isOn(int idx) {
			return (bitmask & 1<<idx);
		}

		// Esta es la razón por la que usamos números con signo
		signed long long valueOfLeastSignificantBitThatIsOn() {
			return (bitmask & -bitmask);
		}

		signed long long lowest1() {
			return valueOfLeastSignificantBitThatIsOn();
		}
};
