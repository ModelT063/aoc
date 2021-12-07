#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lanternfish(int days){
    ifstream in{"input.txt"};
    vector<unsigned long long int> fish(9, 0);
    unsigned long long int temp;
    char comma;
    
    //reads in data
    while(in >> temp){
        fish[temp]++;
        in >> comma;
    }

    // simulates # of days
    for(int i = 0; i < days; i++){
        // updates the number of fish j days away from a child
		rotate(fish.begin(), fish.begin() + 1, fish.end());
		fish[6] += fish[8];
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
