#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    ifstream in("input.txt");
    int depth = 0;
    int dist = 0;
    string command;
    int aim;
    int temp;
    while(in >> command){
        in >> temp;
        if(command == "forward"){
            dist += temp;
            depth += aim * temp;
        }
        else if(command == "up")
            aim -= temp;
        else aim += temp;
    }
    cout << depth << endl;
    cout << dist << endl;
    cout << dist * depth << endl;
    return 0;
}