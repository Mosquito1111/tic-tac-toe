# include <stdio.h>
# include <stdlib.h>
# include <time.h>

void spawn(int board[3][3]);
void move(int board[3][3]);
int is_gameover(int board[3][3]);
void draw(int board[3][3]);

int main()
{
	srand((unsigned int)time(NULL));
	while(1){
	int board[3][3]={0};
	int i,j;
	
	printf("+---+---+---+\n");
	printf("| 1 | 2 | 3 |\n");
	printf("+---+---+---+\n");
	printf("| 4 | 5 | 6 |\n");
	printf("+---+---+---+\n");
	printf("| 7 | 8 | 9 |\n");
	printf("+---+---+---+\n");
	
	int flag=0;
	char input;
	printf("Welcome to Tic-Tac-Toe!\n");
	printf("You are 'x' and the computer is 'o'.\n");
	printf("Enter a number from 1 to 9 to place your mark.\n");
	printf("Get three in a row to win. Good luck!\n");
	
	while(1){
		
		printf("Do you want to go first?(y/n/q):");
		scanf(" %c",&input);
		
		if(input=='y'||input=='Y'){
			flag=1;
			break;
		}
		else if(input=='n'||input=='N'){
			flag=0;
			break;
		}
		else if(input=='q'||input=='Q'){
			return 0;
		}
		else{
			printf("please input y/n/quit!\n");
		}
	}
	
	int state;
	
	while(1){
		
		if(flag==1){
			move(board);
			draw(board);
			state=is_gameover(board);
			// state=1 -> win
			if(state==1){
				printf("You win!\n");
				break;
			}
			// state=2 -> draw
			else if(state==2){
				printf("No one win the game :(\n");
				break;
			}
			// state=0 -> continnue
			else if(state==0){
				flag=0;
				continue;
			}
		}
		else if(flag==0){
			spawn(board);
			draw(board);
			state=is_gameover(board);
			if(state==1){
				printf("Computer win!\n");
				break;
			}
			else if(state==2){
				printf("No one win the game :(\n");
				break;
			}
			else if(state==0){
				flag=1;
				continue;
			}
		}
	}
	printf("Play again?(y/n)\n");
	scanf(" %c",&input);
	
		
	if(input=='y'||input=='Y'){
		continue;
	}
	else{
		return 0;
	}
	}
}

void move(int board[3][3]){
	int input;
	printf("please input number 1~9:");
	while(1){
		if (scanf("%d", &input) != 1){
			while (getchar() != '\n');
			printf("please input a number:");
			continue;
		}
		if(input<1||input>9){
			continue;
		}
		else{
			if(input==1&&board[0][0]==0){
				board[0][0]=1; //human is 1,computer is -1 
				break;
			}
			else if(input==2&&board[0][1]==0){
				board[0][1]=1;
				break;
			}
			else if(input==3&&board[0][2]==0){
				board[0][2]=1;
				break;
			}
			else if(input==4&&board[1][0]==0){
				board[1][0]=1;
				break;
			}
			else if(input==5&&board[1][1]==0){
				board[1][1]=1;
				break;
			}
			else if(input==6&&board[1][2]==0){
				board[1][2]=1;
				break;
			}
			else if(input==7&&board[2][0]==0){
				board[2][0]=1;
				break;
			}
			else if(input==8&&board[2][1]==0){
				board[2][1]=1;
				break;
			}
			else if(input==9&&board[2][2]==0){
				board[2][2]=1;
				break;
			}
			else{
				printf("please input number again:");
	 			continue;
			}
		}
	}	
}

int is_gameover(int board[3][3]){
	int i,j,win=0;
	//is_win? 
	for(i=0;i<3;i++){
		if(board[i][0]==board[i][1]&&board[i][1]==board[i][2]&&board[i][0]!=0){
			win=1;
		}
	}
	for(j=0;j<3;j++){
		if(board[0][j]==board[1][j]&&board[1][j]==board[2][j]&&board[0][j]!=0){
			win=1;
		}
	}
	if(board[0][0]==board[1][1]&&board[1][1]==board[2][2]&&board[0][0]!=0){
		win=1;
	}
	if(board[0][2]==board[1][1]&&board[1][1]==board[2][0]&&board[0][2]!=0){
		win=1;
	}
	
	if(win==1){
		return 1;	//win
	}
	else{
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(board[i][j]==0)
				return 0;	//countinue 
			}
		}
		return 2;	//draw 
	} 
}

void spawn(int board[3][3]){
	int count=0;
	int i,j; 
	int empty[9];
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==0){
				empty[count]=i*3+j;	//coordinates -> index 
				count++; 
			}
		}
	}
	int index=rand()%count;	
	int choose=empty[index];
	
	int r=choose/3;				//index -> coordinates
	int c=choose%3;
	board[r][c]=-1; 
}

void draw(int board[3][3]){
	char symbol[4][4];
	int i,j;
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			if(board[i][j]==1){
				symbol[i][j]='x';
			}
			else if(board[i][j]==-1){
				symbol[i][j]='o';
			}
			else{
				symbol[i][j]=' ';
			}
		}
	}

	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n",symbol[0][0],symbol[0][1],symbol[0][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n",symbol[1][0],symbol[1][1],symbol[1][2]);
	printf("+---+---+---+\n");
	printf("| %c | %c | %c |\n",symbol[2][0],symbol[2][1],symbol[2][2]);
	printf("+---+---+---+\n");
}

