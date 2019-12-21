//BLACKJACK GAME
#include <clocale>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
#include <iostream>

using namespace std;
//---------------------------------------------------------------
struct Card {
	int name;
	int suit;
	bool is_card_of_player;
};
//-------------------------------------------------------------
class BlackJack
{
private:
	char _names[13][3];
	char _suits[4][2];
	int arr_receied_cards[4][13];
	int temp_suits;
	int temp_names;
	int player_scores;
	int casino_scores;
	char answer;
public:
	Card current_card; // the structure describe current card
	Card used_cards_array[52];
	int index_of_used_cards_array;
	//----------------------------------------------------------------------------
	BlackJack()
	{
		index_of_used_cards_array = 0;
		temp_suits = 0;
		temp_names = 0;
		player_scores = 0;
		casino_scores = 0;
		answer = ' ';
		// { "2","3","4","5","6","7","8","9","10","J","Q","K","A" };
		// { "\x05","\x04","\x03","\x06" };//?????, ?????, ?????, ????
		strcpy_s(_names[0], "2");
		strcpy_s(_names[1], "3");
		strcpy_s(_names[2], "4");
		strcpy_s(_names[3], "5");
		strcpy_s(_names[4], "6");
		strcpy_s(_names[5], "7");
		strcpy_s(_names[6], "8");
		strcpy_s(_names[7], "9");
		strcpy_s(_names[8], "10");
		strcpy_s(_names[9], "J");
		strcpy_s(_names[10], "Q");
		strcpy_s(_names[11], "K");
		strcpy_s(_names[12], "A");
		char* temp = new char[2];
		*(temp + 0) = (char)5;//krest
		*(temp + 1) = '\0';
		strcpy_s(_suits[0], temp);

		*(temp + 0) = (char)4;//bubna
		*(temp + 1) = '\0';
		strcpy_s(_suits[1], temp);

		*(temp + 0) = (char)3;//chirva
		*(temp + 1) = '\0';
		strcpy_s(_suits[2], temp);

		*(temp + 0) = (char)6;//pika
		*(temp + 1) = '\0';
		strcpy_s(_suits[3], temp);

		delete[]temp;

		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 13; j++) {
				arr_receied_cards[i][j] = 0;
			}
		}
	}
	//--------------------------------------------------------------
	void Card_providing(bool players_card) {
		srand(time(0));
		for (int i = 0; i < 52; i++) {
		metka1:
			temp_suits = rand() % 4;
			temp_names = rand() % 13;
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 13; j++) {
					if (arr_receied_cards[i][j] == 1 && i == temp_suits && j == temp_names)
					{
						goto metka1;
					}
					if (arr_receied_cards[i][j] == 0 && i == temp_suits && j == temp_names)
					{
						arr_receied_cards[i][j] = 1;
						//propisyvaem snachala object tipa Card, a potom pomechaem ego
						//v massiv ispol,sovannyh card i index massiva uvelichivaem na 1;
						current_card.is_card_of_player = players_card;
						current_card.name = temp_names;
						current_card.suit = temp_suits;
						used_cards_array[index_of_used_cards_array] = current_card;
						index_of_used_cards_array++;
						return;
					}
				}
			}
		}

	}

	//---------------------------------------------------------------------
	void Show_cards_in_play()
	{
		cout << "--------------------------------------------" << endl;
		cout << "------------BLACKJACK CARD GAME-------------" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "**********CARDS RECEIVED BY CASINO**********" << endl;
		cout << "--------------------------------------------" << endl;
		for (int k = 0; k < index_of_used_cards_array; k++)
		{
			if (k == 0 && answer != 'n')
			{
				cout << "                 ----- \n";
				cout << "                | +++ |\n";
				cout << "                | +++ |\n";
				cout << "                | +++ |\n";
				cout << "                 ----- \n";
			}

			if (k != 0 && answer != 'n')
			{
				if (used_cards_array[k].is_card_of_player == false && used_cards_array[k].name != 8)
				{
					cout << "                 ----- \n";
					cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
					cout << "                |  " << _names[used_cards_array[k].name] << "  |\n";
					cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
					cout << "                 ----- \n";
				}
				if (used_cards_array[k].is_card_of_player == false && used_cards_array[k].name == 8)
				{
					cout << "                 ----- \n";
					cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
					cout << "                |  " << _names[used_cards_array[k].name] << " |\n";
					cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
					cout << "                 ----- \n";
				}
			}

			if (answer == 'n')
			{
				if (used_cards_array[k].is_card_of_player == false && used_cards_array[k].name != 8)
				{
					cout << "                 ----- \n";
					cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
					cout << "                |  " << _names[used_cards_array[k].name] << "  |\n";
					cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
					cout << "                 ----- \n";
				}
				if (used_cards_array[k].is_card_of_player == false && used_cards_array[k].name == 8)
				{
					cout << "                 ----- \n";
					cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
					cout << "                |  " << _names[used_cards_array[k].name] << " |\n";
					cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
					cout << "                 ----- \n";
				}
			}


		}
		cout << "--------------------------------------------" << endl;
		cout << "**********CARDS RECEIVED BY PLAYER**********" << endl;
		cout << "--------------------------------------------" << endl;
		for (int k = 0; k < index_of_used_cards_array; k++)
		{
			if (used_cards_array[k].is_card_of_player == true && used_cards_array[k].name != 8)
			{
				cout << "                 ----- \n";
				cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
				cout << "                |  " << _names[used_cards_array[k].name] << "  |\n";
				cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
				cout << "                 ----- \n";
			}
			if (used_cards_array[k].is_card_of_player == true && used_cards_array[k].name == 8)
			{
				cout << "                 ----- \n";
				cout << "                |" << _suits[used_cards_array[k].suit] << "    |\n";
				cout << "                |  " << _names[used_cards_array[k].name] << " |\n";
				cout << "                |    " << _suits[used_cards_array[k].suit] << "|\n";
				cout << "                 ----- \n";
			}

		}
	}
	//---------------------------------------------------------------------
	void Show_result_of_play()
	{
		int k = 0;
		for (k = (index_of_used_cards_array == 4) ? 0 : (index_of_used_cards_array - 1); k < index_of_used_cards_array; k++)
		{
			if (used_cards_array[k].is_card_of_player == true)
			{
				if (used_cards_array[k].name >= 0 && used_cards_array[k].name <= 8)
					player_scores += (used_cards_array[k].name + 2);
				if (used_cards_array[k].name >= 9 && used_cards_array[k].name <= 11)
					player_scores += 10;
				if (used_cards_array[k].name == 12 && player_scores < 21)
					player_scores += 11;
				if (used_cards_array[k].name == 12 && player_scores > 21)
					player_scores += 1;
			}
			if (used_cards_array[k].is_card_of_player == false)
			{
				if (used_cards_array[k].name >= 0 && used_cards_array[k].name <= 8)
					casino_scores += (used_cards_array[k].name + 2);
				if (used_cards_array[k].name >= 9 && used_cards_array[k].name <= 11)
					casino_scores += 10;
				if (used_cards_array[k].name == 12 && casino_scores < 21)
					casino_scores += 11;
				if (used_cards_array[k].name == 12 && casino_scores > 21)
					casino_scores += 1;
			}
		}
		cout << "--------------------------------------------" << endl;
		cout << "************RESULTS OF THE GAME*************" << endl;
		cout << "--------------------------------------------" << endl;
		if (answer != 'n')
			cout << "\nCASINO SCORES: " << "XX" << endl;
		if (answer == 'n')
			cout << "\nCASINO SCORES: " << casino_scores << endl;
		cout << "PLAYER SCORES: " << player_scores << endl;
	}

	//---------------------------------------------------------------------

	void Operating_game(bool players_card)
	{
		do
		{
			cout << "\nWOULD YOU LIKE TO GET ONE MORE CARD? (y/n)\n";
			cout << "TO EXIT, PRESS 'q'\n";
			for (;;)
			{
				cin >> answer;
				if (answer != 'y' && answer != 'n' && answer != 'q')
				{
					cout << "PLEASE, INPUT CORRECT SYMBOL!!!" << endl;
				}
				else { break; }
			}

			if (answer == 'y')
			{
				system("cls");
				Card_providing(true);
				Show_cards_in_play();
				Show_result_of_play();
			}
			if (answer == 'n' && casino_scores < 17)
			{
				system("cls");
				for (int i = 0; i < 52; i++)
				{
					if (casino_scores < 17)
					{
						Card_providing(false);
						Show_cards_in_play();
						Show_result_of_play();
					}
					if (casino_scores >= 17)
					{
						Show_cards_in_play();
						Checking_scores();
						break;
					}
				}

			}
			if (answer == 'n' && casino_scores >= 17)
			{
				system("cls");
				Show_cards_in_play();
				Checking_scores();
				break;
			}

		} while (answer != 'q');

	}

	//---------------------------------------------------------------------------------
	void Checking_scores()
	{
		if ((player_scores <= 21 && player_scores > casino_scores) || (player_scores <= 21 && casino_scores > 21))
		{
			cout << "PLAYER WON WITH SCORES:  " << player_scores << "\n";
			cout << "CASINO LOST WITH SCORES: " << casino_scores << "\n";
		}

		if (player_scores > 21 && casino_scores > 21)
		{
			cout << "PLAYER LOST WITH SCORES: " << player_scores << "\n";
			cout << "CASINO LOST WITH SCORES: " << casino_scores << "\n";
		}

		if ((casino_scores <= 21 && casino_scores > player_scores) || (casino_scores <= 21 && player_scores > 21))
		{
			cout << "CASINO WON WITH SCORES:  " << casino_scores << "\n";
			cout << "PLAYER LOST WITH SCORES: " << player_scores << "\n";
		}

		if ((player_scores < 22 && casino_scores < 22) && (player_scores == casino_scores))
		{
			cout << "THIS TIME A PUSH!!!\n";
		}

	}
	//-----------------------------------------------------------------------------
};

//---------------------------------------------------------------------------------
int main()
{
	BlackJack A;
	for (int k = 0; k < 2; k++)
	{
		A.Card_providing(false);
	}

	for (int k = 0; k < 2; k++)
	{
		A.Card_providing(true);
	}

	A.Show_cards_in_play();
	A.Show_result_of_play();
	A.Operating_game(true);

	system("pause");
	return 0;
}