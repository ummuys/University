#include "game.h"

//################### SHOOTGUN ###################//

void Gun::set_magazine(int count_ammo) {
	srand(time(NULL));
	for (int i = 0; i < count_ammo; i++) {
		magazine.push_back(rand() % 2);
		if (magazine.back()) {
			real_ammo++;
		}
		else {
			blank_ammo++;
		}
	}
}

int Gun::check_current_ammo() {
	return magazine.back();
}

void Gun::reload() {
	if (magazine.back()) {
		real_ammo--;
	}
	else {
		blank_ammo--;
	}
	magazine.pop_back();
}

int Gun::get_real_ammo() {
	return real_ammo;
}

int Gun::get_blank_ammo() {
	return blank_ammo;
}
//################### SHOOTGUN ###################//



//################### PLAYERS ###################//

void Players::set_hp(int c_hp) {
	health_points = c_hp;
}

int Players::get_hp() {
	return health_points;
}

void Players::take_damage(int damage) {
	health_points -= damage;
}


string Players::get_name() {
	return name;
}

void Players::set_name(string nm) {
	name = nm;
}




bool Players::shoot_yourself(Gun * gun) {
	if (gun -> check_current_ammo()) {
		wrong_shoot_yourself();
		health_points--;
		gun -> reload();
		return true;
	}
	else {
		right_shoot_yourself();
		gun -> reload();
		return false;
	}
}


void Players::shoot_opponent(Players * player_2, Gun * gun){
	if (gun -> check_current_ammo()) {
		player_2->take_damage(1);
		right_shoot_opponent();
		gun -> reload();
	}
	else {
		wrong_shoot_opponent();
		gun -> reload();
	}
}

bool Players::shoot(Players* player_2, Gun* gun, int ans) {
	switch (ans) {
	case 0: {
		return shoot_yourself(gun);
	}
	case 1: {
		shoot_opponent(player_2, gun);
		return true;
	}
	}
}


void Players::make_choise(Players* player_2, Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		int ans = rand() % 2;
		end_step = shoot(player_2, gun, ans);
		Sleep(1500);
	}
}


void Players::wrong_shoot_yourself() {
	cout << "--------- Стрельба -----------";
	cout << "\nРезультат: пуля оказалась боевой. Вы потеряли одну единицу здоровья\n";
	cout << "----------------------" << endl << endl;
}
void Players::right_shoot_yourself() {
	cout << "--------- Стрельба -----------";
	cout << "\nРезультат: пуля оказалась холостой. Сделайте еще один ход\n";
	cout << "----------------------" << endl << endl;
}
void Players::wrong_shoot_opponent() {
	cout << "--------- Стрельба -----------";
	cout << "\nРезультат: пуля оказалась холостой. Противник не получил урона\n";
	cout << "----------------------" << endl << endl;
}
void Players::right_shoot_opponent() {
	cout << "--------- Стрельба -----------";
	cout << "\nРезультат: пуля оказалась боевой. Вы нанесли противнику одну единицу урона\n";
	cout << "----------------------" << endl << endl;
}



//################### PLAYERS ###################//



//################### GAMER ###################//


void Gamer::set_c_beer(int count) {
	c_beer = count;
}

void Gamer::set_c_loupe(int count) {
	c_loupe = count;
}


int Gamer::get_c_beer() {
	return c_beer;
}

int Gamer::get_c_loupe() {
	return c_loupe;
}



void Gamer::use_beer(Gun* gun) {
	cout << "----------- Пиво -----------" << endl;
	if (get_c_beer()){
		if (gun->check_current_ammo()) {
			cout << "Вылетел боевой патрон" << endl;
		}
		else {
			cout << "Вылетел холостой патрон" << endl;
		}
		c_beer--;
		gun->reload();
	}
	else {
		cout << "Пиво закончилось" << endl;
	}
	cout << "----------------------" << endl;
}

void Gamer::use_loupe(Gun* gun) {
	cout << "---------- Лупа ----------" << endl;
	if (get_c_loupe()) {
		if (gun->check_current_ammo()) {
			cout << "Результат: cледующий патрон боевой" << endl;
		}
		else {
			cout << "Результат: cледующий патрон холостой" << endl;
		}
		c_loupe--;
	}
	else {
		cout << "Лупы закончились" << endl;
	}
	cout << "----------------------" << endl;
}


void Gamer::choose_items(Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		cout << "1)Кол-во пива: " << get_c_beer() << endl;
		cout << "2)Кол-во луп: " << get_c_loupe() << endl;
		cout << "3)Вернуться " << endl;

		cout << endl << endl;

		cout << "Использовать: ";
		int ans;
		cin >> ans;
		cout << endl;

		switch (ans) {
		case 1: {
			use_beer(gun);
			cout << endl;
			end_step = false;
			break;
		}
		case 2: {
			use_loupe(gun);
			cout << endl;
			end_step = false;
			break;
		}

		case 3: {
			end_step = true;
			break;
		}

		}
	}

}

void Gamer::choose_to_shoot(Players* player_2, Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		cout << "Выстрелить в себя - 0, выстрелить в противника - 1\n\n>>";
		int ans;
		cin >> ans;
		end_step = shoot(player_2, gun, ans);
	}
}

void Gamer::make_choise(Players* player_2, Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		cout << "Выберите действие:\n\n1)Использовать предметы\n2)Выстрелить\n\n>>";
		int ans;
		cin >> ans;
		cout << endl;
		switch (ans) {
		case 1: {
			choose_items(gun);
			break;
		}

		case 2: {
			choose_to_shoot(player_2, gun);
			end_step = true;
			break;
		}
		}
	}
}


//################### GAMER ###################//

//################### GAME ###################//
void Game::start_game() {
	cout << endl << "########################### Игра начинается! ###########################" << endl << endl;
}

void Game::rules() {
	cout << "Правила игры:\n1)Побеждает тот, у кого первого закончатся единицы здоровья. Если боевые патроны заканчиваются, то ничья" << endl;
	cout << "2)Если игрок выстреливает в себя холостым патроном, то игрок делает ход еще раз. Ограничений на выстрел в себя не имеется." << endl << endl;
}
void Game::check_the_winner(Players player_1, Players player_2, Gun gun) {
	if (!(player_1.get_hp())) {
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		cout << "Победил " << player_2.get_name() << endl;
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		exit(0);
	}
	else if (!(player_2.get_hp())) {
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		cout << "Победил " << player_1.get_name() << endl;
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		exit(0);
	}
	else if (gun.get_real_ammo() == 0) {
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		cout << "Ничья" << endl;
		cout << endl << "########################### Результат игры ###########################" << endl << endl;
		exit(0);
	}
}
void Game::begin_player_step(Players player) {
	cout << "########################### Начало хода " << player.get_name() << " ###########################" << endl << endl;
}
void Game::end_player_step(Players player) {
	cout << "\n########################### Конец хода " << player.get_name() << " ###########################" << endl;
	Sleep(3000);
	system("cls");
}

void Game::show_hp_players(Players player_1, Players player_2) {
	cout << "|| Здоровье ||\n";
	cout << "----------------------" << endl;
	cout << player_1.get_name() << " - " << player_1.get_hp() << " здоровья" << endl;
	cout << "----------------------" << endl;
	cout << player_2.get_name() << " - " << player_2.get_hp() << " здоровья" << endl;
	cout << "----------------------" << endl;
	cout << endl;
}


void Game::show_bullets(Gun gun) {
	cout << "|| Патроны ||\n";
	cout << "----------------------" << endl;
	cout << gun.get_real_ammo() << " - " << " боевых" << endl;
	cout << "----------------------" << endl;
	cout << gun.get_blank_ammo() << " - " << " пустых" << endl;
	cout << "----------------------" << endl;
	cout << endl;
}

//################### GAME ###################//