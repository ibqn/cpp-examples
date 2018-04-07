#include <iostream>

using namespace std;

template <typename T>
int size_in_bits (const T &v) {
    return sizeof(v)*8;
}


int main () {
    cout << size_in_bits (32) << endl;
}
