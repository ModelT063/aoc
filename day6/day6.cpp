#include <fstream>
#include <iostream>
#include <vector>
using namespace std;


void lanternfish(int days){
    ifstream in{"input.txt"};
    vector<unsigned long long int> fish(9, 0);
    unsigned long long int temp;
    unsigned long long int temp2;
    unsigned long long int old;
    char comma;
    
    //reads in data
    while(in >> temp){
        fish[temp]++;
        in >> comma;
    }

    temp = 0;
    temp2 = 0;
    // simulates # of days
    for(int i = 0; i < days; i++){
        // updates the number of fish j days away from a child
        for(int j = 8; j >= 0; j--){
            if(j == 8) old = fish[0];
            temp2 = fish[j];
            fish[j] = temp;
            temp = temp2;
        }
        // re-adds fish that just birthed
        fish[6] += old;
        temp = fish[0];
    }

    // adds up number of fish
    temp = 0;
    for(auto f: fish) temp += f;
    cout << "Number of lantern fish after " << days << " days is: " << temp << endl;
    return;
}

int main(){
    int choice;
    cout << "Enter number of days to simulate lanternfish growth\n"
    "(80 for part 1, 256 for part 2)\n-> ";
    cin >> choice;
    lanternfish(choice);
    return 0;
}