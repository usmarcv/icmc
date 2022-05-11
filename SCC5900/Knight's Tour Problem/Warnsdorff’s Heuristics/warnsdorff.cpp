#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

using namespace std;

#define N 8


/*maintain the knight's position*/
static int move_cx[N]={1,1,2,2,-1,-1,-2,-2};
static int move_cy[N]={2,-2,1,-1,2,-2,1,-1};

/*Check whether move location is valid to chessboard*/
int is_valid_move(int x, int y){
    if ((x >= 0 && y >= 0) && (x < N && y < N))
    {
        return 1;
    }
    return 0;
}

/*Checks whether a square is empty or not */
int is_empty(int out[], int x, int y){

    if ((is_valid_move(x, y)) && (out[y * N + x] < 0)){
        return 1;
    }
    return 0;
}

/*Returns the number of empty squares */
int getcount(int out[], int x, int y){
    int i, count = 0;
    for (i = 0; i < N; ++i)
    {
        if (is_empty(out, (x + move_cx[i]), (y + move_cy[i])))
        {
            count++;
        }
    }
    return count;
}

/* Calculates the minimum degree and assigns the counter to that square */
int move_process(int out[], int * x, int * y){
    int start, count, i, flag = -1, c, min = (N + 1), nx, ny;
    start = rand() % N;
    for (count = 0; count < N; ++count)
    {
        i = (start + count) % N;
        nx = * x + move_cx[i];
        ny = * y + move_cy[i];
        if ((is_empty(out, nx, ny)))
        {
            c = getcount(out, nx, ny);
            if (c < min)
            {
                flag = i;
                min = c;
            }
        }
    }
    if (min == N + 1)
    {
        return 0;
    }
    nx = * x + move_cx[flag];
    ny = * y + move_cy[flag];
    //Assigns the counter
    out[ny * N + nx] = out[( * y) * N + ( * x)] + 1;* x = nx;* y = ny;
    return 1;
}

/* Displays the chessboard with all the legal knight's moves */
void print_result(int out[]){
    int i, j;
    for (i = 0; i < N; ++i)
    {
        for (j = 0; j < N; ++j)
        {
            printf("%d\t", out[j * N + i]);
        }
        printf("\n");
    }
}

/* Checks its neighbouring sqaures */
int neighbour(int x, int y, int start_x, int start_y){
    int i;
    for (i = 0; i < N; ++i)
    {
        if (((x + move_cx[i]) == start_x) && ((y + move_cy[i]) == start_y))
        {
            return 1;
        }
    }
    return 0;
}

//Set default moves
void set_default(int out[]){
    //fill the chess board matrix with -1's
    for (int i = 0; i < N * N; ++i)
    {
        out[i] = -1;
    }
}

/* Display the legal moves using warnsdorff's heuristics */
int generate(int out[]){
    set_default(out);
    int i, x, y, sx, sy;
    //Get a random starting location
    sx = rand() % N;
    sy = rand() % N;
    x = sx;
    y = sy;
    //Set the value of first moves
    out[y * N + x] = 1;
    for (i = 0; i < (N * N) - 1; ++i)
    {
        if (move_process(out, & x, & y) == 0)
        {
            return 0;
        }
    }
    if (neighbour(x, y, sx, sy) == 0)
    {
        return 0;
    }
    //When get a valid solution 
    print_result(out);
    return 1;
}

int main(){
 
 		srand(time(NULL));
    //used to store result
    int out[N * N];
    while (!generate(out));
 
    return 0;
}

