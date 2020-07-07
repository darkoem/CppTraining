template <typename T>
class myunique_ptr
{
    private:
    T * pData;
    public:
    ~myunique_ptr()
    {
        delete pData;
    }
    myunique_ptr(T*ptr)
    {
        pData = ptr;
    }
    myunique_ptr(myunique_ptr&& up)
    {
        pData = up.pData;
        up.pData = nullptr;
    }
    myunique_ptr& operator=(myunique_ptr&& up)
    {
        myunique_ptr temp(std::move(up));
        swap(temp);
        return *this;
    }
    T& operator*()
    {
        return *pData;
    }
    T* operator->()
    {
        return pData;
    }
};
