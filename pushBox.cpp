#include <iostream>
#include <cstring>
using namespace std;

int mat[100][100];
int old_mat[100][100];
int col;
int row;
int ntest;

int old_playerX, old_playerY;
int old_boxX, old_boxY;


int playerX, playerY;
int boxX, boxY;
int dstX, dstY;


void up();
void down();
void left();
void right();
void init();
void solve();
void recover();

int main()
{
    init();
    solve();
}

void init()
{
    cout<<"initializing"<<endl;
    cin>>col>>row>>ntest;
    for(int i = 0; i < row; ++i)
    {
        string tmp = "";
        cin>>tmp;
        
        for(int j = 0; j < tmp.size(); ++j)
        {
            mat[i][j] = tmp[j] - '0';
            old_mat[i][j] = mat[i][j];
            
            if(mat[i][j] == 1)
            {
                playerX = i;
                playerY = j;
                
                old_playerX = i;
                old_playerY = j;
            }
            else if(mat[i][j] == 3)
            {
                boxX = i;
                boxY = j;
                
                old_boxX = i;
                old_boxY = j;
            }
            else if(mat[i][j] == 2)
            {
                dstX = i;
                dstY = j;
            }
        }
    }
}

void recover()
{
    playerX = old_playerX;
    playerY = old_playerY;
    boxX = old_boxX;
    boxY = old_boxY;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            mat[i][j] = old_mat[i][j];
        }
    }
}


void solve()
{

    //cout<<endl<<"solve begin!"<<endl;
    int steps;
    string operations;
    for(int i = 0; i < ntest; ++i)
    {
        cin>>steps>>operations;
        for(int j = 0; j < steps; ++j)
        {
            if(operations[j] == 'r')
            {
                //cout<<"right"<<endl;
                right();
                //cout<<"playerX = "<<playerX<<endl;
                //cout<<"playerY = "<<playerY<<endl;
            }
            else if(operations[j] == 'l')
            {
                //cout<<"left"<<endl;
                left();
                //cout<<"playerX = "<<playerX<<endl;
                //cout<<"playerY = "<<playerY<<endl;
            }
            else if(operations[j] == 'u')
            {
                //cout<<"up"<<endl;
                up();
                //cout<<"playerX = "<<playerX<<endl;
                //cout<<"playerY = "<<playerY<<endl;
            }
            else if(operations[j] == 'd')
            {
                //cout<<"down"<<endl;
                //cout<<"playerX = "<<playerX<<endl;
                //cout<<"playerY = "<<playerY<<endl;
                down();
                //cout<<"playerX = "<<playerX<<endl;
                //cout<<"playerY = "<<playerY<<endl;
            }  
        }
        if (boxX == dstX && boxY == dstY)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
        recover();
    }
    
}

void right()
{
    int newPlayerX = playerX;
    int newPlayerY = playerY + 1;
    
    if(newPlayerX > col-1 || newPlayerY > row-1 ||
        newPlayerX < 0 || newPlayerY < 0 ||
        mat[newPlayerX][newPlayerY] == 4)
    {
        return;
    }
    else if(mat[newPlayerX][newPlayerY] == 3 && !(boxX == dstX && boxY == dstY))
    {
        int newBoxX = boxX;
        int newBoxY = boxY + 1;
        if(newBoxX > col-1 || newBoxY > row-1 ||
        newBoxX < 0 || newBoxY < 0 || 
        mat[newBoxX][newBoxY] == 4)
        {
            return;
        }
        else 
        {
            mat[playerX][playerY] = 0;
            mat[boxX][boxY] = 0;
            
            playerX = newPlayerX;
            playerY = newPlayerY;
            boxX = newBoxX;
            boxY = newBoxY;
            
            // if (boxX == dstX && boxY == dstY)
            // {
            //     cout<<"YES"<<endl;
            // }
            
            mat[playerX][playerY] = 1;
            mat[boxX][boxY] = 3;
        }
    }

    else if(mat[newPlayerX][newPlayerY] == 0 || 
            mat[newPlayerX][newPlayerY] == 2)
    {
        mat[playerX][playerY] = 0;
        playerX = newPlayerX;
        playerY = newPlayerY;
        mat[playerX][playerY] = 1;
    }
    
}

void left()
{
    int newPlayerX = playerX;
    int newPlayerY = playerY - 1;
    
    if(newPlayerX > col-1 || newPlayerY > row-1 ||
        newPlayerX < 0 || newPlayerY < 0 ||
        mat[newPlayerX][newPlayerY] == 4)
    {
        return;
    }
    else if(mat[newPlayerX][newPlayerY] == 3 && !(boxX == dstX && boxY == dstY))
    {
        int newBoxX = boxX;
        int newBoxY = boxY - 1;
        if(newBoxX > col-1 || newBoxY > row-1 ||
        newBoxX < 0 || newBoxY < 0 || 
        mat[newBoxX][newBoxY] == 4)
        {
            return;
        }
        else 
        {
            mat[playerX][playerY] = 0;
            mat[boxX][boxY] = 0;
            
            playerX = newPlayerX;
            playerY = newPlayerY;
            boxX = newBoxX;
            boxY = newBoxY;
            
            // if (boxX == dstX && boxY == dstY)
            // {
            //     cout<<"YES"<<endl;
            // }
            
        
            mat[playerX][playerY] = 1;
            mat[boxX][boxY] = 3;
            
        }
    }
    else if(mat[newPlayerX][newPlayerY] == 0 || 
            mat[newPlayerX][newPlayerY] == 2)
    {
        mat[playerX][playerY] = 0;
        playerX = newPlayerX;
        playerY = newPlayerY;
        mat[playerX][playerY] = 1;
    }
    
}

void up()
{
    int newPlayerX = playerX - 1;
    int newPlayerY = playerY;
    
    if(newPlayerX > col-1 || newPlayerY > row-1 ||
        newPlayerX < 0 || newPlayerY < 0 ||
        mat[newPlayerX][newPlayerY] == 4)
    {
        return;
    }
    else if(mat[newPlayerX][newPlayerY] == 3 && !(boxX == dstX && boxY == dstY))
    {
        int newBoxX = boxX - 1;
        int newBoxY = boxY;
        if(newBoxX > col-1 || newBoxY > row-1 ||
        newBoxX < 0 || newBoxY < 0 || 
        mat[newBoxX][newBoxY] == 4)
        {
            return;
        }
        else 
        {
            mat[playerX][playerY] = 0;
            mat[boxX][boxY] = 0;
            
            playerX = newPlayerX;
            playerY = newPlayerY;
            boxX = newBoxX;
            boxY = newBoxY;
            
            // if (boxX == dstX && boxY == dstY)
            // {
            //     cout<<"YES"<<endl;
            // }
            
        
            mat[playerX][playerY] = 1;
            mat[boxX][boxY] = 3;
            
        }
    }
    else if(mat[newPlayerX][newPlayerY] == 0 || 
            mat[newPlayerX][newPlayerY] == 2)
    {
        mat[playerX][playerY] = 0;
        playerX = newPlayerX;
        playerY = newPlayerY;
        mat[playerX][playerY] = 1;
    }
    
}

void down()
{
    int newPlayerX = playerX + 1;
    int newPlayerY = playerY;
    
    if(newPlayerX > col-1 || newPlayerY > row-1 ||
        newPlayerX < 0 || newPlayerY < 0 ||
        mat[newPlayerX][newPlayerY] == 4)
    {
        return;
    }
    else if(mat[newPlayerX][newPlayerY] == 3 && !(boxX == dstX && boxY == dstY))
    {
        //cout<<"@@"<<endl;  
        int newBoxX = boxX + 1;
        int newBoxY = boxY;
        if(newBoxX > col-1 || newBoxY > row-1 ||
        newBoxX < 0 || newBoxY < 0 || 
        mat[newBoxX][newBoxY] == 4)
        {
            //cout<<"@@"<<endl;
            return;
        }
        else 
        {
            mat[playerX][playerY] = 0;
            mat[boxX][boxY] = 0;
            
            playerX = newPlayerX;
            playerY = newPlayerY;
            boxX = newBoxX;
            boxY = newBoxY;
            
            // if (boxX == dstX && boxY == dstY)
            // {
            //     cout<<"YES"<<endl;
            // }
            
        
            mat[playerX][playerY] = 1;
            mat[boxX][boxY] = 3;
            
        }
    }
    else if(mat[newPlayerX][newPlayerY] == 0 || 
            mat[newPlayerX][newPlayerY] == 2)
    {
        mat[playerX][playerY] = 0;
        playerX = newPlayerX;
        playerY = newPlayerY;
        mat[playerX][playerY] = 1;
    }
    
}



