#include "stdafx.hpp"

std::stack<glm::mat4> &World::ModelMatrix()
{
	static std::stack<glm::mat4> m;
	return m;
}

void World::Bind(unsigned int TransformationBinding)
{
	World::ModelMatrix().push(DefaultModel);
	if (World::TransformationBuffer == 0)
	{
		glGenBuffers(1, &World::TransformationBuffer);
		glBindBuffer(GL_UNIFORM_BUFFER, World::TransformationBuffer);
		glBufferData(GL_UNIFORM_BUFFER, TransformationSize, nullptr, GL_DYNAMIC_DRAW);
		glBufferSubData(GL_UNIFORM_BUFFER, ModelMatrixOffset, ModelMatrixSize, glm::value_ptr(ModelMatrix().top()));
		glBufferSubData(GL_UNIFORM_BUFFER, ViewMatrixOffset, ViewMatrixSize, &ViewMatrix);
		glBufferSubData(GL_UNIFORM_BUFFER, ProjectionMatrixOffset, ProjectionMatrixSize, &ProjectionMatrix);
		glBindBufferBase(GL_UNIFORM_BUFFER, TransformationBinding, World::TransformationBuffer);
	};
}

void World::UnBind()
{
	if (TransformationBuffer > 0)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, 0);
		glDeleteBuffers(1, &TransformationBuffer);
	};
	World::ModelMatrix().pop();
}

void World::UpdateModel()
{
	if (TransformationBuffer > 0)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, TransformationBuffer);
		glBufferSubData(GL_UNIFORM_BUFFER, ModelMatrixOffset, ModelMatrixSize, glm::value_ptr(ModelMatrix().top()));
	};
}

void World::RotateView(float Angle, glm::vec3 Rotation)
{
	ViewMatrix = glm::rotate(ViewMatrix, Angle, Rotation);
	if (TransformationBuffer > 0)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, TransformationBuffer);
		glBufferSubData(GL_UNIFORM_BUFFER, ViewMatrixOffset, ViewMatrixSize, &ViewMatrix);
	};
}

void World::ResetView()
{
	ViewMatrix = DefaultView;
	if (TransformationBuffer > 0)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, TransformationBuffer);
		glBufferSubData(GL_UNIFORM_BUFFER, ViewMatrixOffset, ViewMatrixSize, &ViewMatrix);
	};
}


void World::UpdatePerspective(float aspectRatio)
{
	ProjectionMatrix[0].x = 1.0f / (aspectRatio * TangentHalfFOVY);
	if (TransformationBuffer > 0)
	{
		glBindBuffer(GL_UNIFORM_BUFFER, TransformationBuffer);
		glBufferSubData(GL_UNIFORM_BUFFER, ProjectionMatrixOffset, ProjectionMatrixSize, &ProjectionMatrix);
	};
}


