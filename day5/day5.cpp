#include <fstream>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct{
    int x;
    int y;
} point;

typedef struct{
    // source, destination
    point s;
    point d;
} line;

void part1(){
    ifstream in{"input.txt"};
    vector<line> lines;
    vector<vector<int>> graph{1000, vector<int>(1000, 0)};
    line temp;
    char tempc;
    int count = 0;

    while(in >> temp.s.x){
        // reads data into a temp variable
        in >> tempc >> temp.s.y;
        in >> tempc >> tempc;
        in >> temp.d.x >> tempc >> temp.d.y;

        // if a horizontal/vertical line, add to lines
        if(temp.d.x == temp.s.x || temp.d.y == temp.s.y) lines.push_back(temp);
    }

    for(auto L: lines){
        if(L.d.x == L.s.x){
            // fills in graph spaces for vertical lines
            while(L.s.y != L.d.y){
                graph[L.s.x][L.s.y]++;
                L.s.y > L.d.y ? L.s.y--: L.s.y++;
            }
            graph[L.s.x][L.s.y]++;
        }
        else{
            // fills in graph spaces for horizontal lines
            while(L.s.x != L.d.x){
                graph[L.s.x][L.s.y]++;
                L.s.x > L.d.x ? L.s.x--: L.s.x++;
            }
            graph[L.s.x][L.s.y]++;
        }
    }

    // counts number of points that are intersections 
    for(auto x: graph){
        for(auto y: x) 
            if(y > 1) count++;
    }
    cout << "Number of intersections: " << count << endl;    

    /* test graph output
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    return;
}

void part2(){
    ifstream in{"input.txt"};
    vector<line> lines;
    vector<vector<int>> graph{1000, vector<int>(1000, 0)};
    line temp;
    char tempc;
    int count = 0;

    while(in >> temp.s.x){
        // reads data into a temp variable
        in >> tempc >> temp.s.y;
        in >> tempc >> tempc;
        in >> temp.d.x >> tempc >> temp.d.y;

        // if a horizontal/vertical line, add to lines
        /*if(temp.d.x == temp.s.x || temp.d.y == temp.s.y)*/ 
        lines.push_back(temp);
    }

    for(auto L: lines){
        if(L.d.x == L.s.x){
            // fills in graph spaces for vertical lines
            while(L.s.y != L.d.y){
                graph[L.s.x][L.s.y]++;
                L.s.y > L.d.y ? L.s.y--: L.s.y++;
            }
            graph[L.s.x][L.s.y]++;
        }
        else if(L.d.y == L.s.y){
            // fills in graph spaces for horizontal lines
            while(L.s.x != L.d.x){
                graph[L.s.x][L.s.y]++;
                L.s.x > L.d.x ? L.s.x--: L.s.x++;
            }
            graph[L.s.x][L.s.y]++;
        }
        else{
            // fills in graph spaces for diagonal
            while(L.s.x != L.d.x && L.s.y != L.d.y){
                graph[L.s.x][L.s.y]++;
                L.s.x > L.d.x ? L.s.x--: L.s.x++; 
                L.s.y > L.d.y ? L.s.y--: L.s.y++; 
            }
            graph[L.s.x][L.s.y]++;
        }
    }

    // counts number of points that are intersections 
    for(auto x: graph){
        for(auto y: x) 
            if(y > 1) count++;
    }
    cout << "Number of intersections: " << count << endl;    

    /* test graph output
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }*/
    return;
}

int main(){
    part1();
    part2();
    return 0;
}
