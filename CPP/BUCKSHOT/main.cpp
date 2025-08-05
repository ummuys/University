#include "game.h"

int main() {

	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	srand(time(NULL));
	
	Game Buckshoot;
	Players Diller("Diller", 3);
	Gamer Gamer("", 3);
	Gun shootgun;

	string name;
	cout << "Назови свое имя. . . \n\n>>";
	cin >> name;
	Gamer.set_name(name);
	system("cls");

	Gamer.set_c_beer(1);
	Gamer.set_c_loupe(1);
	shootgun.set_magazine(8);
	Buckshoot.start_game();
	Buckshoot.rules();

	while (true) {


		Buckshoot.begin_player_step(Gamer);
		Buckshoot.show_hp_players(Gamer, Diller);
		Buckshoot.show_bullets(shootgun);
		Gamer.make_choise(&Diller, &shootgun);
		Buckshoot.end_player_step(Gamer);


		Buckshoot.check_the_winner(Gamer, Diller, shootgun);


		Buckshoot.begin_player_step(Diller);
		Buckshoot.show_hp_players(Gamer, Diller);
		Buckshoot.show_bullets(shootgun);
		Diller.make_choise(&Gamer, &shootgun);
		Buckshoot.end_player_step(Diller);

		Buckshoot.check_the_winner(Gamer, Diller, shootgun);

	}
}