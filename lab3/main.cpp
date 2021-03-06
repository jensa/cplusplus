#include <vector>
#include <fstream>
#include "character/player.h"
#include "character/troll.h"
#include "character/lampmaker.h"
#include "character/necromancer.h"
#include "character/dragon.h"
#include "object/ring.h"
#include "environment/environment.h"
#include "object/bag.h"
#include "object/key.h"
#include "object/pointeritem.h"
#include "object/weapon.h"
#include "object/lamp.h"
#include "environment/darkroom.h"
#include "environment/lockedroom.h"


using namespace lab3;

std::vector<Environment *> initialize(Player& player);
std::string ascii(std::string);
std::string get_file_contents (std::ifstream&);
std::string welcome();

int main(){

	
	std::string name = welcome();
	Player* player = new Player(name, 20000);
	std::vector<Environment *> environments = initialize(*player);
	player->print_help();
	bool game_running = true;
	while (game_running){
		for (int i = 0; i < environments.size(); i++){
			Environment& env = *environments[i];
			std::vector<std::string> character_names = env.get_character_names();
			
			for (int i = 0; i < character_names.size(); i++){
				Character* character = env.get_character(character_names[i]);
				if (character != NULL ){
					if(character_names[i] == name) {
						game_running = character->action(env);
					} else{
						character->action(env);
					}
				} 
			}
		}
	}

	for (int i = 0; i < environments.size(); i++){
		delete environments[i];
	}
	std::cout << "Game ended." << std::endl;
}

std::vector<Environment *> initialize(Player& player){
	std::vector<Environment *> environments;

	Environment* A_D = new Environment("You see a giant pit. Is this some sort of grave?");
	Environment* B_B = new Environment("You're standing in a deserted garden. All you see are dead plants");
	Environment* B_C = new Environment("You're in the west guard tower.");
	Environment* B_D = new Environment("You're inside the ritual chamber. There's a suspicious door that seems to lead to certain death.");
	Environment* B_E = new Environment("You're in the west bedroom chamber. There's an unbelievable stench permeating the room");
	Environment* C_A = new Environment("You're basically at the end of the world. Just go back, please.");
	Environment* C_B = new Environment("" + ascii("castlefrontview.txt") + "You're facing a giant castle. Well, maybe not GIANT, but it's bigger than your home(hint: you don't have a home). The door seems open...");
	Environment* C_C = new Environment("You're just inside the castle gates. You feel... stereotypical");
	Environment* C_F = new Environment(""+ascii("dragon.txt")+"OH MY GOD THIS HUGE DRAGON WILL KILL YOU DEAD KILL IT KILL IT");
	Environment* C_E = new Darkroom("Oh god everything is so bright. There's a BIG GIANT LOOMING DOOR, among other things", "This is literally the darkest room you've ever seen. Better go back.", C_F);
	Environment* D_C = new Environment("You're standing the the east guard tower. Typical tower, you know.");
	Environment* D_E = new Environment("Wow. OK. This room sucks. just... just get out of here.");
	Environment* E_D = new Environment("Aaah, fresh air. Mingled with a stench of rotten flesh. There's a huge hedge of both of your sides.");
	Environment* D_D = new Lockedroom("This is the gardener's office, or what's left of it. There's a locked door here.", "This is the gardener's office, or what's left of it. The door to the gardens is unlocked.", E_D);
	Environment* F_C = new Environment("You're standing in the ruins of the old lampmaker's hut. You know, the kind of hut you have in a castle garden.");
	Environment* F_D = new Environment(""+ascii("tower.txt")+"You're in the castle gardens. Before you is a huge watchtower with a ladder.");
	Environment* F_E = new Environment("Don't castle type people ever get tired of all the flowers? There's flowers literally everywhere. Oh, and dead bodies.");
	Environment* F_F = new Environment("This is the secret part of the garden. You're feeling full of all kinds of secrets. How unexpected.");
	Environment* G_D = new Environment("" + ascii("castletopview.txt") + "WHOA! the view from here is amazing!");
	Environment* G_E = new Environment("This is the most boring part of the garden. Not even the trolls like this place.");

	(*B_B).set_neighbor("east", C_B);

	(*B_C).set_neighbor("east", C_C);
	(*B_C).set_neighbor("north", B_D);

	(*B_D).set_neighbor("south", B_C);
	(*B_D).set_neighbor("west", A_D);
	(*B_D).set_neighbor("north", B_E);

	(*B_E).set_neighbor("south", B_D);
	(*B_E).set_neighbor("east", C_E);

	(*C_A).set_neighbor("north", C_B);

	(*C_B).set_neighbor("west", B_B);
	(*C_B).set_neighbor("south", C_A);
	(*C_B).set_neighbor("north", C_C);

	(*C_C).set_neighbor("south", C_B);
	(*C_C).set_neighbor("west", B_C);
	(*C_C).set_neighbor("east", D_C);

	(*C_E).set_neighbor("west", B_E);
	(*C_E).set_neighbor("east", D_E);

	(*C_F).set_neighbor("east", C_E);

	(*D_C).set_neighbor("west", C_C);
	(*D_C).set_neighbor("north", D_D);

	(*D_D).set_neighbor("north", D_E);
	(*D_D).set_neighbor("south", D_C);

	(*D_E).set_neighbor("west", C_E);
	(*D_E).set_neighbor("south", D_D);

	(*E_D).set_neighbor("east", F_D);
	(*E_D).set_neighbor("west", D_D);

	(*F_C).set_neighbor("north", F_D);

	(*F_D).set_neighbor("west", E_D);
	(*F_D).set_neighbor("south", F_C);
	(*F_D).set_neighbor("up", G_D);
	(*F_D).set_neighbor("north", F_E);

	(*F_E).set_neighbor("north", F_F);
	(*F_E).set_neighbor("east", G_E);
	(*F_E).set_neighbor("south", F_D);

	(*F_F).set_neighbor("south", F_E);
	
	(*G_D).set_neighbor("down", F_D);

	(*G_E).set_neighbor("west", F_E);

	(*C_B).enter(player);
	Weapon * spear = new Weapon(7, 5, "spear", "a shiny spear");
	Weapon* troll_sword = new Weapon(15, 15, "trollsword", "a disgusting sword");
	Weapon* sword = new Weapon(12, 8, "sword", "a shiny sword");
	Weapon* axe = new Weapon(10, 7, "axe", "a shiny axe");
	
	Troll* troll1 = new Troll("Ardlef", 10, spear);
	Troll* troll2 = new Troll("Borkork", 10, axe);
	Troll* troll3 = new Troll("Crogg", 15, sword);
	Troll* troll4 = new Troll("GORGOG", 20, troll_sword);

	C_C->enter(*troll1);
	D_C->enter(*troll2);
	B_C->enter(*troll3);
	B_E->enter(*troll4);

	Weapon* dragon_claw = new Weapon(70, 3, "dragon claw", "Whoa, it's so light!");
	Dragon* dragon = new Dragon("Dragon", 100, dragon_claw);
	Pointeritem* pointer = new Pointeritem();
	dragon->pick_up(*pointer);
	C_F->enter(*dragon);

	Weapon* dagger = new Weapon(6, 5, "dagger", "a shitty dagger");
	Lampmaker* maker = new Lampmaker("Simon", 10, dagger);
	(*F_C).enter(*maker);

	Weapon* mace = new Weapon(30, 10, "necromace", "a freaky looking mace");
	Necromancer* necro = new Necromancer("Rogert", 40, mace);

	Key* key = new Key();
	necro->pick_up(*key);
	B_D->enter(*necro);

	Ring* ring = new Ring();
	B_E->drop(*ring);

	Bag* bag = new Bag();
	D_D->drop(*bag);

	Weapon* stone_sword = new Weapon(100, 15, "Dragonkiller", "This sword could probably kill a dragon");
	F_F->drop(*stone_sword);

	environments.push_back(A_D);
	environments.push_back(B_B);
	environments.push_back(B_C);
	environments.push_back(B_D);
	environments.push_back(B_E);
	environments.push_back(C_A);
	environments.push_back(C_B);
	environments.push_back(C_C);
	environments.push_back(C_E);
	environments.push_back(C_F);
	environments.push_back(D_C);
	environments.push_back(D_D);
	environments.push_back(D_E);
	environments.push_back(E_D);
	environments.push_back(F_C);
	environments.push_back(F_D);
	environments.push_back(F_E);
	environments.push_back(F_F);
	environments.push_back(G_D);
	environments.push_back(G_E);
	return environments;
}

std::string ascii(std::string filepath){
	std::ifstream reader (filepath);
    std::string contents =  get_file_contents (reader);
	reader.close ();
	return contents;
}

std::string get_file_contents (std::ifstream& file)
{
    std::string lines = "";

    if (file){
		while (file.good ()) {
			std::string tempLine;
			std::getline (file , tempLine);
			tempLine += "\n";
			lines += tempLine;
		}
		return lines;
    } else {
		return "";
    }
}

std::string welcome(){
	std::cout << ascii("intro.txt") << std::endl;
	std::cout << "Welcome to a not so exciting adventure! what is your name?" << std::endl;
	std::cout << ">";
	std::string name;
	std::cin >> name;
	std::cout << name << "! Our medieval castle has been defiled by traditional fantasy creatures! For whatever reason, you must go alone and extract vengeance, even though you only have your weak fists to help you. Now go!" << std::endl;
	std::cout << std::endl << std::endl;
	std::cout << "you are left alone in front of the huge, super cliche castle. Good luck!" << std::endl;
	return name;
}