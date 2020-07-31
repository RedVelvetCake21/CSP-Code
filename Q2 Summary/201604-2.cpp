#include <iostream>
using namespace std;
bool square[19][10]; //大小设置为19就不用考虑边界
bool pic[4][4];
bool stop_row(int row, int col) {
    int i, j;
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            if (pic[i][j] == 1 && square[i+row][j+col] == 1) return true;
    return false;
}

int main() {
    int i, j, num;
    for (i = 0; i < 19; ++i)
        for (j = 0; j < 10; ++j)
            square[i][j] = 1;
    for (i = 0; i < 15; ++i)
        for (j = 0; j < 10; ++j)
            cin >> square[i][j];
    for (i = 0; i < 4; ++i)
        for (j = 0; j < 4; ++j)
            cin >> pic[i][j];
    cin >> num;
    num -= 1;
    int flag = 0;
    for (i = 0; i < 15; ++i) {
        if (stop_row(i, num))
            break;
        flag = i;
    }
    for (i = 0; i < 4; ++i)
        for(j = 0; j< 4; ++j)
            if (pic[i][j] == 1)
                square[flag+i][num+j] = 1;
    for(i = 0; i < 15; ++i){
        for(j = 0; j < 10; ++j)
            cout << square[i][j] << " ";
        cout << endl;
    }
    return 0;
}
