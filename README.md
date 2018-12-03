## Обзор
### Движение центра масс летательного аппарата описывается уравнением
<img src="https://tex.s2cms.ru/svg/%20%5Cbegin%7Bequation*%7D%0A%20%5Cbegin%7Bcases%7D%0A%20%20%20%5Cdot%20x%20%3D%20V_x%20%0A%20%20%20%5C%5C%0A%20%20%20%5Cdot%20y%20%3D%20V_y%20%0A%20%20%20%5C%5C%0A%20%20%20%5Cdot%20z%20%3D%20V_z%20%0A%20%20%20%5C%5C%0A%20%20%20%5Cdot%20V_x%20%3D%20-%20%7B%5Cmu%20%5Cover%20r%5E3%7D%20%5Ccdot%20x%20-%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%20%5Ccdot%20V_x%20%2B%20K%20%5Ccdot%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%5E2%20%5Ccdot%20(%20m_1%20cos%20%5Cgamma%20%2B%20l_1%20sin%20%5Cgamma%20)%20%2B%20x%20%5Ccdot%20%5Comega%5E2%20%2B%202%20%5Ccdot%20%5Comega%20%5Ccdot%20V_y%3B%0A%5C%5C%0A%5Cdot%20V_y%20%3D%20-%20%7B%5Cmu%20%5Cover%20r%5E3%7D%20%5Ccdot%20y%20-%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%20%5Ccdot%20V_y%20%2B%20K%20%5Ccdot%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%5E2%20%5Ccdot%20(%20m_2%20cos%20%5Cgamma%20%2B%20l_2%20sin%20%5Cgamma%20)%20%2B%20y%20%5Ccdot%20%5Comega%5E2%20-%202%20%5Ccdot%20%5Comega%20%5Ccdot%20V_x%3B%0A%5C%5C%0A%5Cdot%20V_z%20%3D%20-%20%7B%5Cmu%20%5Cover%20r%5E3%7D%20%5Ccdot%20x%20-%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%20%5Ccdot%20V_z%20%2B%20K%20%5Ccdot%20c_%7B%20x%20%5Calpha%20%7D%20%5Ccdot%20%7BS_%7B%20mid%20%7D%20%5Cover%20%7B%202m%20%7D%7D%20%5Ccdot%20%5Crho%20%5Ccdot%20V%5E2%20%5Ccdot%20(%20m_3%20cos%20%5Cgamma%20%2B%20l_3%20sin%20%5Cgamma%20)%3B%0A%20%5Cend%7Bcases%7D%0A%5Cend%7Bequation*%7D%20" alt=" \begin{equation*}
 \begin{cases}
   \dot x = V_x 
   \\
   \dot y = V_y 
   \\
   \dot z = V_z 
   \\
   \dot V_x = - {\mu \over r^3} \cdot x - c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V \cdot V_x + K \cdot c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V^2 \cdot ( m_1 cos \gamma + l_1 sin \gamma ) + x \cdot \omega^2 + 2 \cdot \omega \cdot V_y;
\\
\dot V_y = - {\mu \over r^3} \cdot y - c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V \cdot V_y + K \cdot c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V^2 \cdot ( m_2 cos \gamma + l_2 sin \gamma ) + y \cdot \omega^2 - 2 \cdot \omega \cdot V_x;
\\
\dot V_z = - {\mu \over r^3} \cdot x - c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V \cdot V_z + K \cdot c_{ x \alpha } \cdot {S_{ mid } \over { 2m }} \cdot \rho \cdot V^2 \cdot ( m_3 cos \gamma + l_3 sin \gamma );
 \end{cases}
\end{equation*} " />
<img src="https://tex.s2cms.ru/svg/x%2C%20y%2C%20z" alt="x, y, z" /> – компоненты радиуса-вектора центра масс;

<img src="https://tex.s2cms.ru/svg/%5Cmu%20%3D%20398600~%7Bkm%5E3%20%5Cover%20s%5E2%7D" alt="\mu = 398600~{km^3 \over s^2}" /> – гравитационная постоянная Земли;

<img src="https://tex.s2cms.ru/svg/Vx%20%2C%20Vy%20%2C%20Vz" alt="Vx , Vy , Vz" /> – компоненты вектора скорости;

<img src="https://tex.s2cms.ru/svg/c_%7Bx%5Calpha%7D%20%3D%201.3" alt="c_{x\alpha} = 1.3" /> - аэродинамический коэффициент силы лобового
сопротивления;

<img src="https://tex.s2cms.ru/svg/K" alt="K" /> – величина аэродинамического качества;

<img src="https://tex.s2cms.ru/svg/S_%7Bmid%7D%20%20%3D%2015~m%5E2" alt="S_{mid}  = 15~m^2" /> - площадь миделя;

<img src="https://tex.s2cms.ru/svg/m%20%3D%208000~kg" alt="m = 8000~kg" /> -  масса ЛА;

<img src="https://tex.s2cms.ru/svg/%5Crho" alt="\rho" /> - плотность атмосферы;

<img src="https://tex.s2cms.ru/svg/V%2C%20%7BV_x%7D%2C%20%7BV_y%7D%2C%20%7BV_z%7D" alt="V, {V_x}, {V_y}, {V_z}" /> – модуль и компоненты вектора скорости;

<img src="https://tex.s2cms.ru/svg/%5Cgamma" alt="\gamma" /> - угол скоростного крена;

<img src="https://tex.s2cms.ru/svg/m_1%20%2C%20m_2%20%2C%20m_3" alt="m_1 , m_2 , m_3" /> – компоненты единичного вектора, лежащего в местной
вертикальной плоскости и перпендикулярного вектору скорости;

<img src="https://tex.s2cms.ru/svg/l_1%20%2C%20l_2%20%2C%20l_3" alt="l_1 , l_2 , l_3" />  - компоненты единичного вектора-нормали к местной
вертикальной плоскости:

<img src="https://tex.s2cms.ru/svg/%5Cbar%20l%20%3D%20%5Cbegin%7BVmatrix%7D%0Al_1%5C%5C%0Al_2%5C%5C%0Al_3%0A%5Cend%7BVmatrix%7D%20%5Cright%20%5Crdline%20%3D%20%7B%7B%20%5Cbar%20V%20%5Ctimes%20%5Cbar%20r%20%7D%20%5Cover%20%7C%7B%20%5Cbar%20V%20%5Ctimes%20%5Cbar%20r%20%7D%7C%7D%3B~~%5Cbar%20m%20%3D%20%5Cbegin%7BVmatrix%7D%0Am_1%5C%5C%0Am_2%5C%5C%0Am_3%0A%5Cend%7BVmatrix%7D%20%5Cright%20%5Crdline%20%3D%20%7B%7B%20%5Cbar%20l%20%5Ctimes%20%5Cbar%20V%20%7D%20%5Cover%20%7C%7B%20%5Cbar%20l%20%5Ctimes%20%5Cbar%20V%20%7D%7C%7D." alt="\bar l = \begin{Vmatrix}
l_1\\
l_2\\
l_3
\end{Vmatrix} \right \rdline = {{ \bar V \times \bar r } \over |{ \bar V \times \bar r }|};~~\bar m = \begin{Vmatrix}
m_1\\
m_2\\
m_3
\end{Vmatrix} \right \rdline = {{ \bar l \times \bar V } \over |{ \bar l \times \bar V }|}." />
### Данные моделирования
<img src="https://tex.s2cms.ru/svg/%20%5Cbegin%7Bequation*%7D%0A%20%5Cbegin%7Bcases%7D%0Ax%20%3D%205065.124~km%3B%0A%5C%5C%0Ay%20%3D%202373.486~km%3B%0A%5C%5C%0Az%20%3D%203253.021~km%3B%0A%5C%5C%0AV_x%20%3D%20-4.857479~%7Bkm%20%5Cover%20s%7D%3B%0A%5C%5C%0AV_y%20%3D%203.565160~%7Bkm%20%5Cover%20s%7D%3B%0A%5C%5C%0AV_z%20%3D%204.695924~%7Bkm%20%5Cover%20s%7D.%0A%20%5Cend%7Bcases%7D%0A%5Cend%7Bequation*%7D%20" alt=" \begin{equation*}
 \begin{cases}
x = 5065.124~km;
\\
y = 2373.486~km;
\\
z = 3253.021~km;
\\
V_x = -4.857479~{km \over s};
\\
V_y = 3.565160~{km \over s};
\\
V_z = 4.695924~{km \over s}.
 \end{cases}
\end{equation*} " />
## Результаты
Аппарат достигает высоты 5 км на 944 секунде моделирования.
![График высоты 1](/img/height1.png)
![График высоты 2](/img/height2.png)
![График траектории 1](/img/path1.png)
![График траектории 2](/img/path2.png)
![График траектории 3](/img/path3.png)
## Зависимости
1. [cJSON](https://github.com/DaveGamble/cJSON).
2. [Gnuplot](www.gnuplot.info) - local version for Windows or installed version for GNU/Linux.
