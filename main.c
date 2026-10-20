#include <stdio.h>
#include <stdlib.h>
void printb(char board[]){
	printf("\n %c | %c | %c\n-----------\n %c | %c | %c\n-----------\n %c | %c | %c\n\n", board[0],board[1],board[2],board[3],board[4],board[5],board[6],board[7],board[8]);
}
int determine(char board[],int size, int turn){
	int hc = 0;
	int np = 0;
	int wm[8][3] = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8},{0, 3, 6}, {1, 4, 7}, {2, 5, 8},{0, 4, 8}, {2, 4, 6}};
	for(int i =0;i<8;i++){
		int a = wm[i][0];
		int b = wm[i][1];
		int c = wm[i][2];
		if(board[a] != ' ' && board[a] == board[b] && board[b] == board[c]){hc=1;break;}
	}
	if(hc==1){
		return (turn == 1) ? 2 : 1;
	}
	for(int i =0;i<9;i++){
		np += (board[i] == ' ') ? 1 : 0;
	}
	if(np == 0) return 3;
	return 0;
}
int main(void){
	char board[9];
	int win = 0;
	int turn = 1;
	char turnspot;
	for (int i =0;i<9;i++){board[i] = ' ';}
	while(win == 0){
		win = determine(board,9,turn);
		if(win != 0) break;
		printb(board);
		printf("Player %d turn? (1-9): ", turn);
		turnspot = getchar() - '0';
		turnspot -= 1;
		while (getchar() != '\n');
		if ((turnspot < 0) || (turnspot > 8)) continue;
		if (board[turnspot] != ' ') continue;
		board[turnspot] = (turn == 1) ? 'X' : 'O';
		turn = (turn == 1) ? 2 : 1;
		turnspot = -1;
	}
	printb(board);
	if(win == 3){
		printf("Game has tied\n");
	}else{
		printf("Player %d won the game\n", win);
	}
	return 0;
}