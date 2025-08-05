#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef struct Item {
	string name;
	int weight;
	int cost;
	Item() : name(""), cost(0), weight(0) {}
	Item(string name, int weight, int cost) : name(name), weight(weight), cost(cost) {}
}Item;

typedef struct Item_extended {
	string name;
	int weight;
	int cost;
	int amount;
	Item_extended() : name(""), cost(0), weight(0), amount(0) {}
	Item_extended(string name, int weight, int cost, int amount) : name(name), weight(weight), cost(cost), amount(amount){}
}Item_extended;

Item knapsack_problem(vector<Item> Items, int max_weight);
Item knapsack_problem_extended(vector<Item> Items, int max_weight);