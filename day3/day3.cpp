#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
void part1();
void part2();
using namespace std;

int main(){
	part1();
	part2();
	return 0;
}

void part1(){
	string line;
	vector<int> num(12);
	int gamma = 0;
	ifstream in("input.txt");
	while(in >> line){
		for(int i = 0; i < 12; i++)
			if(line[i]=='1') num[i]++;
	}

	for(int i = 0; i < 12; i++){
		if(num[i] >= 500) num[i] = 1;
		else num[i] = 0;
	}

	for(int i = 0; i < 12; i++)
		if(num[i]) gamma += pow(2, 11 - i);
	
	cout << gamma * (gamma^0xFFF) << endl;
	return;
}

void part2(){
	vector<string> lines(1000);
	ifstream in("input.txt");
	int i = 0;
	while(in >> lines[i]) i++;
	in.close();
	i = 0;
	
	int num = 0;
	int oxy = 0;
	while(lines.size() != 1 && i < 12){
		for(auto j: lines)
			if(j[i] == '1') num++;
		if(num >= lines.size() - num)
			for(int j = 0; j < lines.size(); j++){
				if(lines[j][i] == '0'){
					lines.erase(lines.begin() + j);
					j--;
				}
			}
		else{
			for(int j = 0; j < lines.size(); j++){
				if(lines[j][i] == '1'){
					lines.erase(lines.begin() + j);
					j--;
				}
			}
		}
		i++;
		num = 0;
	} 
	cout << lines.size() << endl;
	for(int k = 0; k < 12; k++)
		if(lines[0][k]=='1') oxy += pow(2, 11 - k);

	ifstream in2("input.txt");
	vector<string> lines2(1000);
	i = 0;
	while(in2 >> lines2[i]) i++;
	in2.close();
	i = 0;

	num = 0;
	int co = 0;
	while(lines2.size() != 1 && i < 12){
		for(auto j: lines2)
			if(j[i] == '1') num++;

		if(num >= lines2.size() - num)
			for(int j = 0; j < lines2.size(); j++){
				if(lines2[j][i] == '1'){
					lines2.erase(lines2.begin() + j);
					j--;
				}
			}
		else{
			for(int j = 0; j < lines2.size(); j++){
				if(lines2[j][i] == '0'){
					lines2.erase(lines2.begin() + j);
					j--;
				}
			}
		}		
		i++;
		num = 0;
	} cout << lines2.size() << endl;
	
	for(int k = 0; k < 12; k++)
		if(lines2[0][k]=='1') co += pow(2, 11 - k);

	cout << oxy << " * " << co << " = " << co * oxy << endl;
	return;
}
	
