#include<iostream>
#include <cmath>
#include<fstream>
using namespace std;
#define PI 3.14159
int main()
{
	float pasado[50][50];
	for (int i=0; i<50; i++)
	{
		for (int j=0; j<50; j++)
		{
			if(   (((i-25)*(i-25)) + ((j-25)*(j-25))) <= 25)				
			{
				pasado[i][j]= 100;
			}
			else
			{
				pasado[i][j]=0;
			}
			
		}
		
	}
	

	for (int k=0; k<50; k++)
	{
		for (int l=0; l<50; l++)
		{
			pasado[0][l]=10;
			pasado[49][l]=10;
			pasado[k][0]=10;
			pasado[k][49]=10;			
			std::cout<<pasado[k][l]<<" ";
		}
		std::cout << std::endl;
	}

	float delta_x= 1;
	float delta_y=1;
	float delta_t=0.5;
	float nu= 1.62/(820*2.71);
	float t_max=150000;
	float t=0;
	float presente[50][50];
	int k=0;
	t= t+delta_t;
	
