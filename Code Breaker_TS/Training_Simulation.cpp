//Creator Information:
/*
Name: Hunter Derrick
Professor Name: Tony Hinton
Start Date: 10/21/18
Completion Date: 10/28/18
Project Title: Code Breaker - Training Simulation
Class: CSC215 @ UAT.
*/

//TASK
/*By hand, choose 10 single code words of your choice, and write down a hint for each word.
Create a new C++ project called Keywords
This Code Breaker Training Simulation Program should give the user directions and tell them what it is and how to use it based of the background description above.
Then your Code Breaker Training Simulation Program should randomly select 3 of the 10 words that are coded in your program.
Your code breaker will scramble each word on the fly and different each run randomly.
Now make the user try to solve each one of the three randomly picked coded word from your random list.
Each turn you should give your user feedback on if they got the guess correct or not.
You should also offer the user help.
At the end, you should display their stats and ask if they would like to try again.
After you have a project, publish your code to a new GitHub repository.*/

//Including...
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

//10 Code Words and Meanings
/*

-Alpha - First letter of Military Phonetic Alphabet
-Eagle - Freedom Bird
-Duck - Code Debugger or Pond Swimmer
-Fox - What does it say? Does anyone know?
-Glasses - Tool to assist in eyesight
-Paper - Write on me, draw on me. I don't care. I am a useful tool.
-Window - People look out of me, but don't realize it is what's on the inside that matters.
-Door - I get slammed, I get shut, I get closed. But on some occasions, I get open. What am I?
-Television - You watch me. 
-Keyboard - Odds are, you're using me right now. How dare you use me like that.

*/

int main()
{

	bool playAgain = false;  //Setting a bool to determine if Player wants to play more than once.


	//Let's welcome the player to our Game.
	cout << "\t\tWelcome to Word Scramble\n\n";
	cout << "Unscramble the letters and create the word.\n\n";
	cout << "Type the word 'HINT' for a hint.\n\n";
	cout << "You can quit at any time by typing the word 'QUIT'.\n\n";


	//Create a Do_While Loop. This will run the game until player decides they no longer wish to play.
	do
	{
		//For_Loop. This will run through 3 random words. Player guesses 3 words for each game before being asked to play again.
		for (int i = 0; i < 3; ++i)
		{
			bool playAgain = false;

			enum fields { WORD, HINT, NUM_FIELDS };
			//State how many words there are.
			const int NUM_WORDS = 10;
			//Initialize Words and corresponding hints. Word on left, Hint on Right.
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"alpha", "First letter of Military Phonetic Alphabet"},
				{"eagle", "Freedom Bird"},
				{"duck","Code Debugger or Pond Swimmer"},
				{"fox","What does it say? Does anyone know?"},
				{"glasses","Tool to assist in eyesight"},
				{"paper","Write on me, draw on me. I don't care. I am a useful tool."},
				{"window","People look out of me, but don't realize it is what's on the inside that matters."},
				{"door","I get slammed, I get shut, I get closed. But on some occasions, I get open. What am I?"},
				{"television","You watch me. "},
				{"keyboard","Odds are, you're using me right now. How dare you use me like that."}
			};

			//Picking a random word from the choices...
			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % NUM_WORDS);
			string theWord = WORDS[choice][WORD]; //The word to Guess...
			string theHint = WORDS[choice][HINT]; //The hint to the word...

			//Now time to create a jumbled version of chosen word.
			string randWordChoice = theWord;
			int length = randWordChoice.size();
			for (int i = 0; i < length; ++i)
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = randWordChoice[index1];
				randWordChoice[index1] = randWordChoice[index2];
				randWordChoice[index2] = temp;
			}

			//Show player what the scrambled word is.
			cout << "The scrambled word is: " << randWordChoice;

			//Ask user to guess what the word is.
			string guess;
			cout << "\n\nWhat is your guess: ";
			cin >> guess;


			//Entering the Game Loop
			//While_Loop will run as long as the users guess does not equal 'The Word' or quit. Will also allow user to ask for a hint.
			while ((guess != theWord) && (guess != "quit"))
			{
				//If user asks for a hint.
				if (guess == "hint")
				{
					cout << "\nThe Hint is: " << theHint;
				}
				else
				{
					cout << "\nSorry, that guess is not correct." << endl;
				}
				//After hint is displayed, ask user to guess.
				cout << "\n\nWhat is your guess: ";
				cin >> guess;
			}

			//If the user guesses the word.
			if (guess == theWord)
			{
				cout << "\nCONGRATULATIONS. You guessed correctly.\n" << endl;
			}
			else if(guess == "quit" || "Quit")
			{
				cout << "I am sad to see you leave. But I understand. :( " << endl;
				playAgain = false;
				break;
			}

			system("pause");
		}

		char playerChoice;
		cout << "\nWould you like to play again 'y/n':  ";
		cin >> playerChoice;

		if (playerChoice == 'y' || playerChoice == 'Y')
		{
			playAgain = true;
		}
		else
		{
			playAgain = false;
		}
	} while (playAgain);

	cout << "\nThanks for playing. Have a nice day!\n" << endl;

	system("pause");
	return 0;

}

	


	
