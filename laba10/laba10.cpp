#include "Fraction.h"

#include <iomanip>

int main(){
    std::cout << "=== Демонстрация всех возможностей класса Fraction ===\n\n";

    std::cout << "1. КОНСТРУКТОРЫ:\n";
    Fraction f1;
    std::cout << "   Fraction f1 (по умолчанию): " << f1 << '\n';
    
    Fraction f2(3, 4);
    std::cout << "   Fraction f2(3, 4): " << f2 << '\n';
    
    Fraction f3(-5, 8);
    std::cout << "   Fraction f3(-5, 8): " << f3 << '\n';
    
    Fraction f4(f2);
    std::cout << "   Fraction f4(f2): " << f4 << '\n';

    std::cout << "2. АРИФМЕТИЧЕСКИЕ ОПЕРАЦИИ:\n";
    Fraction a(1, 2);
    Fraction b(1, 3);
    std::cout << "   a = " << a << ", b = " << b << '\n';
    
    Fraction sum = a + b;
    std::cout << "   a + b = " << sum << '\n';
    
    Fraction diff = a - b;
    std::cout << "   a - b = " << diff << '\n';
    
    Fraction prod = a * b;
    std::cout << "   a * b = " << prod << '\n';
    
    Fraction quot = a / b;
    std::cout << "   a / b = " << quot << '\n';
    std::cout << '\n';

    std::cout << "3. СОСТАВНЫЕ ОПЕРАТОРЫ ПРИСВАИВАНИЯ:\n";
    Fraction c(1, 4);
    Fraction d(1, 4);
    std::cout << "   c = " << c << ", d = " << d << '\n';
    
    c += d;
    std::cout << "   c += d: " << c << '\n';
    
    c -= Fraction(1, 8);
    std::cout << "   c -= 1/8: " << c << '\n';
    
    c *= Fraction(2, 1);
    std::cout << "   c *= 2: " << c << '\n';
    
    c /= Fraction(2, 1);
    std::cout << "   c /= 2: " << c << '\n';

    std::cout << "4. ОПЕРАТОРЫ ПРИСВАИВАНИЯ:\n";
    Fraction e(5, 6);
    Fraction f;
    std::cout << "   e = " << e << ", f = " << f << '\n';
    f = e;
    std::cout << "   После f = e (копирование): f = " << f << ", e = " << e << '\n';

    std::cout << "5. УНАРНЫЕ ОПЕРАТОРЫ:\n";
    Fraction g(2, 3);
    std::cout << "   g = " << g << '\n';
    
    std::cout << "   !g (инверсия): " << !g << '\n';
    
    std::cout << "   -g (отрицание): " << -g << '\n';
    
    Fraction j(3, 4);
    std::cout << "   j = " << j << '\n';
    std::cout << "   ++j (префикс): j = " << j << ", результат = " << ++j << '\n';
    
    Fraction k(1, 2);
    std::cout << "   k = " << k << '\n';
    Fraction k_result = k++;
    std::cout << "   k++ (постфикс): k = " << k << ", результат (старое значение) = " << k_result << '\n';
    
    Fraction l(7, 4);
    std::cout << "   l = " << l << '\n';
    Fraction l_result = --l;
    std::cout << "   --l (префикс): l = " << l << ", результат = " << l_result << '\n';
    
    Fraction m(5, 4);
    std::cout << "   m = " << m << '\n';
    Fraction m_result = m--;
    std::cout << "   m-- (постфикс): m = " << m << ", результат (старое значение) = " << m_result << '\n';

    std::cout << "6. ОПЕРАТОРЫ СРАВНЕНИЯ:\n";
    Fraction p(1, 2);
    Fraction q(2, 4);
    Fraction r(3, 4);
    std::cout << "   p = " << p << ", q = " << q << ", r = " << r << '\n';
    
    std::cout << "   p == q: " << (p == q ? "true" : "false") << '\n';
    std::cout << "   p != q: " << (p != q ? "true" : "false") << '\n';
    std::cout << "   p > r: " << (p > r ? "true" : "false") << '\n';
    std::cout << "   p < r: " << (p < r ? "true" : "false") << '\n';
    std::cout << "   p >= q: " << (p >= q ? "true" : "false") << '\n';
    std::cout << "   p <= r: " << (p <= r ? "true" : "false") << '\n';

    std::cout << "7. ВВОД/ВЫВОД:\n";
    Fraction inputFrac;
    std::cout << "   Введите дробь в формате числитель/знаменатель (например, 5/6): ";
    std::cin >> inputFrac;
    std::cout << '\n' << "   Вы ввели: " << inputFrac << '\n';

    std::cout << "8. ПРЕОБРАЗОВАНИЕ В DOUBLE:\n";
    Fraction frac1(3, 4);
    Fraction frac2(22, 7);
    std::cout << "   frac1 = " << frac1 << '\n';
    std::cout << "   frac1.fracToDouble(frac1) = " << std::fixed << std::setprecision(6) 
              << frac1.fracToDouble(frac1) << '\n';
    std::cout << "   frac2 = " << frac2 << '\n';
    std::cout << "   frac2.fracToDouble(frac2) = " << std::fixed << std::setprecision(6) 
              << frac2.fracToDouble(frac2) << '\n';

    std::cout << "\n=== Демонстрация завершена ===\n";
    
    return 0;
}
