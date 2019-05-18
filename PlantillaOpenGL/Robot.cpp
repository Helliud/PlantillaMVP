#pragma once
#include "stdafx.h"
#include "Robot.h"

void Robot::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);
	if (darVueltaRobotDerecha) {
		modelo = rotate(modelo, -90.0f * 3.14159f / 180.0f , vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotIzquierda)
	{
		modelo = rotate(modelo, 90.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras)
	{
		modelo = rotate(modelo, -180.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAdelante) {
		modelo = rotate(modelo, 0.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));

	}

	if (darVueltaRobotAdelante && darVueltaRobotDerecha) {
		modelo = rotate(modelo, 45.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAdelante && darVueltaRobotIzquierda) {
		modelo = rotate(modelo, -45.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras && darVueltaRobotIzquierda) {
		modelo = rotate(modelo, -135.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

	if (darVueltaRobotAtras && darVueltaRobotDerecha) {
		modelo = rotate(modelo, 135.0f * 3.14159f / 180.0f, vec3(0.0f, 1.0f, 0.0f));
	}

}

vec3 Robot::getCoordenadas() {
	return coordenadas;
}

void Robot::avanzar() {
	darVueltaRobotAdelante = true;
	coordenadas.z -= 0.01f;
	actualizarMatrizModelo();
}

void Robot::rotarIzq() {
	darVueltaRobotIzquierda = true;
		coordenadas.x -= 0.01f;
		actualizarMatrizModelo();
}

void Robot::rotarDer() {
	darVueltaRobotDerecha = true;
	coordenadas.x += 0.01f;
	actualizarMatrizModelo();
}

void Robot::regresar() {
	darVueltaRobotAtras = true;
	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}



Robot::Robot() {	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	/*
	//Neblina
	//Neblina - Parte trasera
	vertices.push_back({ vec4(-0.9f, 0.40f,  9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f, 0.40f,  9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f, -0.5f,  9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f,  9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });


	//Neblina - Parte abajo
	vertices.push_back({ vec4(-0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(-0.9f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.9f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });

	//Neblina - Parte delantera
	vertices.push_back({ vec4(-0.9f, 0.40f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f, 0.40f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Neblina - Parte izquierda
	vertices.push_back({ vec4(-0.9f, 0.40f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.9f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.9f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Neblina - Parte derecha
	vertices.push_back({ vec4(0.9f, 0.40f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.9f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.9f, -0.5f,  -9.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	*/

	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, - 0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });


	//OJOS
	//Ojos - Parte arriba
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	
	//Ojos - Parte abajo
	vertices.push_back({ vec4(-0.4f, 0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte delantera
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte izquierda
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(-0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });

	//Ojos - Parte derecha
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f, 0.25f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.5f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });
	vertices.push_back({ vec4(0.4f,  0.1f,  -0.65f, 1.0f),vec4(0.003f, 1.0f, 0.0f, 0.8f) });


	//CUERPO
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	//Derecha
	vertices.push_back({ vec4(0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	/*
	vertices.push_back({ vec4(0.101f, -0.2f, -0.25f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.101f, -0.4f,  0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.101f, -0.6f,  -0.25f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.101f, -0.4f,  -0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });*/

	//Izquierda
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  0.25f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.8f,  -0.25f, 1.0f),vec4(0.5f, 0.54f, 0.58f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.4f,  -0.75f, 1.0f),vec4(0.83f, 0.84f, 0.86f, 1.0f) });

	/*
	vertices.push_back({ vec4(-0.101f, -0.2f, -0.25f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.101f, -0.4f,  0.0f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.101f, -0.6f,  -0.25f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.101f, -0.4f,  -0.5f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });*/
}

