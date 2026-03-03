#include<raylib.h>
#include<math.h>


#define WIDHT 900  
#define HEIGHT 600 
#define BRANCH_COLOR RAYWHITE 
#define STARTING_THICKNESS 20 
#define BRANCH_OF_ANGLE 20* DEG2RAD 

void DrawBranch(float x, float y , float length, float angle, float thickness){

	if (thickness <=1 ) {
		return ; // nothing to do 
			 // 
		}
	

	float end_x = x+sinf(angle) * length ; 
	float end_y  = y-cosf(angle) * length ; 


	Vector2 start = {x, y } ; 
	Vector2 end = {end_x, end_y } ; 
	
	float new_length  = length * 0.7 ; 
	float new_right_angle = angle+BRANCH_OF_ANGLE  ; 
	float new_left_angle= angle-BRANCH_OF_ANGLE  ; 
	float new_thickness = thickness*0.7 ; 

		
	DrawLineEx(start, end, thickness, BRANCH_COLOR); 
	
	DrawBranch(end_x, end_y ,new_length ,  new_right_angle, new_thickness ) ;  
	DrawBranch(end_x, end_y ,new_length , new_left_angle , new_thickness ) ;  

}


int main()
{

    InitWindow(WIDHT, HEIGHT, "Fractal Tree");
    
    SetTargetFPS(30);      
    while (!WindowShouldClose())   
    {
    
     BeginDrawing()  ; 
	ClearBackground(BLACK) ; 
	DrawBranch(WIDHT/2, HEIGHT-20 , 150, 0, STARTING_THICKNESS  ) ; 
     EndDrawing() ; 
    }

    CloseWindow();     

    return 0 ; 


} 
