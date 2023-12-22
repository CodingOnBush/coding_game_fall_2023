#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

// Global variables
const int	step = 600;

// Classes
class Position
{
public:
	int		x;
	int		y;
};

class Creature
{
public:
	int			id;
	int			color;
	int			type;
	Position	pos;
	int			vx;
	int			vy;
};

class Drone
{
public:
	int					id;
	Position			pos;
	int					emergency;
	int					battery;
	map<int, Creature>	visible_creatures;
	map<int, Creature>	creature_scans;
	string				radar;
};

class Game
{
public:
	int creature_count;
	int my_score;
	int foe_score;
	int my_scan_count;
	int foe_scan_count;
	int my_drone_count;
	int foe_drone_count;
	int drone_scan_count;
	int visible_creature_count;
	int radar_blip_count;
};

// Functions
void	update_data(Game *game, map<int, Drone> *my_drones, map<int, Drone> *foe_drones, map<int, Creature> *creatures)
{
	cin >> (*game).my_score; cin.ignore();
	cin >> (*game).foe_score; cin.ignore();
	cin >> (*game).my_scan_count; cin.ignore();

	// collect data of my scans
	for (int i = 0; i < (*game).my_scan_count; i++) {
		int creature_id;
		cin >> creature_id; cin.ignore();
	}

	// collect data of foe scans
	cin >> (*game).foe_scan_count; cin.ignore();
	for (int i = 0; i < (*game).foe_scan_count; i++) {
		int creature_id;
		cin >> creature_id; cin.ignore();
	}
	
	// collect data of my drones
	cin >> (*game).my_drone_count; cin.ignore();
	for (int i = 0; i < (*game).my_drone_count; i++) {
		Drone drone;
		cin >> drone.id >> drone.pos.x >> drone.pos.y >> drone.emergency >> drone.battery; cin.ignore();
		(*my_drones)[drone.id] = drone;
	}

	// collect data of foe drones
	cin >> (*game).foe_drone_count; cin.ignore();
	for (int i = 0; i < (*game).foe_drone_count; i++) {
		Drone drone;
		cin >> drone.id >> drone.pos.x >> drone.pos.y >> drone.emergency >> drone.battery; cin.ignore();
		(*foe_drones)[drone.id] = drone;
	}
	
	// collect data of drone scans
	cin >> (*game).drone_scan_count; cin.ignore();
	for (int i = 0; i < (*game).drone_scan_count; i++) {
		int drone_id;
		int creature_id;
		cin >> drone_id >> creature_id; cin.ignore();
		(*my_drones)[drone_id].creature_scans[creature_id] = (*creatures)[creature_id];
	}
	
	// collect data of visible creatures
	cin >> (*game).visible_creature_count; cin.ignore();
	for (int i = 0; i < (*game).visible_creature_count; i++) {
		int creature_id;
		int creature_x;
		int creature_y;
		int creature_vx;
		int creature_vy;
		cin >> creature_id >> creature_x >> creature_y >> creature_vx >> creature_vy; cin.ignore();
		(*creatures)[creature_id].pos.x = creature_x;
		(*creatures)[creature_id].pos.y = creature_y;
		(*creatures)[creature_id].vx = creature_vx;
		(*creatures)[creature_id].vy = creature_vy;
	}
	
	// collect data of radar blips
	cin >> (*game).radar_blip_count; cin.ignore();
	for (int i = 0; i < (*game).radar_blip_count; i++) {
		int drone_id;
		int creature_id;
		string radar;
		cin >> drone_id >> creature_id >> radar; cin.ignore();
		(*my_drones)[drone_id].visible_creatures[creature_id] = (*creatures)[creature_id];
		(*my_drones)[drone_id].radar = radar;
	}
}

void	init_game(Game *game, map<int, Creature> *creatures)
{
	(*game).creature_count = 0;
	(*game).my_score = 0;
	(*game).foe_score = 0;
	(*game).my_scan_count = 0;
	(*game).foe_scan_count = 0;
	(*game).my_drone_count = 0;
	(*game).foe_drone_count = 0;
	(*game).drone_scan_count = 0;
	(*game).visible_creature_count = 0;
	(*game).radar_blip_count = 0;

	cin >> (*game).creature_count; cin.ignore();
	for (int i = 0; i < (*game).creature_count; i++) {
		Creature creature;
		cin >> creature.id >> creature.color >> creature.type; cin.ignore();
		(*creatures)[creature.id] = creature;
	}
}

void	wait(int light)
{
	cout << "WAIT " << light << endl;
}

void	move(int x, int y, int light)
{
	cout << "MOVE " << x << " " << y << " " << light << endl;
}

void	putstr(string str, string val)
{
	cerr << str << " : " << val << endl;
}

int main()
{
	Game game;
	map<int, Creature>	creatures;
	map<int, Drone>		my_drones;
	map<int, Drone>		foe_drones;
	
	init_game(&game, &creatures);
	while (1) {
		update_data(&game, &my_drones, &foe_drones, &creatures);
		
		for (int i = 0; i < game.my_drone_count; i++) {
			move(5000, 5000, 0);
			fprintf(stderr, "my_drones[i].radar : %s\n", my_drones[i].radar.c_str());
		}
	}
}