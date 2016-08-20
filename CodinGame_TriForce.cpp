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
* 
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


void submitedSolution(int N){
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
}


int main()
{
    int N;
    cin >> N; cin.ignore();

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    int maxTimes = 2; // the challenge just asked for top triangle and 2 below.
    int stars = 1;
    int smallestTriangleBase = (N-1) * 2 + 1;
    int half = N*maxTimes-1;
//    cout << "Smallest: "<<smallestTriangleBase << ", half: " << half << endl;
    int accumBreadth = half;
    
    for (int times = 0 ; times < maxTimes ; ++times, stars = 1){
        for (int line = 0 ; line < N; ++line, stars +=2, --accumBreadth){
            for(int triangles = 0; triangles <= times ; ++triangles){
                if (triangles  == 0)
                    for (int i = 0 ; i < accumBreadth; ++i){// SPACE
                        cout << (times == 0 && line == 0 && i == 0 ? '.':' ');
                    }    
                
                for (int i = 0 ; i < stars; ++i){ // TRIANGLE
                    cout << '*';
                }
                
                if (triangles < times){// SPACE - only if we are in the 2nd row and 1st triangle
                    //for (int i = smallestTriangleBase - ((line % N) * 2) ; i > 0 ; --i){ same result as the next line 
                    for (int i = smallestTriangleBase - stars + 1 ; i > 0 ; --i){
                        cout << ' ';
                    }
                }
            }
            cout << endl;
        }
    }
}
}
