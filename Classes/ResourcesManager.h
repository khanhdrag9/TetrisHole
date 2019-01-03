#include "Header.h"
#include "Templates.h"

class gObject;

class ResourcesManager : public Singleton<ResourcesManager>
{
    map<string, string> _listSources;
    
public:
    ResourcesManager();
    ~ResourcesManager();
    
    shared_ptr<gObject> getObject();

};
