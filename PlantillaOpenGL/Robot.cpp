#pragma once
#include "stdafx.h"
#include "Robot.h"

void Robot::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

vec3 Robot::getCoordenadas() {
	return coordenadas;
}

void Robot::avanzar(Direccion direccion) {

	if (direccion == Direccion::Derecha) {
		rotacion = -rotacion;
		if (rotacion > 360) {
			rotacion -= 360;
		}
	}

	if (direccion == Direccion::Izquierda) {
		rotacion = +rotacion;
		if (rotacion > 0) {
			rotacion += 360;
		}
	}
	angulo += rotacion;

	coordenadas.z += 0.01f;
	actualizarMatrizModelo();
}

void Robot::rotar() {
	
}

Robot::Robot() {	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


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

