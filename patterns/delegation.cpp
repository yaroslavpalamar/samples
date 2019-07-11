#include <iostream>

class I {
   public:
      virtual void f() = 0;
      virtual void g() = 0;
};

class A : public I {
   public:
      void f() { std::cout << "A: вызываем метод f()" << std::endl; }
      void g() { std::cout << "A: вызываем метод g()" << std::endl; }
};

class B : public I {
   public:
      void f() { std::cout << "B: вызываем метод f()" << std::endl; }
      void g() { std::cout << "B: вызываем метод g()" << std::endl; }
};

class C : public I {
   public:
     // Конструктор
      C() : m_i ( new A() ) { }
     // Деструктор
      virtual ~C() {
         delete m_i;
      }
      void f() { m_i->f(); }
      void g() { m_i->g(); }
     // Этими методами меняем поле-объект, чьи методы будем делегировать
      void toA() {
         delete m_i;
         m_i = new A();
      }
      void toB() {
         delete m_i;
         m_i = new B();
      }
   private:
     // Объявляем объект методы которого будем делегировать
      I * m_i;
};

int main() {
   C c;

   c.f();
   c.g();
   c.toB();
   c.f();
   c.g();

   return 0;
}

/* Output:
A: вызываем метод f()
A: вызываем метод g()
B: вызываем метод f()
B: вызываем метод g()
*/

