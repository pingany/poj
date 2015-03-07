#include <iostream>
#include <algorithm>
#include <functional>
#include <cstring>
#include <cstdio>
using namespace std;
bool used[100];
int stick[100];
int stick_num;
bool concate(int unused, int left, int target_len) {
    if (unused == 0 && left == 0)
       return true;
    if (left == 0) {
       left = target_len;
    }
    for (int i = 0; i < stick_num; i++) {
       if (used[i])
           continue;
       if (stick[i] > left)
           continue;
       used[i] = true;
       if (concate(unused - 1, left - stick[i], target_len))
           return true;
       used[i] = false;
       if (stick[i] == left || left == target_len)
           break;
    }
    return false;
}
int main() {
    while (true) {
       int sum = 0;
       memset(used, 0, sizeof(used));
       memset(stick, 0, sizeof(stick));
       cin >> stick_num;
       if (stick_num == 0)
           break;
       for (int i = 0; i < stick_num; i++) {
           scanf("%d", &stick[i]);
           sum += stick[i];
       }
       sort(stick, stick + stick_num, greater<int> ());
       for (int i = stick_num; i > 0; i--) {
           if ((sum % i == 0) && (sum / i >= stick[0])) {
              if (concate(stick_num, 0, sum / i)) {
                  cout << sum / i << endl;
                  break;
              }
           }
       }
    }
    return 0;
}