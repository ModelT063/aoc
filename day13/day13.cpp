#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void part1(){
    ifstream in{"input.txt"};
    vector<vector<int>> matrix (2000, vector<int> (1000, 0));
    int x, y;
    char buff;

    for(int i = 0; i < 722; i++){
        in >> x >> buff >> y;
        matrix[x][y];
    }

    


}

void part2(){
    return;
}

int main(){
    part1();
    return 0;
}