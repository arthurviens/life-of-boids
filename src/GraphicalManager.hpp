#pragma once

#include <vector>

#include "glx.hpp"


class GraphicalManager {
private:
	GLFWwindow* m_window;
	int m_height;
	int m_width;

	GLint m_mvp_location;
	GLint m_vpos_location;
	GLint m_vcol_location;

	GLint m_transform_location;
	GLint m_pointSize_location;
	GLint m_maxSpeedSquared_location;
	GLint m_position_location;
	GLint m_velocity_location;

	GLint m_transform_location2;
	GLint m_vpos_location2;
	GLint m_vcol_location2;

public:
	ShaderProgram triangle_shaderProgram;
	VertexArray triangle_vertexArray;
	Buffer triangle_buffer;

	ShaderProgram points_shaderProgram;
	VertexArray points_vertexArray;
	Buffer points_buffer;

	ShaderProgram lines_shaderProgram;
	VertexArray lines_vertexArray;
	Buffer lines_buffer;

public:
	GraphicalManager();
	~GraphicalManager();
	

	void defineShaders();
	// std::vector<points::Point> pointsPreprocessing(int number);
	int mainLoop();
};


static void error_callback(int error, const char* description);

static void key_callback(GLFWwindow* window, int key, int /*scancode*/, int action, int /*mods*/);

