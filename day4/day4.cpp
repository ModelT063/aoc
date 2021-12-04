#include <fstream>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Board{
    public:
        Board(){}
        vector<vector<int>> numbers{5, vector<int>(5, 0)};
        vector<vector<bool>> called{5, vector<bool>(5, false)};
        bool winner();
        void call(int);
        int score(int);
};

bool Board::winner(){
    bool won = true;
    bool won2 = true;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            // checks columns
            if(!called[i][j]) won = false;
            // checks rows
            if(!called[j][i]) won2 = false;
        }
        // returns true if all cases in either 1 row or column passed
        if(won || won2) return true;
        else{
            won = true;
            won2 = true;
        }
    }
    return false;
}

void Board::call(int num){
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(numbers[i][j] == num) called[i][j] = true; 
        }
    }
}

int Board::score(int num){
    int score = 0;
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(!called[i][j]) score += numbers[i][j];
        }
    }
    return score * num;
}
/*
int part1(){
    ifstream in{"input.txt"};
    // contains the numbers to call
    vector<int> nums(100);
    // contains a list of all the boards being played
    vector<Board> boards;
    
    // reads in the numbers to be called 
    char buff;
    int i = 0;
    while(in >> nums[i++] >> buff && i < 99);
    in >> nums[i];

    // reads in boards and puts them into vector of boards
    while(in){
        boards.emplace(boards.end(), Board());
        for(auto &i: boards.back().numbers){
            for(auto &j: i){
                in >> j;
            }
        }
    }
    boards.pop_back();
    // should be 100? reads in extra board of all 0s after file has terminated
    cout << "# of Boards: " << boards.size() << endl;

    // goes through boards, and nums and "calls" them
    for(auto i: nums){
        for(auto &j: boards){
            j.call(i);
            // returns the score upon finding the first winner
            if(j.winner()) return j.score(i);
        }
    }
    // fail case
    return 0;
}*/

void part2(){   
    ifstream in{"input.txt"};
    // contains the numbers to call
    vector<int> nums(100);
    // contains a list of all the boards being played
    vector<Board> boards;
    
    // reads in the numbers to be called 
    char buff;
    int i = 0;
    while(in >> nums[i++] >> buff && i < 99);
    in >> nums[i];

    // reads in boards and puts them into vector of boards
    while(in){
        boards.emplace(boards.end(), Board());
        for(auto &i: boards.back().numbers){
            for(auto &j: i){
                in >> j;
            }
        }
    }
    boards.pop_back();
    
    int count = 0;
    // goes through boards, and nums and "calls" them
    for(auto i: nums){
        for(int j = 0; j < boards.size(); j++){
            boards[j].call(i);
            // prints scores of all the winners
            if(boards[j].winner()){
                if(count == 0 || count == 99) cout << count++ << ": " << boards[j].score(i) << endl;
                else count++;
                boards.erase(boards.begin() + j);
                j--;
            }
        }
    }
}

int main(){
    part2();
    return 0;
}
