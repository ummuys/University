#include "knapsack_problem.hpp"

Item knapsack_problem(vector<Item> Items, int max_weight) {
	//create backpack
	int c_items = Items.size();
	Item** backpack = new Item*[c_items];
	for (int i = 0; i < c_items; i++) {
		backpack[i] = new Item[max_weight];
	}

	for (int itm = 0; itm < c_items; itm++) {
		for (int cur_w = 0; cur_w < max_weight; cur_w++) {
			int remnant = cur_w - Items[itm].weight + 1;
			if (itm == 0 && remnant < 0)continue;
			if (itm == 0) {
				backpack[itm][cur_w] = Items[itm];
				continue;
			}
			if (remnant < 0) {
				backpack[itm][cur_w] = backpack[itm - 1][cur_w];
			}
			else if (remnant == 0) {
				backpack[itm][cur_w] = backpack[itm - 1][cur_w].cost > Items[itm].cost ? backpack[itm - 1][cur_w] : Items[itm];
			}
			else {
				if (backpack[itm - 1][cur_w].cost > Items[itm].cost + backpack[itm - 1][remnant - 1].cost) {
					backpack[itm][cur_w] = backpack[itm - 1][cur_w];
				}
				else {
					backpack[itm][cur_w].name = Items[itm].name + ", " + backpack[itm - 1][remnant - 1].name;
					backpack[itm][cur_w].cost = Items[itm].cost + backpack[itm - 1][remnant - 1].cost;
					backpack[itm][cur_w].weight = cur_w + 1;
				}
			}
		}
	}

	Item answer = backpack[c_items - 1][max_weight - 1];
	for (int i = 0; i < c_items; i++) {
		delete[] backpack[i];
	}
	delete[] backpack;
	return answer;
}

Item knapsack_problem_extended(vector<Item> Items, int max_weight) {
	int c_items = Items.size();
	Item** backpack = new Item * [c_items];
	for (int i = 0; i < c_items; i++) {
		backpack[i] = new Item[max_weight];
	}
	for (int itm = 0; itm < c_items; itm++) {
		for (int cur_w = 0; cur_w < max_weight; cur_w++) {
			int remnant = cur_w - Items[itm].weight + 1;
			if (itm == 0 && remnant < 0)continue;
			if (itm == 0) {
				if (remnant == Items[itm].weight) {
					backpack[itm][cur_w].name = Items[itm].name + ", " + backpack[itm][remnant - 1].name;
					backpack[itm][cur_w].cost = Items[itm].cost + backpack[itm][remnant - 1].cost;
					backpack[itm][cur_w].weight = Items[itm].weight + backpack[itm][remnant - 1].weight;
					continue;
				}
				else {
					backpack[itm][cur_w] = Items[itm];
					continue;
				}
			}
			if (remnant < 0) {
				backpack[itm][cur_w] = backpack[itm - 1][cur_w];
			}
			else if (remnant == 0) {
				backpack[itm][cur_w] = backpack[itm - 1][cur_w].cost > Items[itm].cost ? backpack[itm - 1][cur_w] : Items[itm];
			}
			else {
					int cost1 = backpack[itm - 1][cur_w].cost;
					int cost2 = Items[itm].cost + backpack[itm - 1][remnant - 1].cost;
					int cost3 = Items[itm].cost + backpack[itm][remnant - 1].cost;
					int answer = max(max(cost1, cost2), cost3);
					if (answer == cost1) {
						backpack[itm][cur_w] = backpack[itm - 1][cur_w];
					}
					else if (answer == cost2) {
						backpack[itm][cur_w].name = Items[itm].name + ", " + backpack[itm - 1][remnant - 1].name;
						backpack[itm][cur_w].cost = Items[itm].cost + backpack[itm - 1][remnant - 1].cost;
						backpack[itm][cur_w].weight = cur_w + 1;
					}
					else if (answer == cost3){
						backpack[itm][cur_w].name = Items[itm].name + ", " + backpack[itm][remnant - 1].name;
						backpack[itm][cur_w].cost = Items[itm].cost + backpack[itm][remnant - 1].cost;
						backpack[itm][cur_w].weight = cur_w + 1;
					}
				}
			}
	}
	Item answer = backpack[c_items - 1][max_weight - 1];
	for (int i = 0; i < c_items; i++) {
		delete[] backpack[i];
	}
	delete[] backpack;
	return answer;
}