// beecrowd 2670 - Coffee Machine

#include <iostream>
using namespace std;

int main() {
    int floor1, floor2, floor3;
    int time1, time2, time3;

    // Read the number of employees on each floor
    cin >> floor1 >> floor2 >> floor3;

    // Calculate the total time for each machine position
    time1 = (floor2 * 2) + (floor3 * 4);  // Machine on the 1st floor
    time2 = (floor1 * 2) + (floor3 * 2);  // Machine on the 2nd floor
    time3 = (floor1 * 4) + (floor2 * 2);  // Machine on the 3rd floor

    // Find the minimum time and output it
    if (time1 <= time2 && time1 <= time3) {
        cout << time1 << endl;
    } else if (time2 <= time1 && time2 <= time3) {
        cout << time2 << endl;
    } else {
        cout << time3 << endl;
    }

    return 0;
}
