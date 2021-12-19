#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int flash(vector<vector<int>> &levels, int x, int y){
    int flashes = 0;

    if(levels[x][y] > 9){
        levels[x][y] = 0;
        flashes++;
        // recurses if not going out of bounds, and not recursing on an already 
        // flashed octopus (checks if value is 0)
        // Left Right Up Down
        if(x < 9 && levels[x + 1][y]) {
            levels[x + 1][y]++;
            flashes += flash(levels, x + 1, y);
        }
        if(y < 9 && levels[x][y + 1]){
            levels[x][y + 1]++;
            flashes += flash(levels, x, y + 1);
        }
        if(x > 0 && levels[x - 1][y]){
            levels[x - 1][y]++;
            flashes += flash(levels, x - 1, y);
        }
        if(y > 0 && levels[x][y - 1]){
            levels[x][y - 1]++;
            flashes += flash(levels, x, y - 1);
        }
        // bottom Left, bottom Right (y increases down)
        if(x > 0 && y < 9 && levels[x - 1][y + 1]){
            levels[x - 1][y + 1]++;
            flashes += flash(levels, x - 1, y + 1);
        }
        if(x < 9 && y < 9 && levels[x + 1][y + 1]){
            levels[x + 1][y + 1]++;
            flashes += flash(levels, x + 1, y + 1);
        }
        // top Left, top Right
        if(x > 0 && y > 0 && levels[x - 1][y - 1]){
            levels[x - 1][y - 1]++;
            flashes += flash(levels, x - 1, y - 1);
        }
        if(x < 9 && y > 0 && levels[x + 1][y - 1]){
            levels[x + 1][y - 1]++;
            flashes += flash(levels, x + 1, y - 1);
        }
    }
    return flashes;
}

// checks if all energey levels are 0
bool checkZero(vector<vector<int>> levels){
    for(auto i: levels){
        for(auto j: i)
            if(j) return false;
    }
    return true;
}

void part1(){
    ifstream in{"input.txt"};
    vector<vector<int>> energy(10, vector<int> (10));
    char buf;
    int count = 0;

    // reads in input data
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            in >> buf;
            energy[i][j] = buf - 48;
        }
    }

    // simulates number of days
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++)
                energy[j][k] = energy[j][k] + 1;
        }
        // checks if an octopus will flash
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                count += flash(energy, j, k);
            }
        }
    }
    cout << count << endl;
}

void part2(){
    ifstream in{"input.txt"};
    vector<vector<int>> energy(10, vector<int> (10));
    char buf;
    int count = 0;

    // reads in input data
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            in >> buf;
            energy[i][j] = buf - 48;
        }
    }

    // runs until all energy levels hit 0
    while(!checkZero(energy)){ 
        // keeps count of # of steps
        count++;
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++)
                energy[j][k] = energy[j][k] + 1;
        }
        
        // call recursion in a loop here ??
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                flash(energy, j, k);
            }
        }
    }

    cout << count << endl;
}

int main(){
    part1();
    part2();
    return 0;
}