.. index:: Clausen functions

클라우센 함수는 다음과 같이 적분으로 정의됩니다.

.. math::

  Cl_2(x) = - \int_0^x \log(2 \sin (\frac{t}{2})) \, dt

이 함수는 다이로그 함수와 다음과 같은 관계를 가집니다.  

.. math::
    
  Cl_2 (\theta) = \Im[Li_2 (e^{i \theta})]

클라우센 함수들은 헤더 파일 :math:`gsl_sf_clausen.h` 에 정의되어 있습니다.

.. function:: double gsl_sf_clausen (double x)
              int gsl_sf_clausen_e (double x, gsl_sf_result * result)

    이 함수들은 클라우센 적분 :math:`Cl_2(x)` 의 값을 계산합니다.