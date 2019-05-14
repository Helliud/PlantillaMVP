#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Robot : public Modelo
{
public:
	Robot();
	void rotar();
	bool textura = false;
	vec3 getCoordenadas();
	enum Direccion { Izquierda, Derecha };
	void avanzar(Direccion direccion);

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
	

};