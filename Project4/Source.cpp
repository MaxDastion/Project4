#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    T* _array;
    size_t _size = 0;
public:
    List() {
        this->_array = new T;
    }
    void PushBack(T element) {
        _array[_size] = element;
        _size++;
    }
    void PopBack() {
        _size--;
    }
    size_t Size() {
        return _size;
    }
    T& operator [] (size_t i) {
        return _array[i];
    }
    bool operator > (const List& other) const {
        return _size > other._size;
    }
};

void main() {
    List <int> vec;
    vec.PushBack(23);
    vec.PushBack(6);
    vec.PushBack(233);
    vec.PushBack(2);
    vec.PushBack(3);
    vec.PushBack(3);
    auto Sort = [&vec]() {
        for (size_t i = 1; i < vec.Size(); ++i) {
            for (size_t r = 0; r < vec.Size() - i; r++) {
                if (vec[r] > vec[r + 1]) {
                    auto temp = vec[r];
                    vec[r] = vec[r + 1];
                    vec[r + 1] = temp;
                }
            }
        }
        return vec;
    };
    auto Find = [&vec](auto felem) {
        for (size_t i = 0; i < vec.Size(); i++)
        {
            if (felem == vec[i])
            {
                return i;
            }
        }
    };
    auto FindLast = [&vec](auto felem) {
        for (size_t i = vec.Size(); i > 0; i--)
        {
            if (felem == vec[i])
            {
                return i;
            }
        }
    };

    Sort();
    for (size_t i = 0; i < vec.Size(); i++)
    {
        cout << vec[i] << ' ';
    }
    cout << endl <<Find(3)<< endl;
    cout << FindLast(3);

}