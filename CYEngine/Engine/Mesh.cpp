#include "Mesh.h"

Mesh::Mesh(const CVector<Vertex>& vertex, const CVector<unsigned int> indices)
{
	_vertices = vertex;
	_indices = indices;
	initialize();
}

void Mesh::initialize()
{
	GlGenVertexArrays(1, &_VAO);
	GlGenBuffers(1, &_VBO);
	GlGenBuffers(1, &_EBO);

	GlBindVertexArray(_VAO);
	
	GlBindBuffer(GL_ARRAY_BUFFER, _VBO);
	GlBufferData(GL_ARRAY_BUFFER, _vertices.size() * sizeof(Vertex), &_vertices[0], GL_STATIC_DRAW);

	GlBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
	GlBufferData(GL_ELEMENT_ARRAY_BUFFER, _indices.size() * sizeof(unsigned int), &_indices[0], GL_STATIC_DRAW);

	// vertex
	GlEnableVertexAttribArray(0);
	GlVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

	// normal
	GlEnableVertexAttribArray(1);
	GlVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

	// texcoords
	GlEnableVertexAttribArray(2);
	GlVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texCoords));
}
