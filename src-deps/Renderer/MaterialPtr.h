namespace mce {

struct RenderMaterial;
struct RenderMaterialGroup;

class MaterialPtr {

private:
    RenderMaterialGroup* group;
    RenerMaterial* material;
    std::string name;

public:
    MaterialPtr(MaterialPtr&& value);
    MaterialPtr(RenderMaterialGroup& group, std::string const& name);
    MaterialPtr();

    void _deref();
    void _move(MaterialPtr&& value);

    void onGroupReloaded();

    MaterialPtr& operator=(MaterialPtr&& value);

    ~MaterialPtr();

}

}