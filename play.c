#include <stdio.h>

#define CHANGE_FLIP_RULE 32

const int points_matrix[8][8] = {{100000, 2 , 10000, 8000, 8000, 10000, 2  , 100000 },
                                 {2     , 1 , 5   , 5    , 5   , 5    , 1  , 2     },
                                 {1000  , 10, 300 , 100  , 100 , 300  , 5  , 10000 },
                                 {800   , 10, 100 , 500  , 500 , 100  , 5  , 8000  },
                                 {800   , 10, 100 , 500  , 500 , 100  , 5  , 8000  },
                                 {1000  , 10, 300 , 100  , 100 , 300  , 5  , 10000 },
                                 {2     , 1 , 5   , 5    , 5   , 5    ,  1 , 2    },
                                 {100000, 2 , 10000, 8000, 8000, 10000, 2  , 100000}
                               };

void check_left(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 0){
    for (int i = pos_x - 1; i > 0; i--){
      if (board[i][pos_y] != !player){
        return;
      } else if (board[i - 1][pos_y] == player){
        plays[pos_x][pos_y] += 1;
        return;
      }
    }
    return;
  } else {
    return;
  }
}

void check_right(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 7){
    int aux = 1;
    for (int i = pos_x + 1; i < 7; i++){
      if (board[i][pos_y] != !player){
        return;
      } else if (board[i + 1][pos_y] == player){
        plays[pos_x][pos_y] += aux;
        return;
      }
      aux += 1;
    }
    return;
  } else {
    return;
  }
}

void check_up(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_y != 0){
    int aux = 1;
    for (int i = pos_y - 1; i > 0; i--){
      if (board[pos_x][i] != !player){
        return;
      } else if (board[pos_x][i - 1] == player){
        plays[pos_x][pos_y] += aux;
        return;
      }
      aux += 1;
    }
    return;
  } else {
    return;
  }
}

void check_down(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_y != 7){
    int aux = 1;
    for (int i = pos_y + 1; i < 7; i++){
      if (board[pos_x][i] != !player){
        return;
      } else if (board[pos_x][i + 1] == player){
        plays[pos_x][pos_y] += aux;
        return;
      }
      aux += 1;
    }
    return;
  } else {
    return;
  }
}

void check_dig_left_up(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 0 || pos_y != 0){
    int aux = 1;
    for (int i = 1; i < 7; i++){
      if ((pos_x - i - 1 < 0) || (pos_y - i - 1 < 0)){
        return;
      }
      if (board[pos_x - i][pos_y - i] != !player){
        return;
      } else if (board[pos_x - i - 1][pos_y - i - 1] == player){
        plays[pos_x][pos_y] += aux;
        return;
      }
      aux += 1;
    }
    return;
  }
  else {
    return;
  }
}

void check_dig_left_down(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 0 || pos_y != 7){
    int aux = 1;
    for (int i = 1; i < 7; i++){
      if ((pos_x - i - 1 < 0) || (pos_y + i + 1 > 7)){
        return;
      }
      if (board[pos_x - i][pos_y + i] != !player){
        return;
      } else if (board[pos_x - i - 1][pos_y + i + 1] == player){
        plays[pos_x][pos_y] += aux * 5;
        return;
      }
       aux += 1;
    }
    return;
  }
  else {
    return;
  }
}

void check_dig_right_up(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 7 || pos_y != 7){
    int aux = 1;
    for (int i = 1; i < 7; i++){
      if ((pos_x + i + 1 > 7) || (pos_y + i + 1 > 7)){
        return;
      }
      if (board[pos_x + i][pos_y + i] != !player){
        return;
      } else if (board[pos_x + i + 1][pos_y + i + 1] == player){
        plays[pos_x][pos_y] += aux * 5;
        return;
      }
       aux += 1;
    }
    return;
  }
  else {
    return;
  }
}

void check_dig_right_down(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  if (pos_x != 7 || pos_y != 0){
    int aux = 1;
    for (int i = 1; i < 7; i++){
      if ((pos_x + i + 1 > 7) || (pos_y - i - 1 < 0)){
        return;
      }
      if (board[pos_x + i][pos_y - i] != !player){
        return;
      } else if (board[pos_x + i + 1][pos_y - i - 1] == player){
        plays[pos_x][pos_y] += aux;
        return;
      }
      aux += 1;
    }
    return;
  }
  else {
    return;
  }
}


void is_possible_play(int plays[8][8], int board[8][8], int pos_x, int pos_y, int player){
  check_right(plays, board, pos_x, pos_y, player);
  check_left(plays, board, pos_x, pos_y, player);
  check_up(plays, board, pos_x, pos_y, player);
  check_down(plays, board, pos_x, pos_y, player);
  check_dig_left_up(plays, board, pos_x, pos_y, player);
  check_dig_left_down(plays, board, pos_x, pos_y, player);
  check_dig_right_down(plays, board, pos_x, pos_y, player);
  check_dig_right_up(plays, board, pos_x, pos_y, player);
}

int find_time_game(int board[8][8]){
  int res = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (board[i][j] == -1){
        res += 1;
      }
    }
  }
  return res;
}

int find_max_play(int plays[8][8]){
  int aux = 0;
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if (plays[i][j] > aux){
        aux = plays[i][j];
      }
    }
  }
  return aux;
}
int find_best_play(int plays[8][8], int board[8][8], int *p_row, int *p_col) {
  int aux = 0;
  int time_game = find_time_game(board);
  int max = find_max_play(plays);
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      int position = points_matrix[i][j];
      if (time_game < CHANGE_FLIP_RULE && plays[i][j] != 0){
        plays[i][j] = max + 1 - plays[i][j];
      }
      plays[i][j] *= position;
      if (plays[i][j] > aux){
        aux = plays[i][j];
        *p_row = i;
        *p_col = j;
      }
    }
  }
  if (aux != 0){
    return 1;
  } else {
    return 0;
  }
}

int play(int player, int board[8][8], int *p_row, int *p_col) {
  int plays[8][8] = {{0}};
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      if(board[i][j] == -1){
        is_possible_play(plays, board, i, j, player);
      }
    }
  }
  if (find_best_play(plays, board, p_row, p_col)){
    return 1;
  } else {
    return 0;
  }
}
