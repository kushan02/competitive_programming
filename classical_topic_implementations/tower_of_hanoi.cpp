#include<iostream>

using namespace std;


void move_disc(int n, int tower_from, int tower_using, int tower_to) {

    if (n == 1) {
        cout << "Move top disc from tower=" << tower_from << " to tower=" << tower_to << endl;
        return;
    }

    move_disc(n - 1, tower_from, tower_to, tower_using);
    move_disc(1, tower_from, tower_using, tower_to);
    move_disc(n - 1, tower_using, tower_from, tower_to);
}

void solve_tower_of_hanoi(int n) { // for 3 towers with n discs
    move_disc(n, 1, 2, 3);
}

int main() {

    solve_tower_of_hanoi(5);

    return 0;
}