from multiprocessing import Pool
import matplotlib.pyplot as plt
from random import randint
import statistics
width = 10000
heigth = width
radio = width

npuntos = 0
ndentro = 0
radio2 = radio*radio
replicas = 80
promediopi = []
listareplicas = []
listapromedios = []


if __name__ == '__main__':
        with Pool(4) as p:
            for j in range(replicas):
                for i in range(1,10000):
                    x = randint(0,width)
                    y = randint(0,width)
                    npuntos += 1
                    if x*x + y*y <= radio2:
                        ndentro += 1
                    pi = ndentro*4 /npuntos
                    promediopi.append(pi)
                print(statistics.mean(promediopi))
                listareplicas.append(j)
                listapromedios.append(statistics.mean(promediopi))
            #print(statistics.mean(promediopi))
            plt.plot(listareplicas,listapromedios)
            plt.xlabel('Número de réplicas')
            plt.ylabel('Valores de pi')
            plt.title('Tarea3_Equipo4_Biomecánica_Jueves')
            plt.show()
