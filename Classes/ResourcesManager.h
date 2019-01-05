#include "Header.h"
#include "Templates.h"

class gObject;

class ResourcesManager : public Singleton<ResourcesManager>
{
    map<string, std::function<shared_ptr<gObject>(const string&)>> _listgObjects;
    map<string, shared_ptr<gObject>> _listgObjectCreated;
    
    shared_ptr<gObject> createObject(const string& path);
    shared_ptr<gObject> getObjectCreated(const string& key);
    
    void init();
public:
    ResourcesManager();
    ~ResourcesManager();
    
    shared_ptr<gObject> getObject(const string& value);

};
