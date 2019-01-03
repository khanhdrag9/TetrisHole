#pragma once
template <class T>
class Singleton
{
public:
    static T* getInstance()
    {
        static T* instance{ new T() };
        return instance;
    }
    
};

template <typename T>
class gridBase
{
protected:
	std::vector<std::vector<T>> _grid;
	
	pos _sizePos;
public:
	std::vector<T>& operator[](const int& index)
	{
		return _grid[index];
	}

	const pos& sizePos() const { return _sizePos; }
};

#if (CC_TARGET_PLATFORM != CC_PLATFORM_WIN32)
template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
#endif
