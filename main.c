#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "board.h"

int main();

/*
* Put color in white, the color by default in a console.
*/
void reset_color(){
	printf("\033[0m");
}

/*
 * Initialize the 16 pieces with characteristics
 */
void init_pieces(piece pieces_array[]){
	int i=0;
	
	for(int sizee=0; sizee<2; sizee++){
		for(int shapee=0; shapee<2; shapee++){
			for(int colorr=0; colorr<2; colorr++){
				for(int topp=0; topp<2; topp++){
					pieces_array[i] = get_piece_from_characteristics(sizee, shapee, colorr, topp);
					i++;
				}
			}
		}
	}
}

/*
* This function displays under the board the available pieces
* that can be played.
*/
void display_pieces(board game, piece pieces[]){
	int i=0;
  char *ouga[8]={"●","○","■","□",
                "●●","○○","■■","□□"};

	printf("\n");
	for(int l=0; l<4; l++){
		for(int c=0; c<4; c++){
			reset_color();

      if(i+1>9){
        printf("%d. ",i+1);
      }else{
        printf(" %d. ",i+1);
      }

      if(piece_size(pieces[i])==TALL &&
          piece_shape(pieces[i])==SQUARE &&
          piece_top(pieces[i])==HOLLOW){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[7]);

      }else if(piece_size(pieces[i])==TALL &&
          piece_shape(pieces[i])==SQUARE &&
          piece_top(pieces[i])==SOLID){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[6]);

      }else if(piece_size(pieces[i])==TALL &&
          piece_shape(pieces[i])==CIRCULAR &&
          piece_top(pieces[i])==HOLLOW){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[5]);
      }else if(piece_size(pieces[i])==TALL &&
          piece_shape(pieces[i])==CIRCULAR &&
          piece_top(pieces[i])==SOLID){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[4]);
      }else if(piece_size(pieces[i])==SHORT &&
          piece_shape(pieces[i])==SQUARE &&
          piece_top(pieces[i])==HOLLOW){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[3]);
      }else if(piece_size(pieces[i])==SHORT &&
          piece_shape(pieces[i])==SQUARE &&
          piece_top(pieces[i])==SOLID){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[2]);
      }else if(piece_size(pieces[i])==SHORT &&
          piece_shape(pieces[i])==CIRCULAR &&
          piece_top(pieces[i])==HOLLOW){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[1]);
      }else if(piece_size(pieces[i])==SHORT &&
          piece_shape(pieces[i])==CIRCULAR &&
          piece_top(pieces[i])==SOLID){
            if(is_present_on_board(game,pieces[i])){
				      printf("\033[0;30m");
              }else{
                if(piece_color(pieces[i])==BLUE){
                  printf("\033[0;34m");
                }else{
                  printf("\033[0;31m");
                }
            }
          printf("%s",ouga[0]);
      }
      if(piece_size(pieces[i])==SHORT){
        printf("  ");
      }else{
        printf(" ");
      }
      i++;
    }
		reset_color();
		printf("\n");
	}
}


/*
* Display in color the current player
*/
void display_current_player(player pl){
		printf("\n↳ ");
		if(pl==PLAYER1){
			printf("\033[0;32m");
			printf("[PLAYER 1] ");
		}else{
			printf("\033[0;35m");
			printf("[PLAYER 2] ");
		}
		printf("\033[1;0m");
}


/*
* Ask the player to choose on which line to place the piece
*/
void ask_x(board game, int* x_choisi, player current_player){
		display_current_player(current_player);
		printf("On which line to place it? ");
		scanf("%d",x_choisi);
		
		while(*x_choisi < 1 || *x_choisi >DIMENSION){
			printf("\nError: the chosen line must be an integer between 1 and %d, not placed on the board\n",DIMENSION);
			display_current_player(current_player);
			printf("On which line to place it? ");
			scanf("%d",x_choisi);
		}	
}



/*
* Ask the player to choose on which column to place the piece
*/
void ask_y(board game, char* y_choisi, player current_player){
		display_current_player(current_player);
		printf("On which column to place it? ");
		scanf(" %c",y_choisi);
		
		while(*	y_choisi < 97 || *y_choisi >DIMENSION+96){
			printf("\nError: the chosen column must be a character between 'a' and '%c' not placed on the board\n",DIMENSION+96);
			display_current_player(current_player);
			printf("On which column to place it? ");
			scanf(" %c",y_choisi);
		}
}


/*
* Return a random number between 1 and 2 to choose randomly the first player
*/
enum players_t random_draw(){
	if(rand()%2+1==1){
		return PLAYER1;
	}else{
		return PLAYER2;
	}
}


/*
* Return 1 or 2 to switch the current player
*/
int switch_player(player pl){
  if(pl==PLAYER1){
		return 2;
	}
	return 1;
}


/*
* Display the winner then ask to play again
*/
void win_display(player winner){
  system("clear");

	printf("\033[1;31m");
	for(int i=0; i<25; i++){
    if(i==13){
      for(int a=0; a<29; a++){
        printf("-");
      }
      printf(" QUARTO ! Player %d won ", winner); //28 carac ; 80-28 = 52/2 = 26
      for(int a=0; a<28; a++){
        printf("-");
      }
      
    }else{
      for(int o=0; o<80; o++){
        printf("-");
      }
    }
		printf("\n");
	}
	printf("\033[1;0m");
  
  char rejouer;
  printf("\n↳ Do you want to play again ? [o/n]");
  scanf(" %c",&rejouer);
  if(rejouer=='o' || rejouer=='O'){
    main();
  }else{
    system("clear");
  }
}


/*
* Display a row, with cases represented by characters.
* The array must be a "DIMENSIONS" items array, so that each case contains 1 piece.
*/
void display_row(board game, piece *p, int ligne){
  
  char *drawings[5][5] = {{"    ● ● ●     ", //circle_solid
                           "   ● ● ● ●    ",
                           "  ● ● ● ● ●   ",
                           "   ● ● ● ●    ",
                           "    ● ● ●     "},
                          {"    ○ ○ ○     ", //circle_void
                           "   ○ ○ ○ ○    ",
                           "  ○ ○ ○ ○ ○   ",
                           "   ○ ○ ○ ○    ",
                           "    ○ ○ ○     "},
                          {"  ■ ■ ■ ■ ■   ", //square_solid
                           "  ■ ■ ■ ■ ■   ",
                           "  ■ ■ ■ ■ ■   ",
                           "  ■ ■ ■ ■ ■   ",
                           "  ■ ■ ■ ■ ■   "},
                          {"  □ □ □ □ □   ", //square_void
                           "  □ □ □ □ □   ",
                           "  □ □ □ □ □   ",
                           "  □ □ □ □ □   ",
                           "  □ □ □ □ □   "},
                          {" -----------  ", //no piece
                           " -----------  ",
                           " -----------  ",
                           " -----------  ",
                           " -----------  "}};


  int type[4];
  for(int l=0; l<5; l++){

      if(l==0){
        for(int size_info=0; size_info<DIMENSION; size_info++){
          if(ligne-1 ==0 && size_info==0){
            printf("\n   ║");
          }
          if(p[size_info]!=NULL){
            if(is_present_on_board(game,p[size_info])){
              if(piece_color(p[size_info])==BLUE){
                printf("\033[0;34m"); 
                if(piece_size(p[size_info])==TALL){
                  if(l==0 && size_info==DIMENSION-1){
                    printf("     TALL     ");
                    reset_color();
                    printf("║");
                  }else{
                    printf("     TALL     ");
                  }
                }else{
                  if(l==0 && size_info==DIMENSION-1){
                    printf("     SHORT    ");
                    reset_color();
                    printf("║");
                  }else{
                    printf("     SHORT    ");
                  }
                }
              }else{ 
                printf("\033[0;31m");
                if(piece_size(p[size_info])==TALL){
                  if(l==0 && size_info==DIMENSION-1){
                    printf("     TALL     ");
                    reset_color();
                    printf("║");
                  }else{
                    printf("     TALL     ");
                  }
                }else{
                  if(l==0 && size_info==DIMENSION-1){
                    printf("     SHORT    ");
                    reset_color();
                    printf("║");
                  }else{
                    printf("     SHORT    ");
                  }
                }
              }
              reset_color();
            }else{
              if(l==0 && size_info==DIMENSION-1){
                printf("              ║");
              }else{
                printf("              ");
              }
            }
          }else{
              if(l==0 && size_info==DIMENSION-1){
                printf("              ║");
              }else{
                printf("              ");
              }
          }
          reset_color();
        }
        printf("\n");
    }

    for(int c=0; c<DIMENSION; c++){
      if(c==0 && l!=0){
        printf("   ║");
      }
      if(c==0 && l==0){
        if(l+1>9){
          printf(" %d║",ligne);
        }else{
          printf("  %d║",ligne);
        }
      }


      type[0]=piece_color(p[c]);
      type[1]=piece_shape(p[c]);
      type[2]=piece_size(p[c]);
      type[3]=piece_top(p[c]);
      if(p[c]!=NULL){
        if(is_present_on_board(game,p[c])){
          if(type[0]==BLUE){
              printf("\033[0;34m"); 
          }else{
              printf("\033[0;31m");
          }

          if(type[1]==SQUARE){
            if(type[3]==SOLID){
              printf("%s",drawings[2][l]);
            }else{
              printf("%s",drawings[3][l]);          
            }
            if(c==DIMENSION-1){
              reset_color();
              printf("║");
            }
          }else{
            if(type[3]==SOLID){
              printf("%s",drawings[0][l]);
            }else{
              printf("%s",drawings[1][l]);          
            }
            if(c==DIMENSION-1){
              reset_color();
              printf("║");
            }
          }
        }else{
          printf("\033[0;37m");
          printf("%s",drawings[4][c]);
          if(c==DIMENSION-1){
            reset_color();
            printf("║");
          }
        }
      }else{
        printf("\033[0;37m");
        printf("%s",drawings[4][c]);
        if(c==DIMENSION-1){
          reset_color();
          printf("║");
        }
      }
      reset_color();
    }
    printf("\n");

  }
}


/*
* This function formats the display of the array.
*/
void display_board(board game, player pl){

  printf("     ");
  for(int i=97; i<DIMENSION+97; i++){
    printf("%c          ",i);
    if(i<DIMENSION+96){
      printf("   ");
    }
	}

  printf("\n   ╔");
  for(int i=0; i<DIMENSION; i++){
    if(i<DIMENSION-1){
      printf("══════════════");        
    }else{
      printf("══════════════╗");
    }
  }

	piece pieces_set[16];
	init_pieces(pieces_set);

	int index=0;
  piece pieces_ligne[DIMENSION];

	for(int l=0; l<DIMENSION; l++){

    for(int c=0; c<DIMENSION; c++){
      pieces_ligne[c] = get_piece(game,l,c);
      index++;
    }
    display_row(game, pieces_ligne, l+1);
    if(l<DIMENSION-1){
      printf("   ║");
    }
  }

  printf("   ╚");
  for(int i=0; i<DIMENSION; i++){
    if(i<DIMENSION-1){
      printf("══════════════");        
    }else{
      printf("══════════════╝");
    }
  }
}


/*
* Main function, and the first ran, that creates a board, ask
* for players to play, detects when a player wins.
*/
int main(){
	system("clear");
	srand(time(NULL));	
	board game = new_game();

	piece pieces_set[16];
	init_pieces(pieces_set);
  
	int piece_choisie=0;
	int x_choisi=0;
	char y_choisi;

	player current_player = random_draw();

	while(!has_winner(game)){
		display_board(game, current_player);
		display_pieces(game, pieces_set);
		display_current_player(current_player);
		
		printf("Which piece to give to the opponent ? ");
    
    while(scanf(" %d", &piece_choisie) != 1 || (piece_choisie>16 || piece_choisie<1)){
    	printf("\nERROR: Enter an Integer between 1 and 16.");
			display_current_player(current_player);
    	printf("Which piece to give to the opponent ? ");
      
      scanf(" %d", &piece_choisie);
      getchar();
    }


		while(is_present_on_board(game,pieces_set[piece_choisie-1])){
			printf("\nERROR: This case is already taken.");
			display_current_player(current_player);
			printf("Which piece to give to the opponent ? ");
			scanf("%d", &piece_choisie);
		}
		
		current_player = switch_player(current_player);
		
		ask_x(game,&x_choisi, current_player);
		ask_y(game,&y_choisi, current_player);
		while(!is_occupied(game,x_choisi,y_choisi)){
			printf("ERROR: This case is already taken.");
			ask_x(game,&x_choisi, current_player);
			ask_y(game,&y_choisi, current_player);
		}
		place_piece(game,x_choisi-1,y_choisi-97,pieces_set[piece_choisie-1]);
		system("clear");
	}
	
	destroy_game(game);
  win_display(current_player);
	return 0;
}
