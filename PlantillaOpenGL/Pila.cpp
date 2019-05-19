#pragma once
#include "stdafx.h"
#include "Pila.h"

void Pila::actualizarMatrizModelo() {
	//Matriz identidad
	modelo = mat4(1.0f);
	modelo = translate(modelo, coordenadasPila);
}

vec3 Pila::getCoordenadasPila() {
	return coordenadasPila;
}



Pila::Pila() {
	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.2f, 0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.2f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.2f, 0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.2f, 0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.19f, 0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.19f, 0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.19f,  -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(-0.19f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(0.5f, 0.40f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, 0.40f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f,  -0.05f,  0.0f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });
	vertices.push_back({ vec4(0.5f, -0.05f,  -0.5f, 1.0f),vec4(0.231f, 0.231f, 0.223f, 1.0f) });



	//CABEZA
	//Cabeza - Parte trasera
	vertices.push_back({ vec4(-0.503f, 0.403f,  0.003f, 1.01f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.403f,  0.003f, 1.01f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  0.003f, 1.01f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, -0.05f,  0.003f, 1.01f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });


	//Cabeza - Parte abajo
	vertices.push_back({ vec4(-0.503f, -0.05f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, -0.05f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f,  -0.05f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });

	//Cabeza - Parte arriba
	vertices.push_back({ vec4(-0.503f, 0.403f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, 0.403f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f,  0.403f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f,  0.403f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });

	//Cabeza - Parte delantera
	vertices.push_back({ vec4(-0.503f, 0.403f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.403f,  -0.501f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  -0.501f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, -0.05f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });

	//Cabeza - Parte izquierda
	vertices.push_back({ vec4(-0.503f, 0.403f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, 0.403f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f,  -0.05f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.503f, -0.05f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });

	//Cabeza - Parte derecha
	vertices.push_back({ vec4(-0.2f, 0.403f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, 0.403f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f,  -0.05f,  0.003f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });
	vertices.push_back({ vec4(-0.2f, -0.05f,  -0.503f, 1.0f),vec4(0.87f, 0.631f, 0.0f, 1.0f) });

}