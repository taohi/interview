#include <iostream>
using namespace std;

bool find(int *a,int rows,int columns,int number)
{
    bool found = false;
    int row = 0,col = columns -1;
    while(row <rows && col >=0)
    {
        if(a[row*columns+col]>number)
            col--;
        else if(a[row*columns+col]== number)
        {
            found = true;
            break;
        }
        else
            row++;
    }
    return found;
}

int main()
{
    int a[4][4] = { {1,2,8,9},
        {2,4,9,12},
        {4,7,10,13},
        {6,8,11,15},
    };
    int number=9;
    bool found = find(&a[0][0],4,4,number);
    if(found)
        cout << number << " is in the matrix" << endl;
    else
        cout << number << " isn't in the matrix" << endl;
    return 0;
}
