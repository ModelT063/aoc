#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void part1(){
    ifstream in{"input.txt"};
    vector<vector<int>> numbers;
    string temp;
    int total = 0;
    // reads data into a 2d vector
    while(getline(in, temp)){
        vector<int> vtemp;
        for(char c: temp) vtemp.push_back(c - 48);
        numbers.push_back(vtemp);
    }

    for(auto i: numbers){
        for(auto j: i){
            cout << j;
        }
        cout << endl;
    }

    // iterates through each number in the vectorj
    for(int i = 0; i < numbers.size(); i++){
        for(int j = 0; j < numbers[i].size(); j++){
            if(numbers[i][j] < (j < numbers[i].size() - 1? numbers[i][j + 1]: 10) &&
            numbers[i][j] < (j > 0? numbers[i][j - 1]: 10) &&
            numbers[i][j] < (i > 0 ? numbers[i - 1][j]: 10) &&
            numbers[i][j] < (i < numbers[i].size() - 1? numbers[i + 1][j]: 10)) 
                total += numbers[i][j] + 1;
        }
    }

    cout << total << endl;
    return;
}

void part2(){
    return;
}

int main(){
    part1();
    return 0;
}