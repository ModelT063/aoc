#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void part1(){
    ifstream in{"input.txt"};
    vector<int> pos;
    int temp;
    char buf;
 
    while(in >> temp){
        pos.push_back(temp);
        in >> buf;
    }

    // calculates median position
    sort(pos.begin(), pos.end());
    int position = pos[pos.size() / 2]; 

    int fuel = 0;
    for(auto i: pos) fuel += abs(position - i);

    cout << position << " " << fuel << endl;
}

int sum(int num){
    int total = 0;
    for(int i = 1; i <= num; i++) total += i;
    return total;
}

// brute forces since average/median doesn't work
void part2(){
    ifstream in{"input.txt"};
    vector<int> pos;
    int temp;
    char buf;
 
    while(in >> temp){
        pos.push_back(temp);
        in >> buf;
    }

    /*/ calculates average position
    float position = 0;
    for(int i: pos) position += i;
    position = round(position / pos.size());*/

    // calculates amount of fuel needed
    int fuel = 0;
    sort(pos.begin(), pos.end());
    vector<int> min_fuel;
    for(int a = 0; a <= pos.back(); a++){
        for(auto i: pos) fuel += sum(abs(a - i));
        min_fuel.push_back(fuel);
        fuel = 0;
    }

    sort(min_fuel.begin(), min_fuel.end());
    cout << min_fuel[0] << endl;
}
int main(){
    part2();
    return 0;
}