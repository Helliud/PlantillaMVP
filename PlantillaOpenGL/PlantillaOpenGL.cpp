// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>

#define GLEW_STATIC

#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include <iostream>

#include "Shader.h"
#include "Vertice.h"

#include "Carro.h"
#include "Robot.h"
#include "Fantasma.h"
#include "Piso.h"

#include "Modelo.h"
#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"



using namespace std;

Shader *shader;
GLuint posicionID;
GLuint colorID;
GLuint modeloID;
GLuint vistaID;
GLuint proyeccionID;

mat4 vista;
mat4 proyeccion;


//Declaramos apuntador de ventana
GLFWwindow *window;

GLfloat ancho = 1024.0f;
GLfloat alto = 768.0f;

//Carro *carro;
Robot *robot;
Fantasma *fantasma;
Piso *piso;

//Actualiza el valor de la vita
void establecerVista() {
	vec3 posicionCamara = robot->getCoordenadas();
	posicionCamara.z += 4;
	posicionCamara.y += 2;

	vista = lookAt(
		posicionCamara, /*Posicion de la camara*/
		robot->getCoordenadas(),	/*Posicion del objetivo*/
		vec3(0.0f, 1.0f, 0.0f) /*Vector hacia arriba*/
	);

	if (robot != NULL) {
		robot ->vista = vista;
	}

	if (fantasma != NULL) {
		fantasma->vista = vista;
	}

	if (piso != NULL) {
		piso->vista = vista;
	}
}

void establecerProyeccion() {
	proyeccion = perspective(
		1.0f,		//Campo de vision (FoV)
		ancho/alto, //Relacion de aspecto
		1.0f,		//Near Clipping (Desde donde renderea)
		10.0f		//Far Clipping (Hasta donde renderea)
	);
}

void dibujar() {
	piso->dibujar(GL_QUADS);
	robot->dibujar(GL_QUADS);
	 fantasma->dibujar(GL_QUADS);
}

void actualizar() {

	int estadoIzquierda = glfwGetKey(window, GLFW_KEY_LEFT);
	if (estadoIzquierda == GLFW_PRESS) {
		robot->rotarIzq();
		establecerVista();
	}
	else {
		robot->darVueltaRobotIzquierda = false;
	}

	int estadoDerecha = glfwGetKey(window, GLFW_KEY_RIGHT);
	if (estadoDerecha == GLFW_PRESS) {
		robot->rotarDer();
		establecerVista();

	}
	else {
		robot->darVueltaRobotDerecha = false;
	}


	int estadoArriba =
		glfwGetKey(window, GLFW_KEY_UP);
	if (estadoArriba == GLFW_PRESS) {
		robot->avanzar();
		establecerVista();
	}
	else {
		robot->darVueltaRobotAdelante = false;
	}


	int estadoAbajo = glfwGetKey(window, GLFW_KEY_DOWN);
	if (estadoAbajo == GLFW_PRESS) {
		robot->regresar();
		establecerVista();
	}
	else {
		robot->darVueltaRobotAtras = false;
	}

}

int main()
{
	//Si no se pudo iniciar glfw
	//terminamos ejcución
	if (!glfwInit()) {
		exit(EXIT_FAILURE);
	}
	//Si se pudo iniciar GLFW
	//entonces inicializamos la ventana
	window =
		glfwCreateWindow(1024, 768, "Ventana", 
			NULL, NULL);
	//Si no podemos iniciar la ventana
	//Entonces terminamos ejecucion
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	//Establecemos el contexto
	glfwMakeContextCurrent(window);

	//Una vez establecido  el contexto
	//Activamos funciones modernas
	glewExperimental = true;
	GLenum errorGlew = glewInit();
	if (errorGlew != GLEW_OK) {
		cout << 
			glewGetErrorString(errorGlew);
	}

	const GLubyte *versionGL =
		glGetString(GL_VERSION);
	cout << "Version OpenGL: "
		<< versionGL;


	const char *rutaVertex = 
		"VertexShader.shader";
	const char *rutaFragment = 
		"FragmentShader.shader";

	shader = new Shader(rutaVertex, rutaFragment);

	//Mapeo de atributos
	posicionID =
		glGetAttribLocation(shader->getID(), "posicion");
	colorID =
		glGetAttribLocation(shader->getID(), "color");
	modeloID =
		glGetUniformLocation(shader->getID(), "modelo");
	vistaID =
		glGetUniformLocation(shader->getID(), "vista");
	proyeccionID =
		glGetUniformLocation(shader->getID(), "proyeccion");

	//Desenlazar el shader
	shader->desenlazar();

	//Establecer vista
	establecerProyeccion();

	//Inicializar modelo y establecer shader al modelo
	
	robot = new Robot();
	robot->proyeccion = proyeccion;
	robot->shader = shader;
	robot->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);

	establecerVista();
	robot->vista = vista;




	//Inicializar modelo y establecer shader al modelo
	fantasma = new Fantasma();
	fantasma->vista = vista;
	fantasma->proyeccion = proyeccion;
	fantasma->shader = shader;

	//Inicializar vertex array
	fantasma->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);



	//Inicializar modelo y establecer shader al modelo
	piso = new Piso();
	piso->vista = vista;
	piso->proyeccion = proyeccion;
	piso->shader = shader;

	//Inicializar vertex array
	piso->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	//Ciclo de dibujo (Draw loop)
	while (!glfwWindowShouldClose(window)) {
		//Esablecer region de dibujo
		glViewport(0, 0, 1024, 768);
		//Establece el color de borrado
		glClearColor(0.0f, 0.0f, 0.0f, 1);
		//Borramos
		glClear(
			GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		//Rutina de dibujo
		dibujar();
		actualizar();

		//Cambiar los buffers
		glfwSwapBuffers(window);
		//Reconocer si hay entradas
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

    return 0;
}

