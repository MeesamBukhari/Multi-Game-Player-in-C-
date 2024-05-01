// Programming Fundamentals Project -- 1st Semester -- BSCS -- Fall 2023
// Syed Meesam Turab Bukhari -- B23F0120CS064
// Syeda Rija Fatima -- B23F0222CS091

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


void ticTacToe();
void GameChart(string, string , char CharMatrixDraw[] );
int winner( char CharMatrixDraw[] );

void rockPaperScissor();

void guessTheNumber();


int main(){
	
	srand(time(0));
	int choice;

	bool repetition=1;
	char ch;

while( repetition )
{

    cout<<"\n\nPlay Games:\n";
    cout<<"1. Rock Paper Scissors\n";
    cout<<"2. Tic Tac Toe\n";
    cout<<"3. Guess the Number\n";
    cout<<"4. Exit\n";

	cout<<"Enter your choice: ";
	cin >> choice;

	switch(choice)
	{
		case 1:
			cout<<"\n\n\n============================= Rock Paper Scissors =============================\n\n\n\n";
			rockPaperScissor();
		break;

		case 2:
			cout<<"\n\n\n============================= Tic Tac Toe =============================\n\n\n\n";
			ticTacToe();
		break;
	
		case 3:
			cout<<"\n\n\n============================= Guess the Number =============================\n\n\n\n";
			guessTheNumber();
		break;

		case 4:
			cout<<"Thank you for playing!!!\n";
			return 0;
		break;

		default:
			cout<<"Invalid Choice\n";
			return 0;
		break;
	}

		cout << "Do you want to play any other game??? (Press 'Y' to proceed) ";	cin >> ch;
		
		if( ch == 'y' || ch == 'Y' )
			repetition=1;
		else                            
			repetition=0;

}



}



void guessTheNumber()
{	
	char ch;
	int repetition=1;

	while( repetition )
	{
		int i=1 ,num;
		srand(time(0));
		
		int x = (rand()%100)+1;	
		cout << "Hi! I'm thinking of a random number between 1 and 100." << endl;	
		while ( i<=10 )
		{
			cout << "---Attempt " << i << ": Number of tries left: " << 11 - i << endl;
			cout << "Guess what number I am thinking of: ";	
			cin >> num;		
			if ( num == x ){
				cout << "You guessed it right.\n";
				break;
			}
			else if( num < x )
				cout << "Too low.\n";
			else if ( num > x )
				cout << "Too high.\n";
			i++;
		}
		
		if ( i==11 ) 	
			cout << "Aw, you ran out of tries. The number was " << x << '.' << endl;	
	
		cout << "Do you want to play this game again??? (Press 'Y' to proceed) ";	
		cin >> ch;
		
		if( ch == 'y' || ch == 'Y' )
			repetition=1;
		else                            
			repetition=0;

	}

}


void ticTacToe(  )
{

	bool repetition=1;
	char ch;

while( repetition )
{

	int Gamer = 1, i , choice;
	string name1;
	string name2;
	char CharMatrixDraw[10] = { '0', '1', '2',
								'3', '4', '5',
								'6', '7', '8', '9' };


	cout<<"1. Tic Tac Toe Game Chart draw."<<endl;
	cout<<"2. Changing the Value of Tic Tac Toe Game Chart."<<endl;
	cout<<"3. Check Win."<<endl<<endl;
	cout<<"Please enter the players name to start the game"<<endl;
	cout<<"============================================================="<<endl;
	cout << "Enter First Player's Name: ";
	cin >> name1;

	cout << "\nEnter Second Player's Name: ";
	cin >> name2;
				
	char mark;
	do {
		GameChart(name1, name2,  CharMatrixDraw );
		Gamer = (Gamer % 2) ? 1 : 2;

		if (Gamer == 1)
		{
			cout << name1 << "! Your Turn, Enter a Number: ";
			cin >> choice;
		}
		else
		{
			cout << name2 << "! Your Turn, Enter a Number: ";
			cin >> choice;
		}
				

		mark = (Gamer == 1) ? 'X' : 'O';

		if (choice == 1 && CharMatrixDraw[1] == '1')
			CharMatrixDraw[1] = mark;

		else if (choice == 2 && CharMatrixDraw[2] == '2')
			CharMatrixDraw[2] = mark;

		else if (choice == 3 && CharMatrixDraw[3] == '3')
			CharMatrixDraw[3] = mark;

		else if (choice == 4 && CharMatrixDraw[4] == '4')
			CharMatrixDraw[4] = mark;

		else if (choice == 5 && CharMatrixDraw[5] == '5')
			CharMatrixDraw[5] = mark;

		else if (choice == 6 && CharMatrixDraw[6] == '6')
			CharMatrixDraw[6] = mark;

		else if (choice == 7 && CharMatrixDraw[7] == '7')
			CharMatrixDraw[7] = mark;

		else if (choice == 8 && CharMatrixDraw[8] == '8')
			CharMatrixDraw[8] = mark;

		else if (choice == 9 && CharMatrixDraw[9] == '9')
			CharMatrixDraw[9] = mark;

		else
		{
			cout << "\nInvalid Choice Try Again ";
			Gamer--;
			cin.ignore();
			cin.get();
		}

		i = winner( CharMatrixDraw );
		Gamer++;

	} while ( i == -1 );

	GameChart(name1, name2 , CharMatrixDraw );
	if (i == 1)
	{
		cout << "\n=============================\n";
		cout << "\a" << name1 << " is Winner \n";
		cout << "=============================\n";
		cout<<"please press any key to close the game"<<endl;
		cout<<"================================================================="<<endl;
	}
	else
	{
		cout << "\n=============================\n";
		cout << "\aGame Is Draw\n";
		cout << "=============================\n";
		cout<<"Please press any key to close the game."<<endl;
		cout<<"================================================================="<<endl;
	}

	cin.ignore();
	cin.get();

		cout << "Do you want to play this game again??? (Press 'Y' to proceed) ";	
		cin >> ch;
		
		if( ch == 'y' || ch == 'Y' )
			repetition=1;
		else
		    repetition=0;

}


}		

int winner( char CharMatrixDraw[] )
{

	if (CharMatrixDraw[1] == CharMatrixDraw[2] && CharMatrixDraw[2] == CharMatrixDraw[3])
		return 1;
	else if (CharMatrixDraw[4] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[6])
		return 1;
	else if (CharMatrixDraw[7] == CharMatrixDraw[8] && CharMatrixDraw[8] == CharMatrixDraw[9])
		return 1;
	else if (CharMatrixDraw[1] == CharMatrixDraw[4] && CharMatrixDraw[4] == CharMatrixDraw[7])
		return 1;
	else if (CharMatrixDraw[2] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[8])
		return 1;
	else if (CharMatrixDraw[3] == CharMatrixDraw[6] && CharMatrixDraw[6] == CharMatrixDraw[9])
		return 1;
	else if (CharMatrixDraw[1] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[9])
		return 1;
	else if (CharMatrixDraw[3] == CharMatrixDraw[5] && CharMatrixDraw[5] == CharMatrixDraw[7])
		return 1;
	else if (CharMatrixDraw[1] != '1' && CharMatrixDraw[2] != '2' && CharMatrixDraw[3] != '3' &&
			 CharMatrixDraw[4] != '4' && CharMatrixDraw[5] != '5' && CharMatrixDraw[6] != '6' &&
			 CharMatrixDraw[7] != '7' && CharMatrixDraw[8] != '8' && CharMatrixDraw[9] != '9')
		return 0;
	else
		return -1;
}

void GameChart(string name1, string name2 , char CharMatrixDraw[] )
{
	system("cls");
	cout << "\n==========================";
	cout << "\n\tTic Tac Toe\n";
	cout << "\n==========================\n";
	string nam1 = name1;
	string nam2 = name2;
	cout << nam1 << "(X)" << "========" << nam2 << " (O)\n\n";
	cout << "     ||     ||     " << endl;
	cout << "  " << CharMatrixDraw[1] << "  ||  " << CharMatrixDraw[2] << "  ||  " << CharMatrixDraw[3] << endl;
	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;
	cout << "  " << CharMatrixDraw[4] << "  ||  " << CharMatrixDraw[5] << "  ||  " << CharMatrixDraw[6] << endl;
	cout << "=====||=====||=====" << endl;
	cout << "     ||     ||     " << endl;
	cout << "  " << CharMatrixDraw[7] << "  ||  " << CharMatrixDraw[8] << "  ||  " << CharMatrixDraw[9] << endl;
	cout << "     ||     ||     " << endl << endl;

}





void rockPaperScissor()
{
	
	bool repetition=1;
	char ch;

	string p1name, p2name;
	char player1, player2;
	
while( repetition )
{	
	cout<<"Enter the name of Player 1: ";
	cin>>p1name;
	cout<<"Enter the name of Player 2: ";
	cin>>p2name;
	cout<<"R = Rock | P = Paper | S = Scissors\n";
	cout<<p1name<<"! Enter your choice (R/P/S): ";	
	cin>>player1;
	cout<<p2name<<"! Enter your choice (R/P/S): ";	
	cin>>player2;
	switch(player1){
		case 'R':
		case 'r':
			switch(player2){
				case 'R':
				case 'r':
					cout<<"Tie";
					break;
				case 'P':
				case 'p':
					cout<<p2name<<" Won";
					break;
				case 'S':
				case 's':
					cout<<p1name<<" Won";
					break;
				default:
					cout<<"Invalid Choice Made!!!";
					break;
			}
			break;
		case 'P':
		case 'p':
			switch(player2){
				case 'R':
				case 'r':
					cout<<p1name<<" Won";
					break;
				case 'P':
				case 'p':
					cout<<"Tie";
					break;
				case 'S':
				case 's':
					cout<<p2name<<" Won";
					break;
				default:
					cout<<"Invalid Choice Made!!!";
					break;
			}
			break;
		case 'S':
		case 's':
			switch(player2){
				case 'R':
				case 'r':
					cout<<p2name<<" Won";
					break;
				case 'P':
				case 'p':
					cout<<p1name<<" Won";
					break;
				case 'S':
				case 's':
					cout<<"Tie";
					break;
				default:
					cout<<"Invalid Choice Made!!!";
					break;
			}
			break;
		default:
			cout<<"Invalid Choice Made!!!";
			break;
	}

		cout << "\nDo you want to play this game again??? (Press 'Y' to proceed) ";	cin >> ch;
		
		if( ch == 'y' || ch == 'Y' )
			repetition=1;
		else                            
			repetition=0;	
}
}