#pragma once
#include "stdafx.h"
#include "hitboxRobot.h"
#include "Robot.h"

void HitboxRobot::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

vec3 HitboxRobot::getCoordenadas() {
	return coordenadas;
}

void HitboxRobot::hitboxrobotTiempoDiferencial() {

	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

}

void HitboxRobot::avanzarHitRob() {
	coordenadas.z -= velocidad * tiempoDiferencial;
	actualizarMatrizModelo();
}

void HitboxRobot::rotarIzqHitRob() {
	coordenadas.x -= velocidad * tiempoDiferencial;
	actualizarMatrizModelo();
}

void HitboxRobot::rotarDerHitRob() {
	coordenadas.x += velocidad * tiempoDiferencial;
	actualizarMatrizModelo();
}

void HitboxRobot::regresarHitRob() {
	coordenadas.z += velocidad * tiempoDiferencial;
	actualizarMatrizModelo();
}


HitboxRobot::HitboxRobot() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f,  -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(rRobot, gRobot, bRobot, 0.1f) });

}

