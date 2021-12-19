.. index:: dilogarithm

다이 로그는 다음과 같이 정의됩니다.

.. math::

    Li_2 (z) = - \int_0^z \frac{\log(1-s)}{s} \, ds

이 함수들은 헤더 파일 :code:`gsl_sf_dilog.h` 에 정의되어 있습니다.


실수 인자 (Real Argument)
----------------------------
.. function:: double gsl_sf_dilog (double x)
              int gsl_sf_dilog_e (double x, gsl_sf_result * result)


    이 함수들은 실수 값에 대한 다이 로그값을 계산합니다. 
    르윈(Lewin)의 표기법으로 :math:`Li_2(x)`  로 표기되며, 
    이는 실수 값 :math:`x`  의 다이 로그 값을 나타냅니다. 
    이 값은 다음과 같이 적분형 표현으로 정의됩니다.

    .. math:: 
        
        Li_2(x) = - \mathfrak{R} \int_0^x \log(1-s) /s \, ds
    
    .. note::

        * :math:`\mathfrak{I}(Li_2(x))` 는 :math:`x \leq 1` 에서 :math:`0` , :math:`x>1` 에서 :math:`- \pi \log(x)` 입니다.
        * Abramowitz & Stegun에서는 스펜스 적분(Spence integral)을 :math:`Li_2(x)` 대신 :math:`S(x) = Li_2(1-x)` 로 정의합니다.


복소수 인자 (Complex Argument)
---------------------------------------

.. function:: int gsl_sf_complex_dilog_e (double r, double theta, gsl_sf_result * result_re, gsl_sf_result * result_im)

    복소수 인자 :math:`z = r \exp(i\theta)` 에 대해, 
    복소수 값을 가지는 완전한 다이 로그 값을 계산합니다. 실수, 허수 값은 각각 :math:`result_re` 와 :math:`result_im` 에 반환됩니다.
