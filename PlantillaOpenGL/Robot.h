#pragma once
#include "Modelo.h"
#include "glm/gtx/transform.hpp"
#include "glm/glm.hpp"

class Robot : public Modelo
{
public:
	Robot();
	vec3 getCoordenadas();
	void avanzar();
	void rotarIzq();
	void rotarDer();
	void regresar();
	float anguloRobot;
	bool darVueltaRobotDerecha;
	bool darVueltaRobotIzquierda;
	bool darVueltaRobotAtras;
	bool darVueltaRobotAdelante;
	void robotTiempoDiferencial();

	double tiempoAnterior = 0.0f;
	double tiempoActual = 0.0f;
	double tiempoDiferencial = 0.0f;
	float velocidad = 5.0f;
	int bonusVelocidad = 1;


	vec3 coordenadasRobot = vec3(-45.0f, 0.0f, 15.0f);

private:
	void actualizarMatrizModelo();
	

};