.. index:: Dawson function

도슨 적분은 다음의 적분을 의미합니다.

.. math::

    D_+(x) = e^{-x^2} \int_0^x e^{t^2} \, dt

도슨 적분표는 Abramowitz & Stegun의 표7.5에서 찾을 수 있습니다. 
이 도슨 함수는 헤더 파일 :math:`gsl_sf_dawson.h` 에 정의되어 있습니다.

.. function:: double gsl_sf_dawson (double x)
              int gsl_sf_dawson_e (double x, gsl_sf_result * result)

    이 함수들은 주어진 값 :math:`x` 대해, 도슨 적분 값을 계산합니다.