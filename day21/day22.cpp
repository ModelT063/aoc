#include <iostream>
using namespace std;

void part1(){
    //Player 1 starting position: 6
    //Player 2 starting position: 3
    int pos1 = 5; // array notation
    int pos2 = 2;

    // holds the score values for p1 and 2
    int score1 = 0;
    int score2 = 0;

    // holds the current dice value and # of times rolled
    int dice = 1;
    int count = 0;

    while(score1 < 1000 && score2 < 1000){
        // player 1
        pos1 = (pos1 + dice + dice + 1 + dice + 2) % 10;
        score1 += pos1 + 1;
        // updates dice number, makes sure 0 is never hit
        dice = (dice + 3) % 100 == 0 ? 100: (dice + 3) % 100;
        count += 3;

        // player 2
        if(score1 < 1000){
            pos2 = (pos2 + dice + dice + 1 + dice + 2) % 10;
            score2 += pos2 + 1;
            dice = (dice + 3) % 100 == 0 ? 100: (dice + 3) % 100;
            count += 3;
        }
    }
    cout << "Player 1: " << score1 << "\nPlayer 2: " << score2 << "\nFINAL: "
        << count * (score1 < score2 ? score1: score2) << endl; 
}

void part2(){
    // idk even wtf to do here lmao
}

int main(){
    part1();
    return 0;
}