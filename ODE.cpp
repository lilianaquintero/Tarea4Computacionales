#include <iostream>
#include <cmath>
float der_x(float vxx);
float der_y(float vyy);
float der_vx(float vxx, float vv);
float der_vy(float vyy, float vv);
float der_v(float vv);

int main()
{
	float h=0.0001;
	//int i=2;
	int puntos=1000;
	float seno=0.85;
	float coseno=0.85;
	float t[puntos];
	float x[puntos];
	float y[puntos];
	float vx[puntos];
	float vy[puntos];
	float v[puntos];
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;
	t[1]= t[0]+h;
	x[1]= x[0]+h*der_x(vx[0]);
	y[1]= y[0]+h*der_y(vy[0]);
	vx[1]=vx[0]+h*der_vx(vx[0], v[0]);
	vy[1]=vy[0]+h*der_vy(vy[0], v[0]);
	float bla= (vx[1]*vx[1])+(vy[1]*vy[1]);
	v[1]=pow(bla,0.5);
	//std::cout<<t[0]<<" "<<x[0]<<" "<<v[0]<<std::endl;
	//std::cout<<t[1]<<" "<<x[1]<<" "<<v[1]<<std::endl;
	//std::cout<<v[1]<<" "<<v[2]<<" "<<vx[0]<<" "<<vy[0]<<std::endl;	
	for (int i =2; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		x[i]= x[i-2] + h*2*der_x(vx[i-1]);
		y[i]= y[i-2] + h*2*der_y(vy[i-1]);
		vx[i]= vx[i-2] + h*2*der_vx(vx[i-1], v[i-1]);
		vy[i]= vy[i-2] + h*2*der_vy(vy[i-1], v[i-1]);
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		std::cout<<x[i]<<" "<<y[i]<<" "<<vy[i]<<std::endl;
	}
	return 0;
}

float der_vy(float vyy, float vv)
{
	return -10.0-(abs(vv)*vyy);
}

float der_vx(float vxx, float vv)
{
	return -10.0-vxx*abs(vv);
}

float der_x(float vxx)
{
	return vxx;
}
float der_y(float vyy)
{
	return vyy;
}
