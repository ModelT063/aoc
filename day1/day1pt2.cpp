#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main(){
    ifstream in{"input.txt"}; 
    int count = 0; 
    int temp; 
    vector<int> input;
    
    while(in >> temp)
        input.push_back(temp);
    in.close();

    for(int i = 0; i + 4 < input.size(); i++) 
        if(input[i] + input[i + 1] + input[i + 2] 
           < input[i + 1] + input[i + 2] + input[i + 3]) count++;
    
    cout << "PART 2: " << count << endl;
    return 0;
}
