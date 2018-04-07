#include <functional>
#include <iostream>


int main () {
  std::function<void(int)> count_down;

  count_down = [&count_down] (int num) -> void {
    if (num > 0) {
      std::cout << "i:" << num << std::endl;

      count_down (num - 1);
    }
  };

  count_down (6);
}
