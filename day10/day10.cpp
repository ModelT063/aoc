#include <fstream>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void part1(){
    ifstream in{"input.txt"};
    string temp;
    stack<char> chunks;
    int corrupt[4] = {0};
    vector<long> scores;

    while(getline(in, temp)){
        for(char c: temp){
            if(c == '(' || c == '{' || c == '[' || c == '<') chunks.push(c);
            /******** PART 1 *********/
            else{
                if(c == ')'){
                    if(chunks.top() == '(') chunks.pop();
                    else{
                        // keeps track of which one was corrupted
                        corrupt[0]++;
                        // clears the stack 
                        while(!chunks.empty()) chunks.pop();
                        break;
                    }
                }                
                else if(c == ']'){
                    if(chunks.top() == '[') chunks.pop();
                    else{
                        corrupt[1]++;
                        while(!chunks.empty()) chunks.pop();
                        break;
                    }
                }                
                else if(c == '}'){
                    if(chunks.top() == '{') chunks.pop();
                    else{
                        corrupt[2]++;
                        while(!chunks.empty()) chunks.pop();
                        break;
                    }
                }                
                else if(c == '>'){
                    if(chunks.top() == '<') chunks.pop();
                    else{
                        corrupt[3]++;
                        while(!chunks.empty()) chunks.pop();
                        break;
                    }
                }                
            }
        }
        /***** PART 2 ******/
        // if chunks isn't empty, it means line wasn't corrupt
        if(!chunks.empty()) scores.push_back(0);
        while(!chunks.empty()){
            // updates score properly for each remaining char in the stack
            scores.back() *= 5;
            if(chunks.top() == '(') scores.back()++;
            else if(chunks.top() == '[') scores.back() += 2;
            else if(chunks.top() == '{') scores.back() += 3;
            else if(chunks.top() == '<') scores.back() += 4;
            chunks.pop();
        }
    }


    cout << "PART 1: " <<
    3 * corrupt[0] + 57 * corrupt[1] + 1197 * corrupt[2] + 25137 * corrupt[3] 
    << endl;

    sort(scores.begin(), scores.end());
    cout << "PART 2: " <<  scores[scores.size() / 2] << endl;
    return;
}

void part2(){
    ifstream in{"input.txt"};
    string temp;
    stack<char> chunks;

    return;
}

int main(){
    part1();
    return 0;
}