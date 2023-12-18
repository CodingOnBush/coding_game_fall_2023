#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Score points by scanning valuable fish faster than your opponent.
 **/

struct Creature {
	int id;
	int color;
	int type;
	int posx;
	int posy;
	int speedx;
	int speedy;
} creature;

struct Drone {
	int 		id;
	int 		posx;
	int 		posy;
	int 		emergency;
	int 		battery;
	int 		score;
	int			scans;
	Creature	pokedex; 
} me, op;

int main()
{
	int creature_count;// the number of creatures you can observe
	int my_drone_count;// the number of drones you control

	std::vector<Creature> creatures;
	cin >> creature_count; cin.ignore();
	creatures.resize(creature_count);

	for (int i = 0; i < creature_count; i++)
		cin >> creatures[i].id >> creatures[i].color >> creatures[i].type; cin.ignore();

	// game loop
	while (1) {
		cin >> me.score; cin.ignore();
		cin >> op.score; cin.ignore();
		cin >> me.scans; cin.ignore();

		for (int i = 0; i < me.scans; i++)
			cin >> me.pokedex.id; cin.ignore();

		cin >> op.scans; cin.ignore();
		for (int i = 0; i < op.scans; i++)
			cin >> op.pokedex.id; cin.ignore();

		
		cin >> my_drone_count; cin.ignore();
		for (int i = 0; i < my_drone_count; i++) {
			int drone_id;
			int drone_x;
			int drone_y;
			int emergency;
			int battery;
			cin >> drone_id >> drone_x >> drone_y >> emergency >> battery; cin.ignore();
		}
		int foe_drone_count;
		cin >> foe_drone_count; cin.ignore();
		for (int i = 0; i < foe_drone_count; i++) {
			int drone_id;
			int drone_x;
			int drone_y;
			int emergency;
			int battery;
			cin >> drone_id >> drone_x >> drone_y >> emergency >> battery; cin.ignore();
		}
		int drone_scan_count;
		cin >> drone_scan_count; cin.ignore();
		for (int i = 0; i < drone_scan_count; i++) {
			int drone_id;
			int creature_id;
			cin >> drone_id >> creature_id; cin.ignore();
		}
		int visible_creature_count;
		cin >> visible_creature_count; cin.ignore();
		for (int i = 0; i < visible_creature_count; i++) {
			int creature_id;
			int creature_x;
			int creature_y;
			int creature_vx;
			int creature_vy;
			cin >> creature_id >> creature_x >> creature_y >> creature_vx >> creature_vy; cin.ignore();
		}
		int radar_blip_count;
		cin >> radar_blip_count; cin.ignore();
		for (int i = 0; i < radar_blip_count; i++) {
			int drone_id;
			int creature_id;
			string radar;
			cin >> drone_id >> creature_id >> radar; cin.ignore();
		}
		for (int i = 0; i < my_drone_count; i++) {

			// Write an action using cout. DON'T FORGET THE "<< endl"
			// To debug: cerr << "Debug messages..." << endl;

			// cout << "MOVE 0 0" << endl; // MOVE <x> <y> <light (1|0)> | WAIT <light (1|0)>
			cout << "MOVE " << "1000" << " " << "4000" << " 1" << endl;
		}
	}
}
