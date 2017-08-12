#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <stdbool.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ENTER 13



#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
    const int column = 4;
    const int row = 4;    
    int table[4][4]={0,0} ;
    int reserve[4][4] = {0,0};
    void initReserve() {
        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                reserve[i][j] = table[i][j];
            }
        }
    }
    void changeTable(){
        for (int i = 0; i < column; ++i) {
            for (int j = 0; j < row; ++j) {
                table[i][j] = reserve[i][j];
            }
        }
    }
    bool changeArrayWithSum(int array_column[row]){
        bool changed = false;
        if(array_column[3]==array_column[2]) {
            array_column[3] *= 2;
            array_column[2] = array_column[1];
            array_column[1] = array_column[0];
            array_column[0] = 0;
            changed = true;
        }
        if(array_column[2] == array_column[1]){
            array_column[2] *= 2;
            array_column[1] = array_column[0];
            array_column[0] = 0;
            changed = true;
        }
        if(array_column[1] == array_column[0]){
            array_column[1] *= 2;
            array_column[0] = 0;
            changed = true;
        }
        return changed;
    }
    bool right(bool change){
        bool canChange = false;
        initReserve();
        int array_column[4] = {0};
        for (int i = 0; i < column; ++i) {
            int z = 3;
            for (int l = 0; l < 4; ++l)
                array_column[l] = 0;
            for (int j = 3; j > -1; --j) {
                if(reserve[i][j] != 0)
                    array_column[z--] = reserve[i][j];
                else
                    canChange = true;
            }
            if(changeArrayWithSum(array_column))
                canChange = true;
            for (int k = 0; k < 4; ++k)
                reserve[i][k] = array_column[k];
        }
        if(change)
            changeTable();
        return canChange;
    }
    bool left(bool change){
        bool canChange = false;
        initReserve();
        int array_column[4] = {0};
        for (int i = 0; i < column; ++i) {
            int z = 3;
            for (int l = 0; l < 4; ++l)
                array_column[l] = 0;
            for (int j = 0; j < 4; ++j) {
                if(reserve[i][j] != 0)
                    array_column[z--] = reserve[i][j];
                else
                    canChange = true;
            }
            if(changeArrayWithSum(array_column))
                canChange = true;
            for (int k = 0; k < 4 ; ++k)
                reserve[i][3-k] = array_column[k];
        }
        if(change)
            changeTable();
        return canChange;
    }
    bool up(bool change){
        bool canChange = false;
        initReserve();
        int array_column[4] = {0};
        for (int i = 0; i < row; ++i) {
            int z = 3;
            for (int l = 0; l < 4; ++l)
                array_column[l] = 0;
            for (int j = 0; j < 4; ++j) {
                if(reserve[j][i] != 0)
                    array_column[z--] = reserve[j][i];
                else
                    canChange = true;
            }
            if(changeArrayWithSum(array_column))
                canChange = true;
            for (int k = 0; k < 4 ; ++k)
                reserve[3-k][i] = array_column[k];
        }
        if(change)
            changeTable();
        return canChange;
    }
    bool down(bool change){
        bool canChange = false;
        initReserve();
        int array_column[4] = {0};
        for (int i = 0; i < row; ++i) {
            int z = 3;
            for (int l = 0; l < 4; ++l)
                array_column[l] = 0;
            for (int j = 3; j > -1; --j) {
                if(reserve[j][i] != 0)
                    array_column[z--] = reserve[j][i];
                else
                    canChange = true;
            }
            if(changeArrayWithSum(array_column))
                canChange = true;
            for (int k = 0; k < 4; ++k)
                reserve[k][i] = array_column[k];
        }
        if(change)
            changeTable();
        return canChange;
    }
        void print_table(){
        system("cls");
        for(int j=0; j < row; j++)//Just for the first row of the biggest square
        {
            printf(" ");//because here we shouldn't print vertical ( | )
            {
                printf(WHITE   ,"_____", RESET);

            }
        }
        printf(" ");
        printf("\n");

        for(int i=0; i < column; i++)
        {
            for(int j=0; j < row; j++)//(first for instruction); for the second row of the square
            {
                    printf(WHITE , "|",  RESET);

                printf(GREEN  , " ", RESET);
                printf(GREEN  , " ", RESET);
                printf(GREEN  , " ", RESET);
                printf(GREEN  , " ", RESET);
                printf(GREEN  , " ", RESET);
            }
                printf(WHITE , "|" , RESET);
            printf("\n");

            for(int j=0; j < row; j++)//(second for instruction); for the third row of the square
            {
                printf(WHITE  "|"  RESET);
                int num = table[i][j];
                num = table[i][j];
                int pow = 0;
                while(num/2 >= 1) {
                    pow++;
                    num/=2;
                }
                num = 1;
                switch(pow){
                    case 1 :
                        printf(GREEN  "   2" RESET);
                        break;
                    case 2 :
                        printf(RED  "   4" RESET);
                        break;
                    case 3 :
                        printf(YELLOW  "   8" RESET);
                        break;
                    case 4 :
                        printf(BLUE  "  16" RESET);
                        break;
                    case 5 :
                        printf(WHITE  "  32" RESET);
                        break;
                    case 6 :
                        printf(CYAN  "  64" RESET);
                        break;
                    case 7 :
                        printf(MAGENTA  " 128" RESET);
                        break;
                    case 8 :
                        printf(BOLDBLUE  " 256" RESET);
                        break;
                    case 9 :
                        printf(BOLDGREEN  " 512" RESET);
                        break;
                    case 10 :
                        printf(BOLDYELLOW  "1024" RESET);
                        break;
                    case 11 :
                        printf(BOLDRED  "2048" RESET);
                        break;
                    default:
                        printf(BOLDRED  "    " RESET);
                }
                printf(GREEN   " " RESET);
            }

                printf(WHITE  "|"  RESET);

            printf("\n");

            for(int j=0; j < row; j++)//(third for instruction); for the forth row of the square
            {

                    printf(WHITE  "|"  RESET);

                    printf(WHITE   "_" RESET);
                    printf(WHITE   "_" RESET);
                    printf(WHITE   "_" RESET);
                    printf(WHITE   "_" RESET);
                    printf(WHITE   "_" RESET);

            }
                printf(WHITE "|" RESET);

            printf("\n");
        }
    }

        void initTable() {
            srand(time(0));
            int column;
            int row;
            while(true) {
                column = rand() % 4;
                row = rand() % 4;
                if(table[column][row]==0){
                    table[column][row] = 2;
                    break;
                }
            }
        }

        void play() {
            char direction = getch();
            while (direction != UP && direction != DOWN && direction != LEFT && direction != RIGHT)
                direction = getch();

            if(direction == RIGHT) {
                if(right(true))
                    initTable();
            }

            if(direction == LEFT) {
                if(left(true))
                    initTable();
            }

            if(direction == UP) {
                if(up(true))
                    initTable();
            }

            if(direction == DOWN) {
                if(down(true))
                    initTable();
            }
        }

        bool check_losing() {
            return !(right(false) || down(false) || up(false) || left(false));
        }

int main(int argc, const char * argv[]){
    // insert code here...
    system("cls");
    table[1][3] = 2;
    initTable();
    bool exit=false;
    bool lose=false;
    print_table();
    while(!exit)
    {
        play();
        lose = check_losing();

        if(lose){
            printf("\nYou lose !!!\npress any key to exit from game.\nif you want try again press Enter.\n");
            char input = getch();
            if(input == ENTER) {
                lose = false;
                exit = false;
                for (int i = 0; i < column; ++i) {
                    for (int j = 0; j < row; ++j) {
                        table[i][j] = 0;
                    }
                }
                table[2][2] = 2;
                initTable();
                print_table();
            }
            else
                exit = true;
        }
        else{
            print_table();
        }

    }
    return 0;
}

