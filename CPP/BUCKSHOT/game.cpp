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
	cout << "--------- �������� -----------";
	cout << "\n���������: ���� ��������� ������. �� �������� ���� ������� ��������\n";
	cout << "----------------------" << endl << endl;
}
void Players::right_shoot_yourself() {
	cout << "--------- �������� -----------";
	cout << "\n���������: ���� ��������� ��������. �������� ��� ���� ���\n";
	cout << "----------------------" << endl << endl;
}
void Players::wrong_shoot_opponent() {
	cout << "--------- �������� -----------";
	cout << "\n���������: ���� ��������� ��������. ��������� �� ������� �����\n";
	cout << "----------------------" << endl << endl;
}
void Players::right_shoot_opponent() {
	cout << "--------- �������� -----------";
	cout << "\n���������: ���� ��������� ������. �� ������� ���������� ���� ������� �����\n";
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
	cout << "----------- ���� -----------" << endl;
	if (get_c_beer()){
		if (gun->check_current_ammo()) {
			cout << "������� ������ ������" << endl;
		}
		else {
			cout << "������� �������� ������" << endl;
		}
		c_beer--;
		gun->reload();
	}
	else {
		cout << "���� �����������" << endl;
	}
	cout << "----------------------" << endl;
}

void Gamer::use_loupe(Gun* gun) {
	cout << "---------- ���� ----------" << endl;
	if (get_c_loupe()) {
		if (gun->check_current_ammo()) {
			cout << "���������: c�������� ������ ������" << endl;
		}
		else {
			cout << "���������: c�������� ������ ��������" << endl;
		}
		c_loupe--;
	}
	else {
		cout << "���� �����������" << endl;
	}
	cout << "----------------------" << endl;
}


void Gamer::choose_items(Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		cout << "1)���-�� ����: " << get_c_beer() << endl;
		cout << "2)���-�� ���: " << get_c_loupe() << endl;
		cout << "3)��������� " << endl;

		cout << endl << endl;

		cout << "������������: ";
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
		cout << "���������� � ���� - 0, ���������� � ���������� - 1\n\n>>";
		int ans;
		cin >> ans;
		end_step = shoot(player_2, gun, ans);
	}
}

void Gamer::make_choise(Players* player_2, Gun* gun) {
	bool end_step = false;
	while (!end_step) {
		cout << "�������� ��������:\n\n1)������������ ��������\n2)����������\n\n>>";
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
	cout << endl << "########################### ���� ����������! ###########################" << endl << endl;
}

void Game::rules() {
	cout << "������� ����:\n1)��������� ���, � ���� ������� ���������� ������� ��������. ���� ������ ������� �������������, �� �����" << endl;
	cout << "2)���� ����� ������������ � ���� �������� ��������, �� ����� ������ ��� ��� ���. ����������� �� ������� � ���� �� �������." << endl << endl;
}
void Game::check_the_winner(Players player_1, Players player_2, Gun gun) {
	if (!(player_1.get_hp())) {
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		cout << "������� " << player_2.get_name() << endl;
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		exit(0);
	}
	else if (!(player_2.get_hp())) {
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		cout << "������� " << player_1.get_name() << endl;
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		exit(0);
	}
	else if (gun.get_real_ammo() == 0) {
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		cout << "�����" << endl;
		cout << endl << "########################### ��������� ���� ###########################" << endl << endl;
		exit(0);
	}
}
void Game::begin_player_step(Players player) {
	cout << "########################### ������ ���� " << player.get_name() << " ###########################" << endl << endl;
}
void Game::end_player_step(Players player) {
	cout << "\n########################### ����� ���� " << player.get_name() << " ###########################" << endl;
	Sleep(3000);
	system("cls");
}

void Game::show_hp_players(Players player_1, Players player_2) {
	cout << "|| �������� ||\n";
	cout << "----------------------" << endl;
	cout << player_1.get_name() << " - " << player_1.get_hp() << " ��������" << endl;
	cout << "----------------------" << endl;
	cout << player_2.get_name() << " - " << player_2.get_hp() << " ��������" << endl;
	cout << "----------------------" << endl;
	cout << endl;
}


void Game::show_bullets(Gun gun) {
	cout << "|| ������� ||\n";
	cout << "----------------------" << endl;
	cout << gun.get_real_ammo() << " - " << " ������" << endl;
	cout << "----------------------" << endl;
	cout << gun.get_blank_ammo() << " - " << " ������" << endl;
	cout << "----------------------" << endl;
	cout << endl;
}

//################### GAME ###################//