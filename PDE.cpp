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
	/*while(t<=t_max)
	{
		for (int i=0; i<50; i++)
		{
			for(int j=0; j<50;j++)
			{				
								
				presente[i][j]=((nu*delta_t*(pasado[i+1][j]-2*pasado[i][j]+pasado[i-1][j]))+(nu*delta_t*(pasado[i][j+1]-2*pasado[i][j]+pasado[i][j-1])))+pasado[i][j];
				presente[0][j]=10;
				presente[49][j]=10;
				presente[i][0]=10;
				presente[i][49]=10;

				if(   (pow(i-25,2) + pow(j-25,2)) <=25)				
				{
					presente[i][j]= 100;
				}			
				
			}
		}
		for (int k=0; k<50; k++)
		{
			for (int l=0; l<50; l++)
			{
				pasado[k][l]=presente[k][l];
			}
		}
		k=k+1;
		t=t+delta_t;
	}
	ofstream myfile;
	myfile.open ("datos_fijo.dat");
	for (int k=0; k<50; k++)
	{
		for (int l=0; l<50; l++)
		{
					
			myfile<<presente[k][l]<<" ";
		}
		myfile<< std::endl;
	}
	myfile.close();*/
	t= 0+delta_t;
	float t_max2=10;
	while(t<=t_max2)
	{
		for (int i=0; i<50; i++)
		{
			for(int j=0; j<50;j++)
			{				
								
				presente[i][j]=((nu*delta_t*(pasado[i+1][j]-2*pasado[i][j]+pasado[i-1][j]))+(nu*delta_t*(pasado[i][j+1]-2*pasado[i][j]+pasado[i][j-1])))+pasado[i][j];
				presente[0][j]=pasado[1][j];
				presente[49][j]=pasado[48][j];
				presente[i][0]=pasado[i][1];
				presente[i][49]=pasado[i][48];

				if(   (pow(i-25,2) + pow(j-25,2)) <=25)				
				{
					presente[i][j]= 100;
				}			
				
			}
		}
		for (int k=0; k<50; k++)
		{
			for (int l=0; l<50; l++)
			{
				pasado[k][l]=presente[k][l];
			}
		}
		k=k+1;
		t=t+delta_t;
	}
	ofstream myfile2;
	myfile2.open ("datos_abierto.dat");
	for (int k=0; k<50; k++)
	{
		for (int l=0; l<50; l++)
		{
					
			myfile2<<presente[k][l]<<" ";
		}
		myfile2<< std::endl;
	}
	myfile2.close();

	
