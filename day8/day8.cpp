#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void part1(){
    ifstream in{"input.txt"};
    string segments;
    int count = 0;
    while(getline(in, segments, '|')){
        for(int i = 0; i < 4; i++){
            in >> segments;
            switch(segments.length()){
                case 2: case 3: case 4: case 7:
                    count++; 
                    break;
            }
        }
    }
    in.close();
    cout << count << endl;
}

void part2(){
    ifstream in{"input.txt"};
    

}

int main(){
    part1();
    return 0;
}