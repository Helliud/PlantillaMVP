#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Robot : public Modelo
{
public:
	Robot();
	bool textura = false;
	vec3 getCoordenadas();
	enum Direccion { Izquierda, Derecha };
	void avanzar();
	float velocidadAngular = 2.0f;
	float angulo = 0.0f;
	void rotarIzq();
	void rotarDer();
	void regresar();
	float anguloRobot;

private:
	void actualizarMatrizModelo();
	vec3 coordenadas = vec3(0.0f, 0.0f, 0.0f);
	

};