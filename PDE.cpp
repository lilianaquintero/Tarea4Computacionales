#include<iostream>
#include <cmath>
#include<fstream>
using namespace std;
#define PI 3.14159
int main()
{
	//condiciones iniciales
	float pasado[50][50];
	for (int i=0; i<50; i++)
	{
		for (int j=0; j<50; j++)
		{
			if(   (((i-25)*(i-25)) + ((j-25)*(j-25))) < 25 or (((i-25)*(i-25)) + ((j-25)*(j-25))) ==25)				
			{
				pasado[i][j]= 100;
			}
			else
			{
				pasado[i][j]=10;
			}
			
		}
		
	}
	//pasar datos iniciales a un archivo
	ofstream file;
	file.open("Inicial.dat");
	for (int k=0; k<50; k++)
	{
		for (int l=0; l<50; l++)
		{
			pasado[0][l]=10;
			pasado[49][l]=10;
			pasado[k][0]=10;
			pasado[k][49]=10;
			std::cout<<pasado[k][l]<<" ";			
			file<<pasado[k][l]<<" ";
		}
	
		file<< std::endl;
	}
	file.close();

	// datos- fijo

	float delta_x= 1;
	float delta_y=1;
	float delta_t=0.8;
	float nu= 1.62/(820*2.71);
	float t_max=500000;
	float t=0;
	float presente[50][50];
	int k1=0;
	t= t+delta_t;
	
	while(t<=t_max)
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

				if(   (pow(i-25,2) + pow(j-25,2)) <25 or (pow(i-25,2) + pow(j-25,2)) ==25)				
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
		
		if (k1==40000)
		{
			ofstream fijo;
			fijo.open("datos_int1_fijo.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					fijo<<presente[k][l]<<" ";
				}
				fijo<< std::endl;
			}
			fijo.close();
		}

		if (k1==90000)
		{
			ofstream fijo2;
			fijo2.open("datos_int2_fijo.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					fijo2<<presente[k][l]<<" ";
				}
				fijo2<< std::endl;
			}
			fijo2.close();
		}
		if(k1==50000 or k1==100000 or k1==150000 or k1==200000 or k1==250000 or k1==300000 or k1==350000)
		{
			ofstream fijo22;
			fijo22.open("datosPromedioFijo.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					fijo22<<presente[k][l]<<" ";
				}
				fijo22<< std::endl;
			}
			fijo22.close();
			ofstream fijo222;
			fijo222.open("tiempoFijo.dat");
			fijo222<<t<<std::endl;
			fijo222.close();
			
		}
		k1=k1+1;
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
	myfile.close();

 	//datos Abierto
	int k2=0;
	t= 0+delta_t;
	float t_max2=500000;
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

				if(   (pow(i-25,2) + pow(j-25,2)) <25 or (pow(i-25,2) + pow(j-25,2)) == 25)				
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
		
		if (k2==1000)
		{
			ofstream ab;
			ab.open("datos_int1_abiero.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					ab<<presente[k][l]<<" ";
				}
				ab<< std::endl;
			}
			ab.close();
		}

		if (k2==200000)
		{
			ofstream ab2;
			ab2.open("datos_int2_abierto.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					ab2<<presente[k][l]<<" ";
				}
				ab2<< std::endl;
			}
			ab2.close();
		}
		if(k2%50000==0)
		{
			ofstream ab22;
			ab22.open("datosPromedioAbierto.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					ab22<<presente[k][l]<<" ";
				}
				ab22<< std::endl;
			}
			ab22.close();
			ofstream ab222;
			ab222.open("tiempoAbierto.dat");
			ab222<<t<<std::endl;
			ab222.close();
			
		}
		k2=k2+1;
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


	//datos periodico
	int k3=0;
	t= 0+delta_t;
	float t_max3=150000;
	while(t<=t_max3)
	{
		for (int i=0; i<50; i++)
		{
			for(int j=0; j<50;j++)
			{				
								
				presente[i][j]=((nu*delta_t*(pasado[i+1][j]-2*pasado[i][j]+pasado[i-1][j]))+(nu*delta_t*(pasado[i][j+1]-2*pasado[i][j]+pasado[i][j-1])))+pasado[i][j];
				presente[0][j]=pasado[48][j];
				presente[49][j]=pasado[1][j];
				presente[i][0]=pasado[i][48];
				presente[i][49]=pasado[i][1];

				if(   (pow(i-25,2) + pow(j-25,2)) <25 or (pow(i-25,2) + pow(j-25,2)) ==25)				
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
		
		if (k3==5000)
		{
			ofstream p;
			p.open("datos_int1_periodico.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					p<<presente[k][l]<<" ";
				}
				p<< std::endl;
			}
			p.close();
		}

		if (k3==100000)
		{
			ofstream p2;
			p2.open("datos_int2_periodico.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					p2<<presente[k][l]<<" ";
				}
				p2<< std::endl;
			}
			p2.close();
		}
		if(k3%50000==0)
		{
			ofstream p22;
			p22.open("datosPromedioPeriodico.dat");
			for (int k=0; k<50; k++)
			{
				for (int l=0; l<50; l++)
				{
							
					p22<<presente[k][l]<<" ";
				}
				p22<< std::endl;
			}
			p22.close();
			ofstream p222;
			p222.open("tiempoPeriodico.dat");
			p222<<t<<std::endl;
			p222.close();

			
		}
		k3=k3+1;
		t=t+delta_t;	

	}
	ofstream myfile3;
	myfile3.open ("datos_periodico.dat");
	for (int k=0; k<50; k++)
	{
		for (int l=0; l<50; l++)
		{
					
			myfile3<<presente[k][l]<<" ";
		}
		myfile3<< std::endl;
	}
	myfile3.close();
	return 0;
}
