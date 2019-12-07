#include "stub.h"

int pairs( vector<int>& arr, int k) {
  std::set<int> m;
  int count = 0;
  int size = static_cast<int>(arr.size());
  for(int i = 0; i < size; ++i)
  {
    if(m.find(arr[i] - k) != m.end())
    {
        std::cout << "(" << arr[i] << "," << arr[i] - k << ")" << std::endl;
        ++count;

    }

    if(m.find(arr[i] + k) != m.end())
    {
        std::cout << "(" << arr[i] + k << "," <<  arr[i] << ")" << std::endl;
        ++count;

    }
    m.insert(arr[i]);

  }
  return count;

}
class Shape {
public:
  virtual void draw(){cout << "Drawing a shape\n"; };
};


class Triangle : public Shape {
public:
  void draw() {cout << "Drawing a triangle\n"; }
};

class Square : public Shape {
public:
  void draw() {cout << "Drawing a square\n"; }
};


template<class T1, class T2>
void construct(T1 *p, const T2& value)
{
    new (p) T1(value);
}

int qqdq()
{
    vector<Shape*> shapes;
    Triangle t1,t2;
    Square s1, s2;
    shapes.push_back(&t1);
    shapes.push_back(&s1);
    shapes.push_back(&t2);
    shapes.push_back(&s2);

   // for_each( shapes.begin(),  shapes.end(), std::mem_fun(&Shape::draw));

   std::string str = "Hello";
   std::string::iterator it(str.begin());
   *it = 'c';
   std::cout << *it << std::endl;

    /*
    std::vector<int> v1{1,5,3,4,1,2,4,2};
    std::sort(v1.begin(), v1.end());
    auto it = std::unique(v1.begin(), v1.end());
    v1.erase(it, v1.end());

    std::cout << pairs(v1, 2);
    */
     return 0;
}
