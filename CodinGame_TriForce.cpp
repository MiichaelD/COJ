#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 INPUT:
 N = 1
 N = 3
 N = 5

 OUTPUT: 
.*
* *
.    *
    ***
   *****
  *     *
 ***   ***
***** *****
.        *
        ***
       *****
      *******
     *********
    *         *
   ***       ***
  *****     *****
 *******   *******
********* *********




 **/
int main()
{
    int N;
    cin >> N; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int stars = 1;
    int accumBreadth = (N-1) * 2 + 1;
    
    for (int times = 0 ; times < 2 ; ++times, stars = 1){
        for (int line = 0 ; line < N; ++line, stars +=2, --accumBreadth){
            for(int triangles = 0; triangles <= times ; ++triangles){
                for (int i = 0 ; i < accumBreadth; ++i){// SPACE
                    cout << (times == 0 && line == 0 && i == 0 ? '.':' ');
                }    
                
                for (int i = 0 ; i < stars; ++i){ // TRIANGLE
                    cout << '*';
                }
                
                if (times > 0 && triangles < 0){// SPACE - only if we are in the 2nd row and 1st triangle
                    for (int i = -1 ; i < accumBreadth; ++i){
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }
    //
}
