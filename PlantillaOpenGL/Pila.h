#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
#include <time.h>

class Pila : public Modelo
{
public:
	Pila();
	float pilaX = 0.0f;
	float pilaZ = 0.0f;
	vec3 coordenadasPila = vec3(pilaX, 0.0f, pilaZ);
	vec3 getCoordenadasPila();

	void actualizarMatrizModelo();


};