#pragma once

template<typename T1 = std::string, typename T2 = int>
Animal<T1, T2>::Animal() {}

template<typename T1 = std::string, typename T2 = int>
Animal<T1, T2>::~Animal() {}

template<typename T1 = std::string, typename T2 = int>
Animal<T1, T2>::Animal(std::string species, std::string typeOfX, T1 x, std::string typeOfY, T2 y): species(species), typeOfX(typeOfX), x(x), typeOfY(typeOfY), y(y)
{}

template<typename T1 = std::string, typename T2 = int>
void Animal<T1, T2>::printEverything()
{
	std::cout << "Spieces is: " << species << " " << typeOfX << " is " << x << " " <<  typeOfY << " is " << y << std::endl;
}