#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    // PART 1
    ifstream in{"input.txt"};
    int count = 0;
    int cur;
    int prev;

    in >> cur;
    while(in){
        prev = cur;
        in >> cur;
        if(cur > prev) count++;
    }
    in.close();
    
    cout << "PART 1: " << count << endl;
    return 0;
}
