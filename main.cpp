#include <iostream>
#include <fstream>
#include <array>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Point
{
    int x, y;
};

int player;
const int SIZE = 8;
array<std::array<int, SIZE>, SIZE> board;
vector<Point> next_valid_spots;

void read_board()
{
    cin >> player;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cin >> board[i][j];
        }
    }
}

void read_valid_spots()
{
    int n_valid_spots;
    cin >> n_valid_spots;
    int x, y;
    for (int i = 0; i < n_valid_spots; i++)
    {
        cin >> x >> y;
        next_valid_spots.push_back({x, y});
    }
}

Point state_value()
{
    int n_valid_spots = next_valid_spots.size();
    for(int i=0;i<n_valid_spots;i++)
    {
        Point cur = next_valid_spots[i];
        //cout << board[2][3] << endl;
        if(board[cur.x][cur.y + 1] == 1 && board[cur.x - 1][cur.y - 1] == 2 && board[cur.x][cur.y + 2] == 2)//左 上跟右
        {
            //board[cur.x][cur.y] = 2;
            //board[cur.x + 1][cur.y] = 2;
            return cur;
        }
        else if(board[cur.x][cur.y + 1] == 1 && board[cur.x - 1][cur.y - 1] == 2 && board[cur.x + 1][cur.y + 1] == 2)//左 上跟下
        {
            return cur;
        }
        else if(board[cur.x][cur.y + 1] == 1 && board[cur.x + 1][cur.y + 1] == 2 && board[cur.x][cur.y + 2] == 2)//左 右跟下
        {
            return cur;
        }
        else if(board[cur.x + 1][cur.y] == 1 && board[cur.x + 1][cur.y - 1] == 2 && board[cur.x + 1][cur.y + 1] == 2)//上 左跟右
        {
            return cur;
        }
        else if(board[cur.x + 1][cur.y] == 1 && board[cur.x + 2][cur.y] == 2 && board[cur.x + 1][cur.y + 1] == 2)//上 下跟右
        {
            return cur;
        }
        else if(board[cur.x + 1][cur.y] == 1 && board[cur.x + 2][cur.y] == 2 && board[cur.x + 1][cur.y - 1] == 2)//上 下跟左
        {
            return cur;
        }
        else if(board[cur.x][cur.y - 1] == 1 && board[cur.x - 1][cur.y - 1] == 2 && board[cur.x][cur.y - 2] == 2)//右 上跟左
        {
            return cur;
        }
        else if(board[cur.x][cur.y - 1] == 1 && board[cur.x - 1][cur.y - 1] == 2 && board[cur.x + 1][cur.y - 1] == 2)//右 上跟下
        {
            return cur;
        }
        else if(board[cur.x][cur.y - 1] == 1 && board[cur.x + 1][cur.y - 1] == 2 && board[cur.x][cur.y - 2] == 2)//右 下跟左
        {
            return cur;
        }
        else if(board[cur.x - 1][cur.y] == 1 && board[cur.x + 1][cur.y + 1] == 2 && board[cur.x + 2][cur.y] == 2)//下 左跟上
        {
            return cur;
        }
        else if(board[cur.x - 1][cur.y] == 1 && board[cur.x - 1][cur.y - 1] == 2 && board[cur.x - 1][cur.y + 1] == 2)//下 左跟右
        {
            return cur;
        }
        else if(board[cur.x - 1][cur.y] == 1 && board[cur.x - 1][cur.y + 1] == 2 && board[cur.x + 2][cur.y] == 2)//下 右跟上
        {
            return cur;
        }
    }
    return {0,0};
}

void write_valid_spot()
{
    srand(time(NULL));
    // Choose random spot. (Not random uniform here)
    Point p = state_value();
    //int index = (rand() % n_valid_spots);
    //Point p = next_valid_spots[index];
    // Remember to flush the output to ensure the last action is written to file.
    cout << p.x << " " << p.y << endl;
    cout.flush();
}

void printboard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(int, char** argv)
{
    //std::ifstream fin(argv[1]);
    //std::ofstream fout(argv[2]);
    read_board();
    read_valid_spots();
    state_value();
    write_valid_spot();
    //printboard();
    //fin.close();
    //fout.close();
    return 0;
}
