#include "lib.h"

class Gun {
private:
	vector<unsigned int> magazine;
	int real_ammo;
	int blank_ammo;
public:

	void set_magazine(int count_ammo);
	int check_current_ammo();
	void reload();
	int get_real_ammo();
	int get_blank_ammo();
};


class Players {
protected:

	string name;
	unsigned int health_points;
	bool end_move;

public:

	Players(string nm, unsigned int hp) : name(nm), health_points(hp) {}

	void set_hp(int c_hp);
	int get_hp();
	string get_name();
	void set_name(string nm);

	void take_damage(int damage);
	bool shoot_yourself(Gun* gun);
	void shoot_opponent(Players* player_2, Gun* gun);
	bool shoot(Players* player_2, Gun* gun, int ans);
	virtual void make_choise(Players* player_2, Gun* gun);

	void wrong_shoot_yourself();
	void right_shoot_yourself();
	void wrong_shoot_opponent();
	void right_shoot_opponent();

};


class Gamer : public Players {
protected:
	unsigned int c_beer;
	unsigned int c_loupe;
public:


	Gamer(string nm, unsigned int hp) : Players(nm, hp), c_beer(0), c_loupe(0) {}

	void set_c_beer(int count);
	void set_c_loupe(int count);


	int get_c_beer();
	int get_c_loupe();

	void use_beer(Gun* gun);
	void use_loupe(Gun* gun);
	void make_choise(Players* player_2, Gun* gun) override;
	void choose_to_shoot(Players* player_2, Gun* gun);
	void choose_items(Gun* gun);

};


class Game{
public:

	void start_game();
	void rules();
	void show_hp_players(Players player_1, Players player_2);
	void show_bullets(Gun gun);
	void check_the_winner(Players player_1, Players player_2, Gun gun);

	void begin_player_step(Players player);
	void end_player_step(Players player);


};
