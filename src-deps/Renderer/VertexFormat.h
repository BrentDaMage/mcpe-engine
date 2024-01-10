using namespace mce;

class VertexFormat {
private:
    unsigned char _fieldOffset[5];
public:
    int getID() { return _fieldOffset[0]; }
    int getVertexSize() { return _fieldOffset[1]; }
}