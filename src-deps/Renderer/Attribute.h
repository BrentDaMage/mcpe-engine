#pragma once

#include "VertexField.h"

namespace mce
{
	class Attribute
	{
	private:
		mce::VertexField m_vertexField;
		unsigned int m_location;
		unsigned int m_count;
		
	public:
		Attribute();
		Attribute(unsigned int location, unsigned int count, mce::VertexField vertexField);

		mce::VertexField getVertexField() { return m_vertexField; }
		unsigned int getLocation() { return m_location; }
		
		bool operator==(const mce::Attribute& other) const;
	};
}