#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"
#include <time.h>


class HitboxRobot : public Modelo
{
public:
	HitboxRobot();
	vec3 getCoordenadas();
	double tiempoAnterior = 0.0f;
	double tiempoActual = 0.0f;
	double tiempoDiferencial = 0.0f;
	float velocidad = 10.0f;

	void avanzarHitRob();
	void rotarIzqHitRob();
	void rotarDerHitRob();
	void regresarHitRob();


	float rRobot = 1.0f;
	float gRobot = 1.0f;
	float bRobot = 1.0f;


	float xRobot = 0.0f;
	float zRobot = 0.0f;

	vec3 coordenadas = vec3(xRobot, 0.0f, zRobot);
	void hitboxrobotTiempoDiferencial();

private:

	void actualizarMatrizModelo();
};
