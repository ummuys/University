#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <limits>
#include "graph.hpp"

//COLORS//
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
//COLORS//


void show_vect(std::vector<vvi> curr_grapgs){
    std::cout<<std::endl << std::endl;
    for(int c = 0; c < curr_grapgs.size(); c++){
        std::cout<< "Graph №" << c + 1 << std::endl;
        std::cout << "------------------------------" << std::endl;
        for(int i = 0; i < curr_grapgs[c].size(); i++){
            std::cout << "Edge №" << i << " -> " << "{";
            for(int j = 0; j < curr_grapgs[c][i].size(); j++){
                if(curr_grapgs[c][i][j]){
                    std::cout << j;
                    if(j + 1 != curr_grapgs[c][i].size())std::cout<<", ";
                }
            }
            std::cout << "}, ";
            std::cout<<std::endl;
        }
        std::cout << "------------------------------" << std::endl;
        std::cout<<std::endl;
    }
}

void show_matrix(vvi elem, int ans, std::string path, int mode_graph){
    std::ofstream out1;
    out1.open(path);
    
    for(int i = 0; i < elem.size(); i++){
        std::cout << "{";
        for(int j = 0; j < elem[i].size(); j++){
            out1 << elem[i][j] << " ";
            std::cout << elem[i][j];
            if(j + 1 != elem[i].size())std::cout<<", ";
        }
        std::cout << "}, ";
        out1 << std::endl;
        std::cout<<std::endl;
    }
    out1.close();
}

void greetings(std::string graph_path, std::string mode_path){
    int mode = -1;
    bool incorrect_flag = false;
    while(mode == -1){
        if(incorrect_flag){
            std::cout<< RED << "Incorrect ans . . . Try again" << RESET << std::endl;
        }
        std::cout << "Do you wanna work with undirected(1) or directed(2) graph?\n\n>>";
        if(std::cin.peek() != '\n') {
            std::cin >> mode;
        }
        if(std::cin.fail() || (mode < 1 || mode > 2 )) {
            incorrect_flag = true;
            system("clear");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            mode = -1;
        }
    }

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    //------------------------//
    std::ofstream out2;
    out2.open(mode_path);
    out2 << mode;
    out2.close();
    //------------------------//

    int ans = -1;
    std::cout << std::endl;
    incorrect_flag = false;
    std::string choosen_mode = (mode == 1? "undirected" : "directed");
    std::vector<vvi>& curr_grapgs = (mode == 1?all_nonD_graphs:all_D_graphs);
    while(ans == -1){
        if(incorrect_flag){
            std::cout<< RED << "Incorrect ans . . . Try again" << RESET << std::endl;
            std::cout<< "Choosen mode: " << choosen_mode << std::endl << std::endl;
        }
        std::cout << "Choose a number of adjacency matrix (1-" << (curr_grapgs.size()) <<"):";
        show_vect(curr_grapgs);
        std::cout << ">>";

        if(std::cin.peek() != '\n') {
            std::cin >> ans;
        }
        if(std::cin.fail() || (ans < 1 || ans > curr_grapgs.size())) {
            incorrect_flag = true;
            system("clear");
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            ans = -1;
            }
    }
    system("clear");
    std::cout<< GREEN << "Choosen mode: " << RESET << choosen_mode << std::endl;
    std::cout << GREEN << "Choosen matrix:" << RESET << std::endl;
    show_matrix(curr_grapgs[ans - 1], ans, graph_path, mode);

    std::cout << std::endl << "Enter any character to continue. . . .";
    fgetc(stdin);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(int argc, char *argv[]){
    system("clear"); 
    greetings(argv[1], argv[2]);
    return 0;
}
