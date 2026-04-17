#include <iostream> // Library for input/output
#include <string> // Librart for string
#include <vector> // Library for vector
#include <algorithm> // A library for searching for specific elements in an vector
#include <cctype> // Library for converting lowercase letters to uppercase
#include <Windows.h> // Library for function sleep

// Vector with cities
std::vector<std::string> cities{ "Agadir", "Abidjan", "Amman", "Anshan", "Austin" ,"Athens", "Astana", "Ankara", "Alexandria", "Almaty", "Adana", "Abu-Dhabi", "Moscow", "Madrid", "Minsk", "Montreal", "Munich", "Merida", "Matsudo", "Wellington", "Warsaw", "Washington", "Wakayama", "Windsor", "Wuhan", "Chicago", "Changchun", "Chengdu", "Chongqing", "Changsha", "Osaka", "Ordos", "Omsk", "Ottawa", "Orenburg", "Oklahoma-City", "Omaha", "Oakland", "Orel", "Orlando", "Ostrava", "Otsu", "Okanagan", "Oshawa", "Oxnard", "Oxford", "Ontario", "Oakville", "Osan", "Taipei-City", "Toulouse", "Tbilisi", "Tabriz", "Edinburgh", "Exeter", "Enfield-Town", "Epsom", "Ubud", "Udaipur", "Ulaanbaatar", "Utrecht", "Urumchi", "Beijing", "Bangkok", "Boston", "Berlin", "Busan", "Budapest", "Tehran", "Toronto", "Tashkent", "Tyumen", "Tomsk", "Amsterdam", "Barcelona", "Cair", "Dubai", "Dublin", "Frankfurt", "Geneva", "Guangzhou", "Guankou", "Giza", "Guadalajara", "Gwalior", "Glasgow", "Gold-Coast", "Hanoi", "Helsinki", "Hong-Kong", "Hiroshima", "Halifax", "Istanbul", "Izmir", "Indianapolis", "Izhevsk", "Irkutsk", "Iwaki", "Ichihara", "Jakarta", "Kabul", "Kiev", "Kazan", "Krasnoyarsk", "Konya", "Krakow", "Krasnodar", "Lisbon", "London", "Madrid", "Mexico-city", "New-York","New-Delhi", "Nagoya", "New-Kingston", "Nanjing", "Oslo", "Prague", "Pittsburg", "Riga", "Rome", "Raleigh", "Riverside", "Reno", "Ratlam", "Rybinsk", "Saint-Petersburg", "San-Francisco", "Singapore", "Stockholm", "Sydney", "Tokyo", "Toronto", "Delhi", "Dalian", "Daegu", "Dallas", "Dnipro", "Donetsk", "Dublin", "Denver", "Detroit", "Paris", "Vienna", "Venice", "Yokohama", "Yono", "Yekaterinburg", "Yamagata", "York", "Zagreb" };

// Required variables
int menu_choice; // Choice actions
char StartNewGame; // Player choice of start game

// Function for clear console. CC - ClearConsole
void CC() {
	system("cls");
}
void EndGame() {
	Sleep(100);
}
// Function for end game
int End_Programm() {
	std::cout << "WIsh good day for you! :)";

	return 0;
}

// Function for get last symbol. PM - PlayerMove
void PMove_CMove(std::vector<std::string>& cities) {
	std::string PlayerMove;
	char TargetLetter;
PM:
	std::cout << "\n Player Move: ";
	std::cin >> PlayerMove;

	// Checking user move
	if (!PlayerMove.empty()) {
		TargetLetter = PlayerMove.back();
		TargetLetter = toupper(TargetLetter);
	}
	else if (PlayerMove.empty()) {
		std::cout << "Player Move cant be empty!";
		Sleep(5000);
		goto PM;
	}

	// Deleting a city used by a player
	auto Plcity = find(cities.begin(), cities.end(), PlayerMove);
	cities.erase(Plcity);

	// Search for a city by the desired letter
	auto Ccity = find_if(cities.begin(), cities.end(), [TargetLetter](const std::string& Ccity) {
		return !Ccity.empty() && Ccity[0] == TargetLetter;
		});

	// The system of withdrawal and removal of cities
	std::cout << "\nComputer Move: " << *Ccity;
	cities.erase(Ccity);
}

void menu() {
	int numb = 0;
	char MenuChoiceBack;

st:
	std::cout << std::endl << "  ______________________";
	std::cout << std::endl << "  |Actions:            |";

	// Possible actions
	std::cout << std::endl << "  |1. Start Game       |";
	std::cout << std::endl << "  |2. View Cities      |";
	std::cout << std::endl << "  |3. Exit             |";
	std::cout << std::endl << "  ----------------------";

	// Request for user input
GetData:
	std::cout << std::endl << "Your Choice (1-3):";
	std::cin >> menu_choice;

	// Checking the user's choice
	if (menu_choice == 1) CC();
	if (menu_choice == 2) {
		for (auto cities2 = cities.begin(); cities2 != cities.end(); cities2++) {
			numb++;
			std::cout << std::endl << numb << "." << *cities2;
		}
		std::cout << std::endl << "Back to choice action (Y or N):";
		std::cin >> MenuChoiceBack;
		if (MenuChoiceBack == 'Y') {
			CC();
			goto st;
		}
		else {
			std::cout << std::endl << "Okay";
		}
	}
	if (menu_choice == 3) End_Programm;
	else if (menu_choice != 1 && menu_choice != 2 && menu_choice != 3) { 
		CC();
		goto GetData;
	}
}

int main() {
	int counter, GTS, GTD = 0;
	std::string choice;

start:

	// Settings
	menu();
	if (menu_choice == 3) goto ENDGAME;

	// Code start Game
	for (counter = 0; counter <= 100; counter++ & counter--) {
		PMove_CMove(cities);

		if (cities.empty()) {
			std::cout << "\n All cities were involved, Game Over!";
		}
	}
ENDGAME:
	End_Programm();

	return 0;
}
