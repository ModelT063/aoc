#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

int flash(vector<vector<int>> &levels, int x, int y){
    int flashes = 0;
    levels[x][y] = (levels[x][y] + 1) % 10;

    if(levels[x][y] == 0){
        flashes++;
        // recurses if not going out of bounds, and not recursing on an already 
        // flashed octopus (checks if value is 0)
        // Left Right Up Down
        if(x < 9 && levels[x + 1][y]) flashes += flash(levels, x + 1, y);
        if(y < 9 && levels[x][y + 1]) flashes += flash(levels, x, y + 1);
        if(x > 0 && levels[x - 1][y]) flashes += flash(levels, x - 1, y);
        if(y > 0 && levels[x][y - 1]) flashes += flash(levels, x, y - 1);
        // bottom Left, bottom Right (y increases down)
        if(x > 0 && y < 9 && levels[x - 1][y + 1]) flashes += flash(levels, x - 1, y + 1);
        if(x > 9 && y < 9 && levels[x + 1][y + 1]) flashes += flash(levels, x + 1, y + 1);
        // top Left, top Right
        if(x > 0 && y > 0 && levels[x - 1][y - 1]) flashes += flash(levels, x - 1, y - 1);
        if(x < 9 && y > 0 && levels[x + 1][y - 1]) flashes += flash(levels, x + 1, y - 1);
    }
    return flashes;
}

void part1(){
    ifstream in{"test.txt"};
    vector<vector<int>> energy(10, vector<int> (10));
    char buf;
    int count = 0;

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            in >> buf;
            energy[i][j] = buf - 48;
        }
    }

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                energy[j][k] = (energy[j][k] + 1) % 10;
            }
        }
        // call recursion in a loop here ??
        
        for(auto h: energy){
            for(auto l: h){
                cout << l;
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << count << endl;
}

void part2(){
    
}

int main(){
    part1();
    return 0;
}