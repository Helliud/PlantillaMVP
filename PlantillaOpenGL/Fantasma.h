#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
#include <time.h>

class Fantasma : public Modelo
{
public:
	Fantasma();
	void avanzar();
	void rotar();
	bool textura = false;
	void flotar();
	double tiempoAnterior = 0.0f;
	double tiempoActual = 0.0f;
	double tiempoDiferencial = 0.0f;

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);


}; 
