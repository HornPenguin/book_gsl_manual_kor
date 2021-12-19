.. index::
   single: error function
   single: erf(x)
   single: erfc(x)

오차 함수는 Abramowitz & Stegun, Chapter 7.에 기술되어 있습니다. 
이 단원에서 기술된 함수들은 헤더파일 :code:`gs_sf_erf.h` 에 기술되어 있습니다.

오차 함수(Error Functionn)
------------------------------

.. function:: double gsl_sf_erf (double x)
              int gsl_sf_erf_e (double x, gsl_sf_result * result)

    오차함수 :math:`\text{erf}(x)` 의 값을 계산합니다.  
    :math:`\text{erf}(x)` 는 다음과 같이 정의됩니다.
    
    .. math::
    
        \text{erf}(x) = \frac{2}{\sqrt{\pi}} \int_0^x dt \exp(-t^2)
    
상보 오차 함수(Complementary Error Functionn)
-------------------------------------------------

.. function:: double gsl_sf_erfc (double x)
              int gsl_sf_erfc_e (double x, gsl_sf_result * result)

    상보 오차 함수 :math:`\text{erfc}(x) = 1- \text{erf}(x)` 의 값을 계산합니다. :math:`\text{erfc}(x)` 는 다음과 같이 정의됩니다.

.. math::

    \text{erfc}(x) = \frac{2}{\sqrt{\pi}} \int_x^\infty dt \exp(-t^2)

로그 상보 오차 함수(Log Complementary Error Functionn)
-----------------------------------------------------------------------

.. function:: double gsl_sf_log_erfc (double x)
              int gsl_sf_log_erfc_e (double x, gsl_sf_result * result)

    상보 오차 함수의 로그값 :math:`\log(\text{erfc}(x))`  를 계산합니다.


확률 함수 (Probability functions)
------------------------------------------------

표준/가우스 분포의 확률 함수들은 Abramowitz & Stegun, Section 26.2에 기술되어 있습니다.

.. function:: double gsl_sf_erf_Z (double x)
              int gsl_sf_erf_Z_e (double x, gsl_sf_result * result)

    가우스 확률 밀도 함수 :math:`Z(x) = \frac{1}{\sqrt{2\pi}} \exp(- \frac{x^2}{2})` 값을 계산합니다.


.. function:: double gsl_sf_erf_Q (double x)
              int gsl_sf_erf_Q_e (double x, gsl_sf_result * result)

    가우스 확률 함수의 :math:`Q(x) = (1/\sqrt{2\pi}) \int_x^\infty dt \exp(-t^2/2)` 값을 계산합니다.


    표준 분포의 **하자드 함수(Hazard function)** 는 Mills' 비의 역으로도 알려져 있습니다. 
    이는 다음과 같이 정의됩니다.

    .. math:: 
    
        h(x) = \frac{Z(x)}{Q(x)} = \sqrt{\frac{2}{\pi}} \frac{\exp(- x^2/2)}{\text{erfc}(x/\sqrt{2})}

    :math:`x` 가 :math:`-\infty` 에 가까우질 수록 급격히 감소하며, :math:`x` 가 :math:`+\infty` 에 가까워질 수록 :math:`h(x) \approx` 로 점근합니다.

.. function:: double gsl_sf_hazard (double x)
              int gsl_sf_hazard_e (double x, gsl_sf_result * result)

    표준 분포의 하자드 함수(Hazard function)를 계산합니다.
