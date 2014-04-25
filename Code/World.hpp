#pragma once

#define ModelMatrixSize sizeof(glm::mat4)
#define ViewMatrixSize sizeof(glm::mat4)
#define ProjectionMatrixSize sizeof(glm::mat4)

#define ModelMatrixOffset 0
#define ViewMatrixOffset ModelMatrixOffset + ModelMatrixSize
#define ProjectionMatrixOffset ViewMatrixOffset + ViewMatrixSize
#define TransformationSize ProjectionMatrixOffset + ProjectionMatrixSize

namespace World
{
	// 60° grādi ≈ 1.05 radiāni
	const float FieldOfViewY = 1.05f;
	const float TangentHalfFOVY = tan(FieldOfViewY / 2.0f);
	const glm::mat4 DefaultModel = glm::mat4(1.0f);
	const glm::mat4 DefaultView = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -25.0f));
	static glm::mat4 ViewMatrix = DefaultView;
	static glm::mat4 ProjectionMatrix = glm::perspective(1.05f, 1.0f, 0.1f, 1000.0f);
	static GLuint TransformationBuffer = 0;
	std::stack<glm::mat4> &ModelMatrix();
	void Bind(unsigned int TransformationBinding);
	void UnBind();
	void UpdateModel();
	void RotateView(float Angle, glm::vec3 Rotation);
	void ResetView();
	void UpdatePerspective(float aspectRatio);
};
