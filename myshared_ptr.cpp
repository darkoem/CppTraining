class RefCounter
{
    private:
    int count;

    public:
    void AddRefCount()
    {
        count++;
    }

    int DecreaseRefCount()
    {
        return --count;
    }
};

template <typename T> 
class myshared_ptr
{
private:
    T* pData;
    RefCounter* refCounter;
public:
    myshared_ptr() : pData(0), refCounter(0)
    {
        refCounter = new RefCounter();
        refCounter->AddRefCount();
    }
    myshared_ptr(T* pValue) : pData(pValue), refCounter(0)
    {
        refCounter = new RefCounter();
        refCounter->AddRefCount();
    }

    myshared_ptr(const myshared_ptr<T>& sp) : pData(sp.pData), refCounter(sp.refCounter)
    {
        refCounter->AddRefCount();
    }

    ~myshared_ptr()
    {
        if (refCounter->DecreaseRefCount() == 0)
        {
            delete pData;
            delete refCounter;
        }
    }
};
