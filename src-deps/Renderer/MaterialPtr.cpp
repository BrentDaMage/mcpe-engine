namespace mce {

MaterialPtr(MaterialPtr&& value)
{
    _move(value);
}

MaterialPtr(RenderMaterialGroup& group, std::string const& name)
    : group(group),
    , material(nullptr),
    , name(name)
{
    group->_addRef(this);
    onGroupReloaded();
}

MaterialPtr::MaterialPtr()
    : group(nullptr),
    , name("")
{}

void MaterialPtr::_move(MaterialPtr&& value)
{
    group = value.group;
    material = value.material;
    std::swap(name, value.name);
    _deref(value);
    group->_addRef(this);
}

RenderMaterialGroup* MaterialPtr::_deref()
{
    if (group != nullptr)
    {
        group->removeRef(this);
        group = nullptr;
    }
    material = nullptr;
}

void onGroupReloaded()
{
    if (group == nullptr)
    {

    }
}

MaterialPtr& MaterialPtr::operator=(MaterialPtr&& value)
{
    return *_move(value);
}

MaterialPtr::~MaterialPtr()
{
    _deref();
}

}