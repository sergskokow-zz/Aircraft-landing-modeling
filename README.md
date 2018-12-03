## Обзор
### Движение центра масс летательного аппарата описывается уравнением
![СДУ](/img/DE.png)

![x, y, z](https://tex.s2cms.ru/svg/x%2C%20y%2C%20z) – компоненты радиуса-вектора центра масс;

![\mu = 398600~{km^3 \over s^2}](https://tex.s2cms.ru/svg/%5Cmu%20%3D%20398600~%7Bkm%5E3%20%5Cover%20s%5E2%7D) – гравитационная постоянная Земли;

![Vx , Vy , Vz](https://tex.s2cms.ru/svg/Vx%20%2C%20Vy%20%2C%20Vz) – компоненты вектора скорости;

![c_{x\alpha} = 1.3](https://tex.s2cms.ru/svg/c_%7Bx%5Calpha%7D%20%3D%201.3) - аэродинамический коэффициент силы лобового сопротивления;

![K](https://tex.s2cms.ru/svg/K) – величина аэродинамического качества;

![S_{mid}  = 15~m^2](https://tex.s2cms.ru/svg/S_%7Bmid%7D%20%20%3D%2015~m%5E2) - площадь миделя;

![m = 8000~kg](https://tex.s2cms.ru/svg/m%20%3D%208000~kg) - масса ЛА;

![\rho](https://tex.s2cms.ru/svg/%5Crho) - плотность атмосферы;

![V, {V_x}, {V_y}, {V_z}](https://tex.s2cms.ru/svg/V%2C%20%7BV_x%7D%2C%20%7BV_y%7D%2C%20%7BV_z%7D) – модуль и компоненты вектора скорости;

![\gamma](https://tex.s2cms.ru/svg/%5Cgamma) - угол скоростного крена;

![m_1 , m_2 , m_3](https://tex.s2cms.ru/svg/m_1%20%2C%20m_2%20%2C%20m_3) – компоненты единичного вектора, лежащего в местной вертикальной плоскости и перпендикулярного вектору скорости;

![l_1 , l_2 , l_3](https://tex.s2cms.ru/svg/l_1%20%2C%20l_2%20%2C%20l_3) - компоненты единичного вектора-нормали к местной вертикальной плоскости:

![l_,m_](https://tex.s2cms.ru/svg/%5Cbar%20l%20%3D%20%5Cbegin%7BVmatrix%7D%0Al_1%5C%5C%0Al_2%5C%5C%0Al_3%0A%5Cend%7BVmatrix%7D%20%5Cright%20%5Crdline%20%3D%20%7B%7B%20%5Cbar%20V%20%5Ctimes%20%5Cbar%20r%20%7D%20%5Cover%20%7C%7B%20%5Cbar%20V%20%5Ctimes%20%5Cbar%20r%20%7D%7C%7D%3B~~%5Cbar%20m%20%3D%20%5Cbegin%7BVmatrix%7D%0Am_1%5C%5C%0Am_2%5C%5C%0Am_3%0A%5Cend%7BVmatrix%7D%20%5Cright%20%5Crdline%20%3D%20%7B%7B%20%5Cbar%20l%20%5Ctimes%20%5Cbar%20V%20%7D%20%5Cover%20%7C%7B%20%5Cbar%20l%20%5Ctimes%20%5Cbar%20V%20%7D%7C%7D.)
### Данные моделирования
![Data](https://tex.s2cms.ru/svg/%20%5Cbegin%7Bequation*%7D%0A%20%5Cbegin%7Bcases%7D%0Ax%20%3D%205065.124~km%3B%0A%5C%5C%0Ay%20%3D%202373.486~km%3B%0A%5C%5C%0Az%20%3D%203253.021~km%3B%0A%5C%5C%0AV_x%20%3D%20-4.857479~%7Bkm%20%5Cover%20s%7D%3B%0A%5C%5C%0AV_y%20%3D%203.565160~%7Bkm%20%5Cover%20s%7D%3B%0A%5C%5C%0AV_z%20%3D%204.695924~%7Bkm%20%5Cover%20s%7D.%0A%20%5Cend%7Bcases%7D%0A%5Cend%7Bequation*%7D%20)
## Результаты
Аппарат достигает высоты 5 км на 944 секунде моделирования.
![График высоты 1](/img/height1.png)
![График высоты 2](/img/height2.png)
![График траектории 1](/img/path1.png)
![График траектории 2](/img/path2.png)
![График траектории 3](/img/path3.png)
## Зависимости
1. [cJSON](https://github.com/DaveGamble/cJSON).
2. [Gnuplot](http://www.gnuplot.info/) - local version for Windows or installed version for GNU/Linux.
