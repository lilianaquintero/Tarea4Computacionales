Resultados_hw4.pdf : Plot_ODE_2.pdf Resultados_hw4.tex

	pdflatex Resultados_hw4.tex


Plot_ODE_2.pdf : datos_otros.dat Plots_hw4.py
	python Plots_hw4.py

datos45.dat : a.outODE
	./a.outODE

datos_otros.dat : a.outODE
	./a.outODE

a.outODE : ODE.cpp
	g++ -o a.outODE ODE.cpp

datos_periodicos.dat : a.outPDE
	./a.outPDE

a.out : PDE.cpp
	g++ -o a.outPDE PDE.cpp

	

