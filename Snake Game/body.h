#include <graphics.h>
#include <iostream>
using namespace std;

enum DIRECTION {LEFT, RIGHT, UP, DOWN};

struct Node{
	int x;
	int y;
	int direction;
	Node* next = NULL;
	Node* prev = NULL;

};

class Snake{
private:
	Node* head = NULL;
	int x_dis = 30; //20
	int y_dis = 30; //20
	int length = 0;

public:
	Snake(){
		Node* newNode = new Node;
		newNode->x = 700;
		newNode->y = 350;
		newNode->direction = RIGHT;

		head = newNode;
	}

	// Methods
	void drawSnake();
	void growSnake();
	void changeDir(int arg);
	void moveSnake(int food_count);
	float getPosX();
	float getPosY();
	bool isCollision();


};


// draw the body of the snake
void Snake::drawSnake(){

	Node* temp = head;
	
	if (temp->next == NULL){
		setcolor(BLACK);
		rectangle(temp->x, temp->y, temp->x+30, temp->y+30); //20
		setfillstyle(SOLID_FILL, LIGHTRED);
		floodfill(temp->x+10, temp->y+10, BLACK);
	}

	while (temp->next != NULL){ 
		setcolor(BLACK);
		rectangle(temp->x, temp->y, temp->x+30, temp->y+30); //20

		if (temp == head)
			setfillstyle(SOLID_FILL, LIGHTRED);

		else
			setfillstyle(SOLID_FILL, RED);

		floodfill(temp->x+10, temp->y+10, BLACK);

		temp = temp->next;
	}

	while(temp->prev != NULL){
		temp->x = temp->prev->x;
		temp->y = temp->prev->y;

		temp = temp->prev;
	}

};







// move snake
void Snake::moveSnake(int food_count){
	Node* temp = head;

	rectangle(head->x, head->y, head->x+30, head->y+30); //20
	if (head->direction == LEFT || head->direction == RIGHT)
		head->x += x_dis;
	if (head->direction == DOWN || head->direction == UP)
	head->y += y_dis;

	if (length <= food_count){
		growSnake();
	}

}



// increases the length of the snake
void Snake::growSnake()
{
    length++;

    Node* temp = head;
    Node* newNode = new Node;
	

    newNode->x =  temp->x;
    newNode->y =  temp->y;
    
    while(temp->next != NULL){
        temp = temp->next;
    }
    
    
    temp->next = newNode;
    newNode->prev = temp;

}


// change the direction of snake head // 20
void Snake::changeDir(int newDir)
{
	bool oppDir = (newDir==LEFT && head->direction==RIGHT) || (newDir==RIGHT && head->direction==LEFT) ||
					(newDir==UP && head->direction==DOWN) || (newDir==DOWN && head->direction==UP);

	if (oppDir)
		return;

    if (newDir == LEFT){
    	if (head->direction != LEFT){
    		x_dis = -30;
    		head->direction = newDir;
    	}
    }

    else if (newDir == UP){
    	if (head->direction != UP){
    		y_dis = -30;
    		head->direction = newDir;
    	}
    }


    else if (newDir == RIGHT){
    	if (head->direction != RIGHT){
    		x_dis = 30;
    		head->direction = newDir;
    	}
    }

    else if (newDir == DOWN){
    	if (head->direction != DOWN){
    		y_dis = 30;
    		head->direction = newDir;
    	}
    	
    }

}


// Return the x and y coordinates
float Snake::getPosX(){
	return head->x;
}

float Snake::getPosY(){
	return head->y;
}


// Collision between head and body
bool Snake::isCollision(){

	Node* temp = head;
	while (temp->next->next != NULL){
		if ((head->x == temp->next->x) && (head->y == temp->next->y)){
			return true;
		}

		temp = temp->next;
	}

	return false;
}
