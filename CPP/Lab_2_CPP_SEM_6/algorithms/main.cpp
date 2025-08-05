#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <limits>
#include "DFS.hpp"
#include "BFS.hpp"
#include "kosaraju.hpp"

//COLORS//
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
//COLORS//

typedef std::vector<std::vector<int>> vvi;
#pragma warning(disable:4996)

int bad_ans(){
    system("clear"); 
    std::cout<< RED << "Incorrect ans . . ." << RESET << std::endl;
    return -1;
}

vvi read_txt_matrix(std::string path){
    std::fstream read(path);
    vvi vect;
    std::string line;
    std::size_t i = 0;
    while(std::getline(read, line)){
        std::vector<int> tmp_vect;
        for(int k = 0; k < line.size(); k++){
            if(isdigit(line[k])){
                tmp_vect.push_back(line[k] - '0');
            }
        }
        if(tmp_vect.size()){
            vect.push_back(tmp_vect);
            i++;
        }
    }
    read.close();
    return vect;
}


void view_list(int mode){
    int i = 1;
    std::cout  << "(" << i << ")" << " DFS " << "(" << i << ")" << std::endl;
    i++;
    std::cout  << "(" << i << ")" << " BFS " << "(" << i << ")" << std::endl;
    i++;
    if(mode == 2) {
        std::cout  << "(" << i << ")" << " Kosaraji " << "(" << i << ")" << std::endl;
    }
}
int choose_search(char mode) {
	system("clear");
    int ans = -1;
    bool incorrect_flag = false;
    while(ans == -1){
        if(incorrect_flag){
            std::cout<< RED << "Incorrect ans . . . Try again" << RESET << std::endl;
        }
        view_list(mode);
        std::cout << std::endl << std::endl << ">>";
        if(std::cin.peek() != '\n') {
            std::cin >> ans;
        }
        if(std::cin.fail() || (ans < 1 || ans > 3 )) {
            incorrect_flag = true;
            system("clear");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ans = -1;
        }
    }
    return ans;
}
void DFS_alg(vvi vect){
    std::vector<int> res;
    std::cout << GREEN << "Result of DFS:" << RESET << std::endl;
    res = DFS(vect).first;
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if(i + 1 < res.size()){
            std::cout << "->";
        }
    }
}
void BFS_alg(vvi vect){
    std::vector<int> res;
    std::cout << GREEN << "Result of BFS:" << RESET << std::endl;
    res = BFS(vect);
    for(int i = 0; i < res.size(); i++){
        std::cout << res[i];
        if(i + 1 < res.size()){
            std::cout << "->";
        }
    }
}
void SSC_alg(vvi vect, std::string path){
    vvi res_ssc = get_ssc(vect);
    std::ofstream out;
    out.open(path);
    for(int i = 0; i < res_ssc.size(); i++){
        for(int j = 0; j < res_ssc[i].size(); j++){
            out << res_ssc[i][j];
            if(j + 1 < res_ssc[i].size())out << " ";
        }
        out << std::endl;
    }
    out.close();
}


int main(int argc, char *argv[]) {

    std::ifstream file(argv[2]);
    char mode;
    file.get(mode);
    file.close();

	int choise = choose_search(mode - 48);
    vvi vect = read_txt_matrix(argv[1]);
    switch (choise)
    {
    case 1:
        DFS_alg(vect);
        break;
    
    case 2:
        BFS_alg(vect);
        break;
    case 3:
        SSC_alg(vect, argv[3]);
        break;
    }

    
    std::cout << std::endl << std::endl;
    std::cout << "To end the programm, close the window with graph . . .";
	return 0;
}