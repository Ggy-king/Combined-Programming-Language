#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>
#include <time.h>

#define VERSION    "1.0"
#define MOVE_SPEED 300
#define MAP_WIDTH  45
#define MAP_HEIGHT 13
#define FOOD_SCORE 100
#define MOVE_SCORE 1
#define SPEED_UP   10
#define IS_WALL    0
#define IS_SPEEDUP 0

typedef struct
{
    int x;
    int y;
} COORD;

typedef struct
{
    COORD     body[MAP_WIDTH * MAP_HEIGHT]; //蛇身
    COORD     face;
    COORD     food;
    int       level; //蛇的长度
    int       score; //游戏积分
    int       speed;
    int       clock;
} SNAKE;

void snake_init(SNAKE**);
void snake_food(SNAKE*);
void snake_move(SNAKE*);
void snake_control(SNAKE*);
int  snake_isdie(SNAKE*);

void snake_init(SNAKE **snake)
{
    *snake = (SNAKE*)malloc(sizeof(SNAKE));
    
    if(*snake == NULL)
        exit(-1);
        
    memset(*snake, 0, sizeof(*snake));
    
    (*snake) -> body[0].x = (MAP_WIDTH + 2) / 2;
    (*snake) -> body[0].y = (MAP_HEIGHT + 2) / 2;
    (*snake) -> body[1].x = (*snake) -> body[0].x - 1;
    (*snake) -> body[1].y = (*snake) -> body[0].y;
    
    (*snake) -> face.x = 1;
    (*snake) -> face.y = 0;
    
    (*snake) -> level = 2;
    
    (*snake) -> speed = MOVE_SPEED;
    
    snake_food(*snake);
    
    return;
}

void snake_food(SNAKE *snake)
{
    srand(time(NULL));
    snake -> food.x = 1 + rand() % MAP_WIDTH;
    snake -> food.y = 1 + rand() % MAP_HEIGHT;
    
    return;
}

void snake_eat(SNAKE *snake)
{
    if(snake -> body[0].x == snake -> food.x && snake -> body[0].y == snake -> food.y)
    {
        snake -> score += FOOD_SCORE;
        snake -> level += 1;
        if(IS_SPEEDUP)
            snake -> speed -= SPEED_UP;
            if(snake->speed <= 50)
                snake -> speed = 50;
        snake_food(snake);
    }
}

int snake_isdie(SNAKE *snake)
{
    for(int i = 1; i < snake -> level; i ++)
    {
        if(IS_WALL)
        {
            if(snake -> body[0].x < 1 
            || snake -> body[0].x > MAP_WIDTH 
            || snake -> body[0].y < 1 
            || snake -> body[0].y > MAP_HEIGHT)
            {
                snake -> face.x = 0;
                snake -> face.y = 0;
                return 1;
            }
        }
        
        
        if(snake -> body[0].x == snake -> body[i].x && snake -> body[0].y == snake -> body[i].y)
        {
            //snake_split(snake);
            return 2;
        }
    }
    
    return 0;
}

void snake_move(SNAKE *snake)
{
    for(int i = snake -> level - 1; i > 0; i --)
    {
        snake -> body[i].x = snake -> body[i - 1].x;
        snake -> body[i].y = snake -> body[i - 1].y;
    }
    
    snake -> body[0].x += snake -> face.x;
    snake -> body[0].y += snake -> face.y;
    
    if(!IS_WALL)
    {
        if(snake -> body[0].x > MAP_WIDTH)
            snake -> body[0].x = 1;
        if(snake -> body[0].y > MAP_HEIGHT)
            snake -> body[0].y = 1;
        
        if(snake -> body[0].x < 1)
            snake -> body[0].x = MAP_WIDTH;
        if(snake -> body[0].y < 1)
            snake -> body[0].y = MAP_HEIGHT;
    }
    
    snake->score += MOVE_SCORE;;
    
    snake_eat(snake);
    
    return;
}

void snake_control(SNAKE *snake)
{
    char key = 0;
    while(_kbhit())
        key = _getch();
        
    switch(key)
    {
        case 'w':
            if(snake -> face.x != 0 && snake -> face.y != 1)
            {
                snake -> face.x =  0;
                snake -> face.y = -1;
            }
            break;
            
        case 's':
            if(snake -> face.x != 0 && snake -> face.y != -1)
            {
                snake -> face.x = 0;
                snake -> face.y = 1;
            }
            break;
            
        case 'a':
            if(snake -> face.x != 1 && snake -> face.y != 0)
            {
                snake -> face.x = -1;
                snake -> face.y =  0;
            }
            break;
            
        case 'd':
            if(snake -> face.x != -1 && snake -> face.y != 0)
            {
                snake -> face.x = 1;
                snake -> face.y = 0;
            }
            break;
    }
    
    return;
}
void game_show(SNAKE *snake)
{
    printf("这是贪吃蛇 VER%s\n", VERSION);
    for(int y = 0; y < MAP_HEIGHT + 2; y ++)
    {
        for(int x = 0; x < MAP_WIDTH + 2; x ++)
        {
            if(y > 0 && y < MAP_HEIGHT + 1)
            {
                if(x == 0 || x == MAP_WIDTH + 1)
                    putchar('#');
                else
                {
                    char pen = ' ';
                    for(int i = 0; i < snake -> level; i ++)
                    {
                        if(snake -> body[i].x == x && snake -> body[i].y == y)
                        {
                            if(i == 0)
                                pen = '@';
                            else
                                pen = '*';
                        }
                        if(snake -> food.x == x && snake -> food.y == y)
                        {
                            pen = '+';
                        }
                    }
                        
                    putchar(pen);
                }
            
            }
            else
            {  
                putchar('#');
            }
        }
        putchar(10);
    }
    if(snake_isdie(snake)) 
        printf("积分：%d 等级：%d 用时：%ds GAME OVER\n", 
        snake -> score, snake -> level - 1, snake->clock);
    else
        printf("积分：%d 等级：%d 用时：%ds\n", 
        snake -> score, snake -> level - 1, snake->clock);
    
    return;
}

int main()
{
    SNAKE *snake = NULL;
    
    snake_init(&snake);
    
    //隐藏控制台光标
    system("echo -e \"\033[?25l\"");
    
    time_t start = time(NULL);
    
    while(1)
    {
        system("clear");
        
        snake_control(snake);
        snake_move(snake);
        
        snake->clock = time(NULL) - start;
        
        game_show(snake);
        
        if(snake_isdie(snake))
        {
            if(snake != NULL)
                free(snake);
            break;
        }
        
        usleep(snake->speed * 1000);
    }
    
    return 0;
}

