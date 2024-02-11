#include "Attribute.h"

mce::Attribute::Attribute()
{
	m_vertexField = mce::VertexField();
	m_location = 0;
	m_count = 0;
}

mce::Attribute::Attribute(unsigned int location,  unsigned int count, mce::VertexField vertexField)
{
	m_vertexField = vertexField;
	m_location = location;
	m_count = count;
}

bool mce::Attribute::operator==(const mce::Attribute &other) const
{
  return m_vertexField == other.m_vertexField &&
		 m_location == other.m_location &&
		 m_count == other.m_count;
}