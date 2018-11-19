import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib import cm
import matplotlib.animation as animation
from matplotlib.ticker import LinearLocator, FormatStrFormatter




txt= np.genfromtxt("datos45.dat")

x=txt[:,0]
v=txt[:,1]
plt.plot(x,v)
plt.xlabel("Dist x")
plt.ylabel("Dist y")
plt.title("Mov del proyectil para 45 grados")
#plt.savefig("Plot_ODE_1.pdf")
plt.show()
txt2=np.genfromtxt("datos_otros.dat")

g10x=[]
g10y=[]
g20x=[]
g20y=[]
g30x=[]
g30y=[]
g40x=[]
g40y=[]
g50x=[]
g50y=[]
g60x=[]
g60y=[]
g70x=[]
g70y=[]
for i in range(len(txt2)):
	if(txt2[i,2]==1):
		g10x.append(txt2[i,0])
		g10y.append(txt2[i,1])
	if(txt2[i,2]==2):
		g20x.append(txt2[i,0])
		g20y.append(txt2[i,1])
	if(txt2[i,2]==3):
		g30x.append(txt2[i,0])
		g30y.append(txt2[i,1])
	if(txt2[i,2]==4):
		g40x.append(txt2[i,0])
		g40y.append(txt2[i,1])
	if(txt2[i,2]==5):
		g50x.append(txt2[i,0])
		g50y.append(txt2[i,1])
	if(txt2[i,2]==6):
		g60x.append(txt2[i,0])
		g60y.append(txt2[i,1])
	if(txt2[i,2]==7):
		g70x.append(txt2[i,0])
		g70y.append(txt2[i,1])
plt.figure()
plt.plot(g10x,g10y, label="10")
plt.plot(g20x,g20y, label="20")
plt.plot(g30x,g30y, label="30")
plt.plot(g40x,g40y, label="40")
plt.plot(g50x,g50y, label="50")
plt.plot(g60x,g60y, label="60")
plt.plot(g70x,g70y, label="70")
plt.xlabel("Dist x")
plt.ylabel("Dist y")
plt.title("Mov del proyectil para diferentes angulos")
plt.legend(loc="best")
#plt.savefig("Plot_ODE_2.pdf")
plt.show()
#PDEs

#cond inciiales
inicial=np.genfromtxt("Inicial.dat")

fig0=plt.figure()
x0=np.linspace(-25,24,50, dtype='int')
y0=np.linspace(-25,24,50, dtype='int')

def f0(x,y):
	return inicial[x][y]

z_0=f0(x0,y0)

ax0=fig0.gca(projection='3d')
x0, y0=np.meshgrid(x0, y0)
surf0= ax0.plot_surface(x0,y0,z_0, cmap=cm.viridis, linewidth=0.2)
fig0.colorbar(surf0, shrink=0.5, aspect=5)
ax0.set_xlabel('X')
ax0.set_ylabel('Y')
ax0.set_zlabel('Temperatura')
plt.title("Condiciones iniciales-extremos fijos")
plt.savefig("1.pdf")



#cond fijas

#cond fijo intermedios

dat00=np.genfromtxt("datos_int1_fijo.dat")
fig00=plt.figure()
x00=np.linspace(-25,24,50, dtype='int')
y00=np.linspace(-25,24,50, dtype='int')

def f00(x,y):
	return dat00[x][y]

z_00=f00(x00,y00)

ax00=fig00.gca(projection='3d')
x00, y00=np.meshgrid(x00, y00)
surf00= ax00.plot_surface(x00,y00,z_00, cmap=cm.viridis, linewidth=0.2)
fig00.colorbar(surf00, shrink=0.5, aspect=5)
ax00.set_xlabel('X')
ax00.set_ylabel('Y')
ax00.set_zlabel('Temperatura')
plt.title("Paso intermedio-extremo fijo")
plt.savefig("2.pdf")


dat01=np.genfromtxt("datos_int2_fijo.dat")
fig01=plt.figure()
x01=np.linspace(-25,24,50, dtype='int')
y01=np.linspace(-25,24,50, dtype='int')

def f01(x,y):
	return dat01[x][y]

z_01=f01(x01,y01)

ax01=fig01.gca(projection='3d')
x01, y01=np.meshgrid(x01, y01)
surf01= ax01.plot_surface(x01,y01,z_01, cmap=cm.viridis, linewidth=0.2)
fig01.colorbar(surf01, shrink=0.5, aspect=5)
ax01.set_xlabel('X')
ax01.set_ylabel('Y')
ax01.set_zlabel('Temperatura')
plt.title("Paso intermedio-extremo fijo")
plt.savefig("3.pdf")



#cond fijo final
dat= np.genfromtxt("datos_fijo.dat")

fig=plt.figure()
x=np.linspace(-25,24,50, dtype='int')
y=np.linspace(-25,24,50, dtype='int')

def f(x,y):
	return dat[x][y]

z_fijo=f(x,y)

ax=fig.gca(projection='3d')
x, y=np.meshgrid(x, y)
surf= ax.plot_surface(x,y,z_fijo, cmap=cm.viridis, linewidth=0.2)
fig.colorbar(surf, shrink=0.5, aspect=5)
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Temperatura')
plt.title("Grafica final-extremos fijos (equilibrio)")
plt.savefig("4.pdf")


#cond abierto

#cond inicial
inicial=np.genfromtxt("Inicial.dat")

fig0=plt.figure()
x0=np.linspace(-25,24,50, dtype='int')
y0=np.linspace(-25,24,50, dtype='int')

def f0(x,y):
	return inicial[x][y]

z_0=f0(x0,y0)

ax0=fig0.gca(projection='3d')
x0, y0=np.meshgrid(x0, y0)
surf0= ax0.plot_surface(x0,y0,z_0, cmap=cm.viridis, linewidth=0.2)
fig0.colorbar(surf0, shrink=0.5, aspect=5)
ax0.set_xlabel('X')
ax0.set_ylabel('Y')
ax0.set_zlabel('Temperatura')
plt.title("Condicion inicial-extremos abiertos")
plt.savefig("5.pdf")


#cond int abierto

dat10= np.genfromtxt("datos_int1_abiero.dat")
x10=np.linspace(-25,24,50, dtype='int')
y10=np.linspace(-25,24,50, dtype='int')

def f10(x,y):
	return dat10[x][y]

z_10=f10(x10,y10)
fig10=plt.figure()
ax10=fig10.gca(projection='3d')
x10, y10=np.meshgrid(x10, y10)
surf10= ax10.plot_surface(x10,y10,z_10, cmap=cm.viridis, linewidth=0.2)
fig10.colorbar(surf10, shrink=0.5, aspect=5)
ax10.set_xlabel('X')
ax10.set_ylabel('Y')
ax10.set_zlabel('Temperatura')
plt.title("Paso intermedio-extremos abiertos")
plt.savefig("6.pdf")

dat11= np.genfromtxt("datos_int2_abierto.dat")
x11=np.linspace(-25,24,50, dtype='int')
y11=np.linspace(-25,24,50, dtype='int')

def f11(x,y):
	return dat11[x][y]

z_11=f11(x11,y11)
fig11=plt.figure()
ax11=fig11.gca(projection='3d')
x11, y11=np.meshgrid(x11, y11)
surf11= ax11.plot_surface(x11,y11,z_11, cmap=cm.viridis, linewidth=0.2)
fig11.colorbar(surf11, shrink=0.5, aspect=5)
plt.title("Paso intermedio-extremos abiertos")
plt.savefig("7.pdf")


#cond final abiero
dat1= np.genfromtxt("datos_abierto.dat")

x1=np.linspace(-25,24,50, dtype='int')
y1=np.linspace(-25,24,50, dtype='int')

def f1(x,y):
	return dat1[x][y]

z_abierto=f1(x1,y1)
fig1=plt.figure()
ax1=fig1.gca(projection='3d')
x1, y1=np.meshgrid(x1, y1)
surf1= ax1.plot_surface(x1,y1,z_abierto, cmap=cm.viridis, linewidth=0.2)
fig1.colorbar(surf1, shrink=0.5, aspect=5)
ax1.set_xlabel('X')
ax1.set_ylabel('Y')
ax1.set_zlabel('Temperatura')
plt.title("Grafica final-extremos abiertos(equilibrio)")
plt.savefig("8.pdf")


#cond periodico
#inicial
inicial=np.genfromtxt("Inicial.dat")

fig0=plt.figure()
x0=np.linspace(-25,24,50, dtype='int')
y0=np.linspace(-25,24,50, dtype='int')

def f0(x,y):
	return inicial[x][y]

z_0=f0(x0,y0)

ax0=fig0.gca(projection='3d')
x0, y0=np.meshgrid(x0, y0)
surf0= ax0.plot_surface(x0,y0,z_0, cmap=cm.viridis, linewidth=0.2)
fig0.colorbar(surf0, shrink=0.5, aspect=5)
ax0.set_xlabel('X')
ax0.set_ylabel('Y')
ax0.set_zlabel('Temperatura')
plt.title("Condicion inicial-extremos periodico")
plt.savefig("9.pdf")


#intermedios periodico


dat20= np.genfromtxt("datos_int1_abiero.dat")
x20=np.linspace(-25,24,50, dtype='int')
y20=np.linspace(-25,24,50, dtype='int')

def f20(x,y):
	return dat20[x][y]

z_20=f20(x20,y20)
fig20=plt.figure()
ax20=fig20.gca(projection='3d')
x20, y20=np.meshgrid(x20, y20)
surf20= ax20.plot_surface(x20,y20,z_20, cmap=cm.viridis, linewidth=0.2)
fig20.colorbar(surf20, shrink=0.5, aspect=5)
ax20.set_xlabel('X')
ax20.set_ylabel('Y')
ax20.set_zlabel('Temperatura')
plt.title("Paso intermedio.extremos periodico")
plt.savefig("10.pdf")


dat21= np.genfromtxt("datos_int2_abierto.dat")
x21=np.linspace(-25,24,50, dtype='int')
y21=np.linspace(-25,24,50, dtype='int')

def f21(x,y):
	return dat21[x][y]

z_21=f21(x21,y21)
fig21=plt.figure()
ax21=fig21.gca(projection='3d')
x21, y21=np.meshgrid(x21, y21)
surf21= ax21.plot_surface(x21,y21,z_21, cmap=cm.viridis, linewidth=0.2)
fig21.colorbar(surf21, shrink=0.5, aspect=5)
ax21.set_xlabel('X')
ax21.set_ylabel('Y')
ax21.set_zlabel('Temperatura')
plt.title("Paso intermedio.extremos periodico")
plt.savefig("11.pdf")


#fianl periodico

dat2= np.genfromtxt("datos_periodico.dat")
x2=np.linspace(-25,24,50, dtype='int')
y2=np.linspace(-25,24,50, dtype='int')

def f2(x,y):
	return dat2[x][y]

z_p=f2(x2,y2)
fig2=plt.figure()
ax2=fig2.gca(projection='3d')
x2, y2=np.meshgrid(x2, y2)
surf2= ax2.plot_surface(x2,y2,z_p, cmap=cm.viridis, linewidth=0.2)
fig2.colorbar(surf2, shrink=0.5, aspect=5)
ax2.set_xlabel('X')
ax2.set_ylabel('Y')
ax2.set_zlabel('Temperatura')
plt.title("Grafica final-extremos periodico (equilibrio)")
plt.savefig("12.pdf")

#animacion
M=[]
d=np.genfromtxt("datosPromedioFijo.dat")
n=len(d)/50

for i in range(n):
	x=d[i*50:(i+1)*50][0::]
	M.append(x)
M[1][0][0]=10

def data(i, z5, line):
	z5=M[i]
	ax5.clear()
	line=ax5.plot_surface(x5,y5,z5,cmap=cm.viridis, antialiased=False)
	return line
fig5=plt.figure()
ax5=fig5.add_subplot(111, projection='3d')
x5=np.linspace(-25,24,50, dtype='int')
y5=np.linspace(-25,24,50, dtype='int')

x5,y5=np.meshgrid(x5,y5)
z5= M[0]

line= ax5.plot_surface(x5,y5,z5,cmap=cm.viridis, antialiased=False)
fig5.colorbar(line, shrink=0.5, aspect=5)
ani=animation.FuncAnimation(fig5, data, fargs=(M,line), frames=len(M), interval=30, blit=False)
#ani.save("animacion_fijos.gif", writer ="imagemagick", fps=100)


#promedios
#promedios


p1=np.genfromtxt("datosPromedioFijo.dat")
t1=np.genfromtxt("tiempoFijo.dat")
m_p=[]
	
for i in range(n):	
		x=p1[i*50:(i+1)*50][0::]				
		m_p.append(x)
	

#for j in range(49):
#	for ii in range(49):
#		if (m_p[i][j][ii]==100):
#			b[i]=np.delete(m_p[i],[j][ii])

for i in range(len(m_p)):
	m_p[i]=np.average(m_p[i])

plt.figure()
plt.plot(t1,m_p)
plt.savefig("Promedio1.pdf")


p3=np.genfromtxt("datosPromedioPeriodico.dat")
t3=np.genfromtxt("tiempoPeriodico.dat")
m_p3=[]
	
for i in range(n):	
		x3=p3[i*50:(i+1)*50][0::]				
		m_p3.append(x3)
	

#for j in range(49):
#	for ii in range(49):
#		if (m_p[i][j][ii]==100):
#			b[i]=np.delete(m_p[i],[j][ii])

for i in range(len(m_p3)):
	m_p3[i]=np.average(m_p3[i])

plt.figure()
plt.plot(t1,m_p3)
plt.savefig("Promedio3.pdf")



