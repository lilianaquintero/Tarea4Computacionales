Resultados_hw4.pdf : Plot_ODE_1.pdf Plot_ODE_2.pdf resultados.tex
	pdflatex resultados.tex

Plot_ODE_1.pdf : datos_ODE.dat datos_PDE.dat Plots_hw4.py
	python Plots_hw4.py

Plot_ODE_2.pdf : datos_ODE.dat datos_PDE.dat Plots_hw4.py
	python Plots_hw4.py

datos_ODE.dat : a.out
	./a.out>>datos_ODE.dat

a.out : ODE.cpp
	g++ ODE.cpp

datos_PDE.dat : a.out
	./a.out>>datos_PDE.dat

a.out : PDE.cpp
	g++ PDE.cpp

	

