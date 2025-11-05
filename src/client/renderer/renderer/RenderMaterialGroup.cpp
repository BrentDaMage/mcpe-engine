#include "RenderMaterialGroup.h"

#include "RenderMaterial.h"

using namespace mce;

RenderMaterialGroup::RenderMaterialGroup()
    : AppPlatformListener(false)
{
}

RenderMaterialGroup::~RenderMaterialGroup()
{
    _fireGroupDestroyed();
}

void RenderMaterialGroup::_fireGroupReloaded()
{
    for (std::set<MaterialPtr*>::iterator it = m_references.begin(); it != m_references.end(); it++)
    {
        (*it)->onGroupReloaded();
    }
}

void RenderMaterialGroup::_fireGroupDestroyed()
{
    m_references.clear();
}

RenderMaterial*& RenderMaterialGroup::_material(const std::string& fileName, const std::string& tag)
{
    return m_materials[fileName + tag];
}

void RenderMaterialGroup::_addRef(MaterialPtr& reference)
{
    m_references.insert(&reference);
}

void RenderMaterialGroup::_removeRef(MaterialPtr& reference)
{
    m_references.erase(&reference);
}

RenderMaterial* RenderMaterialGroup::_getMaterialPtr(const std::string& name)
{
    std::map<const std::string, RenderMaterial*>::iterator it = m_materials.find(name);
    if (it != m_materials.end())
        return it->second;

    return nullptr;
}

RenderMaterial* RenderMaterialGroup::_getMaterial(const std::string& name)
{
    RenderMaterial* materialPtr = _getMaterialPtr(name);
    if (!materialPtr)
    {
        //LOG_W("Filename: %s not found", name);
    }

    return materialPtr;
}

RenderMaterial& RenderMaterialGroup::_getMaterialOrDefault(const std::string& name, RenderMaterial& defaultMaterial)
{
    RenderMaterial* materialPtr = _getMaterialPtr(name);
    if (materialPtr)
        return *materialPtr;
    else
        return defaultMaterial;
}

void RenderMaterialGroup::loadList(const std::string listPath)
{
    if (!m_listPath.empty())
    {
        m_materials.clear();
        m_listPath = listPath;
        _loadList();
        _fireGroupReloaded();
    }
    else
    {
        initListener();
        m_listPath = listPath;
        _loadList();
    }
}

void RenderMaterialGroup::onAppResumed()
{
    m_materials.clear();
    _loadList();
    _fireGroupReloaded();
}

void RenderMaterialGroup::onAppSuspended()
{
    for (std::map<const std::string, RenderMaterial*>::iterator it = m_materials.begin(); it != m_materials.end(); it++)
    {
        *(it->second) = RenderMaterial();
    }
}