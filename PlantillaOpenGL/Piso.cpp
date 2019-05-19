#pragma once
#include "stdafx.h"
#include "Piso.h"

void Piso::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadas);

}


Piso::Piso() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	vertices.push_back({ vec4(-50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 1.0f) });
	vertices.push_back({ vec4(50.0f, -0.8f,  20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 1.0f) });
	vertices.push_back({ vec4(-50.0f, -0.8f,  20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 1.0f) });

	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });

	vertices.push_back({ vec4(-50.0f, -0.8f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(-50.0f, -0.8f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	/*
	vertices.push_back({ vec4(-50.0f, -0.8f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, -0.8f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(-50.0f, 20.0f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });*/

	vertices.push_back({ vec4(50.0f, -0.8f, 20.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, -0.8f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, -100.0f, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
	vertices.push_back({ vec4(50.0f, 20.0f, 20.0, 1.0f),vec4(0.32f, 0.32f, 0.32f, 0.2f) });
}

