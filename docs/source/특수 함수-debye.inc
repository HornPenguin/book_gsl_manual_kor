.. index:: Debye functions


디바이 함수 :math:`D_n(x)`  는 다음과 같이 정의됩니다.

.. math::

    D_n(x) = \frac{n}{x^n} \int_0^x \frac{t^n}{e^t -1} \, dt

더 자세한 정보는 Abramowitz & Stegun, Section 27.1을 참고할 수 있습니다. 
디바이 함수는 헤더 파일 :code:`gsl_sf_debye.h` 에 정의되어 있습니다.

.. c:function:: double gsl_sf_debye_1 (double x)
              int gsl_sf_debye_1_e (double x, gsl_sf_result * result)

   :math:`1` 차 디바이 함수 :math:`D_1(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_debye_2 (double x)
              int gsl_sf_debye_2_e (double x, gsl_sf_result * result)

   :math:`2` 차 디바이 함수 :math:`D_2(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_debye_3 (double x)
              int gsl_sf_debye_3_e (double x, gsl_sf_result * result)

   :math:`3` 차 디바이 함수 :math:`D_3(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_debye_4 (double x)
              int gsl_sf_debye_4_e (double x, gsl_sf_result * result)

   :math:`4` 차 디바이 함수 :math:`D_4(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_debye_5 (double x)
              int gsl_sf_debye_5_e (double x, gsl_sf_result * result)

   :math:`5` 차 디바이 함수 :math:`D_5(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_debye_6 (double x)
              int gsl_sf_debye_6_e (double x, gsl_sf_result * result)

   :math:`6` 차 디바이 함수 :math:`D_6(x)` 의 값을 계산합니다.
