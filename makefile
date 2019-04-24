all: grafica_001.png grafica_01.png grafica_1.png 
%.png: euler_001.dat euler_01.dat euler_1.dat 
	python graficar.py
    
all: euler_001.dat euler_01.dat euler_1.dat 

%.dat: datos.x
	./datos.x
    
datos.x: data.cpp
	g++ data.cpp -o datos.x

clean:
	rm -rf *.dat *.png *.x