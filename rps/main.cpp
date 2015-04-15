#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <unordered_map>

int main()
{
	bool playing = true;
	std::string userMoveStr, playAgain;
	int playerWins = 0, compWins = 0, compMove, userMove, result;
	typedef std::unordered_map<int, std::string> moveMap;
	moveMap moves = { { 1, "Rock" }, { 2, "Paper" }, { 3, "Scissors" } };

	// Initialize random number generator
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 eng(rd()); // seed the generator
	std::uniform_int_distribution<> distr(1, 3); // define the range

	std::ofstream results;
	results.open("results.txt");

	std::cout << "Welcome!" << std::endl;

	// std::cout << " Does 'results.txt' already exist? [y/n]? " << std::endl;

	/*
	if (results) {

		// Yes, truncate it
		results.close();
		results.open("results.txt", std::ios::trunc);
	}
	*/
	
	while (playing)
	{
		std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
		getline(std::cin, userMoveStr);

		while (!(userMoveStr == "1" || userMoveStr == "2" || userMoveStr == "3"))
		{
			std::cout << "Unknown command! Please try that again... \n\n" << std::endl;
			std::cout << "Enter 1 to play Rock, 2 to play Paper, and 3 to play Scissors!: ";
			getline(std::cin, userMoveStr);
		}

		// Convert the user move from a string to an integer
		userMove = std::stoi(userMoveStr);

		// Create random integer in range [1,3] to simulate the computer selecting a move
		compMove = distr(eng);

		result = userMove - compMove;

		if (result == 0)
			
			results << "Tie game! \n" << std::endl;
			std::cout << "Tie game! \n" << std::endl;

		if (result == 1 || result == -2)

		{

			results << "Congratulations, you won!" << std::endl;
			std::cout << "Congratulations, you won!\n" << std::endl;


			playerWins++;

		}

		else

		{

			results << "Sorry, you lost!" << std::endl;
			std::cout << "Sorry, you lost! \n" << std::endl;


			compWins++;

		}

		std::cout << std::endl;
		std::cout << "Your move: " << moves[userMove] << " // Computer's move: " << moves[compMove] << std::endl << std::endl;
		std::cout << "(Player: " << playerWins << " | Computer: " << compWins << ")" << std::endl << std::endl;
		std::cout << "Play again? [y/n]: ";
		getline(std::cin, playAgain);

		while (!(playAgain == "y" || playAgain == "n"))

		{
			std::cout << "Unknown command! Please try that again..." << std::endl;
			std::cout << "Play again? [y/n]: ";
			getline(std::cin, playAgain);
		}

		if (playAgain == "n")
			playing = false;
	}

	results.close();

	return 0;
}