#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
void part1();
void part2();

class Board{
    public:
        Board(){}
        vector<vector<int>> numbers{5, vector<int>(5, 0)};
        vector<vector<bool>> called{5, vector<bool>(5, false)};
        bool winner(Board);
        int score(Board);
};

bool Board::winner(Board b){
    // write this to check if a board has won
}

int Board::score(Board winner){
    // write to calculate a boards score
}

int main(){
    part1();
    return 0;
}

void part1(){
    ifstream in{"input.txt"};
    // contains the numbers to call
    vector<int> nums(100);
    // contains a list of all the boards being played
    vector<Board> boards;
    
    // reads in the numbers to be called 
    char buff;
    int i = 0;
    while(in >> nums[i++] >> buff && buff == ',');

    // reads in boards and puts them into vector of boards
    while(in){
        boards.emplace(boards.end(), Board());
        for(auto i: boards.back().numbers){
            for(auto j: i) in >> j;
        }
    }
    // should be 100? reads in extra board of all 0s after file has terminated
    cout << "# of Boards: " << boards.size() << endl;
}

void part2(){
    
    return;
}