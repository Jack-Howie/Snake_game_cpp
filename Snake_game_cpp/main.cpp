// blank main hopefully fixes merge problem
//#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

bool gameOver;
const int width = 20;
const int height = 20;
int headX, headY, fruitX, fruitY;
int score = 0;
enum edirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
edirection dir;

void Setup() {
    gameOver = false;
    //Snake doesn't move initially
    dir = STOP;
    //Setup snake start position
    headX = width / 2;
    headY = height / 2;
    //Create fruit positions random
    fruitX = rand() % width;
    fruitY = rand() % height;
}

void Draw() {
    system("cls");//clear screen
    for (int i = 0; i < width + 1; i++) {
        std::cout << "#";//top border
    }
    std::cout << "\n";

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0) {
                std::cout << "#";
            }
            if (i == headY and j == headX) {
                std::cout << "O";
                j++;
            }
            else if (i == fruitY and j == fruitX) {
                std::cout << "F";
                j++;
            }            
            if (j == width - 1) {
                std::cout << "#";
                std::cout << "\n";
            }
            else {
                std::cout << " ";
            }
        }
    }
    for (int i = 0; i < width + 1; i++) {
        std::cout << "#";
    }
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    switch (dir) {
    case STOP:
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    case LEFT:
        headX--;
        break;
    default:
        break;
    }
    if (headX == '#' or headY == '#') {
        gameOver = true;
    }
    if (headX == fruitX and headY == fruitY) {
        score++;
        fruitX = rand() % width;
        fruitY = rand() % height;
    }
}

int main(){
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();

    }
    //glfwTerminate();
    return 0;
}