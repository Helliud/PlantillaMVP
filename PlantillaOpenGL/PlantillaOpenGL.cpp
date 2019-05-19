// PlantillaOpenGL.cpp: define el punto de entrada de la aplicación de consola.

#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
#include "Pila.h"
#include "HitboxRobot.h"

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

GLfloat visibility;
GLfloat density = 0.007f;
GLfloat gradient = 1.5f;
int contadorPuntos;
char windowName[] = "THE GAME";


mat4 vista;
mat4 proyeccion;

GLint camaraZ = 4;
GLint camaraY = 2;
//Declaramos apuntador de ventana
GLFWwindow *window;

GLfloat ancho = 1024.0f;
GLfloat alto = 768.0f;

//Carro *carro;
Robot *robot;
Fantasma *fantasma;
Piso *piso;
Pila *pila;
HitboxRobot *hitboxRobot;

//Actualiza el valor de la vita
void establecerVista() {
	vec3 posicionCamara = robot->getCoordenadas();
	posicionCamara.z += camaraZ;
	posicionCamara.y += camaraY;

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

	if (pila != NULL) {
		pila->vista = vista;
	}

	if (hitboxRobot != NULL) {
		hitboxRobot->vista = vista;
	}

}

void establecerProyeccion() {
	proyeccion = perspective(
		1.0f,		//Campo de vision (FoV)
		ancho/alto, //Relacion de aspecto
		1.0f,		//Near Clipping (Desde donde renderea)
		100.0f		//Far Clipping (Hasta donde renderea)
	);
}

void dibujar() {
	piso->dibujar(GL_QUADS);
	robot->dibujar(GL_QUADS);
	fantasma->dibujar(GL_QUADS);
	fantasma->actualizarMatrizModelo();
	pila->dibujar(GL_QUADS);
}
void verificarGanador() {
	if (contadorPuntos == 3) {

		
	}
}

void checarColisiones() {
	robot->getCoordenadas();
	srand(time(0));
//Ancho, alto y coordenadas de X y Y
	//Se le suma el .1 porque es la mitad del cuadrado, asi es la orilla del cuadrado
	if (robot->coordenadasRobot.x - 0.4f < pila->coordenadasPila.x + 0.4f &&
		robot->coordenadasRobot.x + 0.2f > pila->coordenadasPila.x - 0.2f &&
		robot->coordenadasRobot.z - 0.2f < pila->coordenadasPila.z + 0.2f &&
		robot->coordenadasRobot.z + 0.2f > pila->coordenadasPila.z - 0.2f) {

		pila->coordenadasPila.x = (rand() % 49) - 49;
		pila->coordenadasPila.z = (rand() % 20) - 50;
		pila->actualizarMatrizModelo();
		robot->bonusVelocidad += 1;
		contadorPuntos += 1;
		verificarGanador();

	}


}


void neblina() {
	GLfloat distance = length(robot->getCoordenadas());
	visibility = exp(-pow((distance * density), gradient));
	visibility = clamp(visibility, 0.0f, 1.0f);
}

void colisionesOrilla() {
	if (robot->coordenadasRobot.z >= 19.33f) {
		robot->coordenadasRobot.z = 19.33f;
		vec3 posicionCamara = robot->getCoordenadas();

		camaraZ = 1;
		camaraY = 12;
	}
	else if (robot->coordenadasRobot.z <= -99.33f) {
		robot->coordenadasRobot.z = -99.33f;
	}
	else if (robot->coordenadasRobot.x >= 49.33f) {
		robot->coordenadasRobot.x = 49.33f;
	}
	else if (robot->coordenadasRobot.x <= -49.33f) {
		robot->coordenadasRobot.x = -49.33f;
	}

	else {
		 camaraZ = 4;
		 camaraY = 2;
	}

}

void moverRobot() {
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

void actualizar() {
	neblina();
	robot->robotTiempoDiferencial();
	robot->tiempoAnterior = robot->tiempoActual;
	moverRobot();
	checarColisiones();
	colisionesOrilla();
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
		glfwCreateWindow(1024, 768, windowName, 
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

	//--------------------------------------------------------------------------------------------------------
	//Inicializar modelo y establecer shader al modelo
	
	robot = new Robot();
	robot->proyeccion = proyeccion;
	robot->shader = shader;
	robot->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);

	establecerVista();
	robot->vista = vista;



	//--------------------------------------------------------------------------------------------------------
	//Inicializar modelo y establecer shader al modelo
	fantasma = new Fantasma();
	fantasma->vista = vista;
	fantasma->proyeccion = proyeccion;
	fantasma->shader = shader;

	//Inicializar vertex array
	fantasma->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);


	//--------------------------------------------------------------------------------------------------------
	//Inicializar modelo y establecer shader al modelo
	piso = new Piso();
	piso->vista = vista;
	piso->proyeccion = proyeccion;
	piso->shader = shader;
	//Inicializar vertex array
	piso->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);


	//--------------------------------------------------------------------------------------------------------
	pila = new Pila();
	pila->vista = vista;
	pila->proyeccion = proyeccion;
	pila->shader = shader;
	//Inicializar vertex array
	pila->inicializarVertexArray(posicionID,
		colorID, modeloID, vistaID, proyeccionID);

	//--------------------------------------------------------------------------------------------------------
	hitboxRobot = new HitboxRobot();
	hitboxRobot->vista = vista;
	hitboxRobot->proyeccion = proyeccion;
	hitboxRobot->shader = shader;
	//Inicializar vertex array
	hitboxRobot->inicializarVertexArray(posicionID,
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

