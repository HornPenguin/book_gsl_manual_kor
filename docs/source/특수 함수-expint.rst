

지수 적분의 자세한 정보는 Abramowitz & Stegun, Chapter 5. 에서 찾아볼 수 있습니다. 이 함수들은 헤더 파일 :math:`gsl_sf_expint.h` 정의되어 있습니다.

지수 적분 (Exponential Integral)
----------------------------------

.. function:: double gsl_sf_expint_E1 (double x)
              int gsl_sf_expint_E1_e (double x, gsl_sf_result * result)

    지수 적분 함수 :math:`E_1(x)` 를 계산합니다.

    .. math::
    
        E_1(x) := \mathfrak{R} \int_1^\infty \frac{\exp(-xt)}{t}  dt


.. function:: double gsl_sf_expint_E2 (double x)
              int gsl_sf_expint_E2_e (double x, gsl_sf_result * result)

    :math:`2` 차 지수 적분 함수 :math:`E_2(x)` 를 계산합니다.

.. math::

    E_2(x) := \mathfrak{R} \int_1^\infty \frac{\exp(-xt)}{t^2}  dt

.. function:: double gsl_sf_expint_En (int n, double x)
              int gsl_sf_expint_En_e (int n, double x, gsl_sf_result * result)

    :math:`n` 차 지수 적분 함수 :math:`E_2(x)` 를 계산합니다.

    .. math::

        E_n(x) := \mathfrak{R} \int_1^\infty \frac{\exp(-xt)}{t^n}  dt


Ei(x)
-------------------------

.. function:: double gsl_sf_expint_Ei (double x)
              int gsl_sf_expint_Ei_e (double x, gsl_sf_result * result)

    지수 적분 :math:`Ei(x)` 의 값을 계산합니다.

    .. math::

        Ei(x) = - PV (\int_{-x}^\infty \frac{\exp(-t)}{t} dt)

    :math:`PV` 는 적분 주요값(Principal Value of Integral)입니다. 코시 주요값(Cauchy principal value)이라고도 합니다(\*).

초기하 적분 (Hyperbolic Integrals)
-------------------------------------------

.. function:: double gsl_sf_Shi (double x)
              int gsl_sf_Shi_e (double x, gsl_sf_result * result)

    다음의 적분값을 계산합니다.

    .. math::
     
        \text{Shi} (x) := \int_0^x \frac{\sinh(t)}{t} dt


.. function:: double gsl_sf_Chi (double x)
              int gsl_sf_Chi_e (double x, gsl_sf_result * result)

    다음의 적분값을 계싼합니다.

    .. math::

        \text{Chi}(x) := \mathfrak{R} [\gamma_E + \log(x) + \int_0^x \frac{\cosh(t) -1}{t} dt]

    :math:`\gamma_E` 는 오일러 상수입니다. 
    오일러 상수는 :macro:`M_EULER` 매크로로 라이브러리 내에 있습니다.


Ei_3(x)
-------------------------

.. function:: double gsl_sf_expint_3 (double x)
              int gsl_sf_expint_3_e (double x, gsl_sf_result * result)

    다음의 :math:`3`  차 지수 적분값을 :math:`x \geq 0`  에 대해 계산합니다.

    .. math::

        \text{Ei}_3 (x) := \int_0^x \exp(-t^3) dt


삼각 적분 (Trigonometric Integrals)
-------------------------------------------

.. function:: double gsl_sf_Si (const double x)
              int gsl_sf_Si_e (double x, gsl_sf_result * result)

    다음의 적분값을 계산합니다.

    .. math::

        \text{Si} (x) := \int_0^x \frac{\sin(t)}{t} dt

.. function:: double gsl_sf_Ci (const double x)
              int gsl_sf_Ci_e (double x, gsl_sf_result * result)

    다음의 적분값을 :math:`x \geq 0`  에 대해 계산합니다.

    .. math::

        \text{Ci} (x) := -\int_0^x \frac{\cos(t)}{t} dt


역탄젠트 적분 (Arctangent Integral)
-------------------------------------------

.. function:: double gsl_sf_atanint (double x)
              int gsl_sf_atanint_e (double x, gsl_sf_result * result)

    다음의 적분값을 계산합니다.
    
    .. math::
    
        \text{AtanInt}(x) := \int_0^x \frac{\text{arctan}}{t} dt