.. index:: 에어리 함수
.. index:: Airy functiion

에어리 함수(Airy function) :math:`Ai(x)` 와 :math:`Bi(x)` 는 적분표현으로 다음과 같이 정의됩니다.

.. math::

    Ai(x) & = {1\over\pi} \int_0^\infty \cos(t^3/3 + xt ) \,dt \\
    Bi(x) & = {1\over\pi} \int_0^\infty (e^{-t^3/3 + xt} + \sin(t^3/3 + xt)) \,dt


더 자세한 정보는 Abramowitz & Stengu, Section 10.4를 참고할 수 있습니다. 
에어리 함수들은 헤더 파일 :code:`gsl_sf_airy.h` 에 정의되어 있습니다. 


에어리 함수
-----------------------------------
.. c:function:: double gsl_sf_airy_Ai (double x, gsl_mode_t mode)
                int gsl_sf_airy_Ai_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    에어리 함수 :math:`Ai(x)`의 값을 주어진 :var:`mode` 정밀도에 따라 계산합니다.

.. c:function:: double gsl_sf_airy_Bi (double x, gsl_mode_t mode)
                int gsl_sf_airy_Bi_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    에어리 함수 :math:`Bi(x)`의 값을 주어진 :var:`mode` 정밀도에 따라 계산합니다.

.. c:function:: double gsl_sf_airy_Ai_scaled (double x, gsl_mode_t mode)
                int gsl_sf_airy_Ai_scaled_e (double x, gsl_mode_t mode, gsl_sf_result * result)


    조정된 에어리 함수 :math:`S_A(x) Ai (x)` 의 값을 계산합니다. 
    :math:`x>0`일 때, 조정 계수 :math:`S_A(x)` 의 값은 :math:`exp{(\frac{2}{3} x^\frac{3}{2})}` 이고, :math:`x<0` 일 때는 :math:`1` 입니다.

.. c:function:: double gsl_sf_airy_Bi_scaled (double x, gsl_mode_t mode)
                int gsl_sf_airy_Bi_scaled_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    조정된 에어리 함수 :math:`S_A(x) Bi (x)` 의 값을 계산합니다. 
    :math:`x>0` 일 때, 조정 계수 :math:`S_A(x)` 의 값은 :math:`exp{(\frac{2}{3} x^\frac{3}{2})}` 이고, 
    :math:`x<0` 일 때는 :math:`1` 입니다.

에어리 함수의 도함수
-----------------------------------------------------

.. c:function:: double gsl_sf_airy_Ai_deriv (double x, gsl_mode_t mode)
                int gsl_sf_airy_Ai_deriv_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    에어리 함수의 도함수 :math:`Ai'(x)` 의 값을 주어진 :code:`mode` 정밀도에 따라 계산합니다.

.. c:function:: double gsl_sf_airy_Bi_deriv (double x, gsl_mode_t mode)
                int gsl_sf_airy_Bi_deriv_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    에어리 함수의 도함수 :math:`Bi'(x)` 의 값을 주어진 :code:`mode` 정밀도에 따라 계산합니다.

.. c:function:: double gsl_sf_airy_Ai_deriv_scaled (double x, gsl_mode_t mode)
                int gsl_sf_airy_Ai_deriv_scaled_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    조정된 에어리 도함수 :math:`S_A(x) Ai' (x)`의 값을 계산합니다. 
    :math:`x>0`일 때, 조정 계수 :math:`S_A(x)` 의 값은 :math:`exp{(\frac{2}{3} x^\frac{3}{2})}` 이고, 
    :math:`x<0` 일 때는 :math:`1` 입니다.

.. c:function:: double gsl_sf_airy_Bi_deriv_scaled (double x, gsl_mode_t mode)
                int gsl_sf_airy_Bi_deriv_scaled_e (double x, gsl_mode_t mode, gsl_sf_result * result)

    조정된 에어리 도함수 :math:`S_A(x) Bi' (x)` 의 값을 계산합니다. 
    :math:`x>0`일 때, 조정 계수 :math:`S_A(x)` 의 값은 :math:`exp{(\frac{2}{3} x^\frac{3}{2})}` 이고, 
    :math:`x<0` 일 때는 :math:`1` 입니다.

에어리 함수의 근
------------------------------------------------

.. c:function:: double gsl_sf_airy_zero_Ai (unsigned int s)
                int gsl_sf_airy_zero_Ai_e (unsigned int s, gsl_sf_result * result)

    에어리 함수 :math:`Ai(x)`의 :math:`s` 번째 근을 찾아 반환합니다. 

.. c:function:: double gsl_sf_airy_zero_Bi (unsigned int s)
                int gsl_sf_airy_zero_Bi_e (unsigned int s, gsl_sf_result * result)

    에어리 함수 :math:`Bi(x)`의 :math:`s` 번째 근을 찾아 반환합니다. 

에어리 도함수의 근
---------------------------------------------------------------------

.. c:function:: double gsl_sf_airy_zero_Ai_deriv (unsigned int s)
                int gsl_sf_airy_zero_Ai_deriv_e (unsigned int s, gsl_sf_result * result)

    에어리 도함수 :math:`Ai'(x)`의 :math:`s` 번째 근을 찾아 반환합니다.

.. c:function:: double gsl_sf_airy_zero_Bi_deriv (unsigned int s)
                int gsl_sf_airy_zero_Bi_deriv_e (unsigned int s, gsl_sf_result * result)

    에어리 도함수 :math:`Bi'(x)`의 :math:`s` 번째 근을 찾아 반환합니다.