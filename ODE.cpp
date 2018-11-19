#include <iostream>
#include <cmath>
#include<fstream>
using namespace std;

float der_x(float vxx);
float der_y(float vyy);
float der_vx(float vyy, float vxx);
float der_vy(float vyy, float vxx);
float der_v(float vv);

int main()
{
	float h=0.0001;
	//int i=2;
	int puntos=50000;
	float seno=0.70;
	float coseno=0.70;
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
	ofstream myfile;
	myfile.open("datos45.dat");
	float yc=y[0];
	int i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile<<x[i]<<" "<<y[i]<<" "<<std::endl;
		yc= y[i];
		i=i+1;
	}
	myfile.close();

	std::cout<<"La distancia recorrida por el proyectil es de 4.26 (en el eje x)"<<std::endl;
	std::cout<<"El angulo para el cual alcanzo una mayor distancia es de 20 grados"<<std::endl;
	puntos=6100;
	coseno=0.9848;
	seno=0.1736;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;
	ofstream myfile2;
	myfile2.open("datos_otros.dat");
	//i=1;
	//yc=y[0];	
	for (int i =1; i<puntos; i++)
	//while(yc>=0)
	{
		t[i]= t[i-1] + h;

		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;

		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
	
		myfile2<<x[i]<<" "<<y[i]<<" "<<1<<std::endl;
		//i=i+1;
		//yc=y[i];
	}


	puntos=9400;
	coseno=0.93969262;
	seno=0.34202014;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<2<<std::endl;
		yc=y[i];
		i=i+1;
	}


	puntos=12500;
	coseno=0.8660254;
	seno=0.5;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<3<<std::endl;
		yc=y[i];
		i=i+1;
	}

	puntos=15100;
	coseno=0.76604444;
	seno=0.64278761;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;	
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<4<<std::endl;
		yc=y[i];
		i=i+1;
	}
	
	puntos=15000;
	coseno=0.64278761;
	seno=0.76604444;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<5<<std::endl;
		yc=y[i];
		i=i+1;
	}

	puntos=15000;
	coseno=0.5;
	seno=0.8660254;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;	
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<6<<std::endl;
		yc=y[i];
		i=i+1;
	}

	puntos=30000;
	coseno=0.34202014;
	seno=0.93969262;
	t[0] =0;
	x[0] =0;
	y[0] =0;
	v[0] =300.0;
	vx[0]=coseno*300.0;
	vy[0]=seno*300;	
	yc=y[0];
	i=1;
	while(yc>=0)
	//for (int i =1; i<puntos; i++)
	{
		t[i]= t[i-1] + h;
		float k1, k2, k3, k4, l1,l2,l3,l4,m1,m2,m3,m4,n1,n2,n3,n4;
		k1=h* der_x(vx[i-1]);
		k2=h*der_x(vx[i-1]+(0.5*k1));
		k3=h*der_x(vx[i-1]+(0.5*k2));
		k4=h*der_x(vx[i-1] +k3);
		
		
		l1=h* der_y(vy[i-1]);
		l2=h*der_y(vy[i-1]+ (0.5*l1));
		l3=h*der_y(vy[i-1]+(0.5*l2));
		l4=h*der_y(vy[i-1] +l3);

		
		m1=h* der_vx(vy[i-1], vx[i-1]);
		n1=h* der_vy(vy[i-1], vx[i-1]);

		m2=h*der_vx(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));
		n2=h*der_vy(vy[i-1]+ (0.5*n1), vx[i-1]+(0.5*m1));

		m3=h*der_vx(vy[i-1]+0.5*n2, vx[i-1]+(0.5*m2));
		n3=h*der_vy(vy[i-1]+(0.5*n2), vx[i-1]+(0.5*m2));

		m4=h*der_vx(vy[i-1] +n3, vx[i-1]+m3);
		n4=h*der_vy(vy[i-1] +n3, vx[i-1]+m3);

		float a_k, a_l, a_m, a_n;
		a_k=(1.0/6.0)*(k1+2.0*k2+2.0*k3+k4);
		a_l=(1.0/6.0)*(l1+2.0*l2+2.0*l3+l4);
		a_m=(1.0/6.0)*(m1+2.0*m2+2.0*m3+m4);
		a_n=(1.0/6.0)*(n1+2.0*n2+2.0*n3+n4);

		x[i]= x[i-1] + a_k;
		y[i]= y[i-1] + a_l;
		vx[i]= vx[i-1] + a_m;
		vy[i]= vy[i-1] + a_n;
		float bla= (vx[i]*vx[i])+(vy[i]*vy[i]);
		v[i]=pow(bla,0.5);
		
		myfile2<<x[i]<<" "<<y[i]<<" "<<7<<std::endl;
		yc=y[i];
		i=i+1;
	}
	myfile2.close();
	return 0;
}

float der_vy(float vyy, float vxx)
{
	float bla= (vxx*vxx)+(vyy*vyy);
	float vv=pow(bla,0.5);
	return -(10.0+(vv*vyy));
}

float der_vx(float vyy, float vxx)
{
	float bla= (vxx*vxx)+(vyy*vyy);
	float vv=pow(bla,0.5);	
	return -0.2*vxx*pow(vv,2)/(abs(vv)*0.2);
}

float der_x(float vxx)
{
	return vxx;
}
float der_y(float vyy)
{
	return vyy;
}
