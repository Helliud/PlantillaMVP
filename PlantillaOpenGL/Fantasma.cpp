#pragma once
#include "stdafx.h"
#include "Fantasma.h"

void Fantasma::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}

void Fantasma::avanzar() {
	coordenadas.z -= 0.01f;
	actualizarMatrizModelo();
}

void Fantasma::rotar() {

}

void Fantasma::flotar() {
	tiempoActual = glfwGetTime();
	tiempoDiferencial = tiempoActual - tiempoAnterior;

	if (coordenadas.y < -100.0f) {
		coordenadas.y -= 1.0f;
	}
}

Fantasma::Fantasma() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.00f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(-0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(-0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.1f) });
	vertices.push_back({ vec4(0.5f,  -0.5f,  0.0f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });
	vertices.push_back({ vec4(0.5f, -0.5f,  -0.7f, 1.0f),vec4(1.0f, 1.0f, 1.0f, 0.0f) });

	//OJOS
	//Ojo - Izquierdo
	vertices.push_back({ vec4(-0.35f, 0.2f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.35f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, 0.2f, -0.701f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//Ojo - Derecho
	vertices.push_back({ vec4(0.35f, 0.2f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.35f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, 0.2f, -0.701f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//BOCA
	vertices.push_back({ vec4(-0.1f, -0.05f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.1f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.0f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(0.1f, -0.05f, -0.701f, 1.0f), vec4(0.0f, 0.0f, 0.0f, 1.0f) });

	//LAGRIMAS
	//Lagrimas - Izquierda
	vertices.push_back({ vec4(-0.25f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(-0.25f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(-0.2f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(-0.2f, 0.0f, -0.701f, 1.0f), vec4(0.0f, 0.2f, 0.5f, 0.08f) });

	//Lagrimas - Izquierda
	vertices.push_back({ vec4(0.25f, 0.0f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(0.25f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(0.2f, -0.5f,  -0.701f, 1.0f),vec4(0.0f, 0.2f, 0.5f, 0.08f) });
	vertices.push_back({ vec4(0.2f, 0.0f, -0.701f, 1.0f), vec4(0.0f, 0.2f, 0.5f, 0.08f) });

}

