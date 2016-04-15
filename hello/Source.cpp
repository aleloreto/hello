
#include <csignal>
#include <iostream>
#include <fstream>
#include <atomic>

namespace
{
	std::atomic<bool> salir = false;
}

void sigintHandler(int h)
{
	std::cout << "SIGINT handler.\n";
	salir = true; // sólo pone la señal de salida
}

class Unaclase {
public:
	Unaclase() { 
		std::cout << "abriendo el archivo.\n";
		archivo.open("raii.txt"); 
	}
	~Unaclase() { 
		std::cout << "cerrando el archivo.\n";
		archivo.close(); 
		std::cin.get();
	}
private:
	std::ofstream archivo;
};

int main()
{
	signal(SIGINT, sigintHandler);

	while (!salir) {
		// lo que haga el programa va acá
		// ...

		Unaclase uc{};

	}
}


