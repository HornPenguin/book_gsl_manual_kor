운송 함수 :math:`J(n,x)` 는 다음과 같이 적분으로 정의됩니다.

.. math::
    
    J(n,x) = \int_0^x \frac{t^ne^t}{(e^t -1)^2} \, dx

    헤더 파일 :code:`gsl_sf_transport.h` 에 정의되어 있습니다.

.. function:: double gsl_sf_transport_2 (double x)
              int gsl_sf_transport_2_e (double x, gsl_sf_result * result)

    운송 함수 :math:`J(2,x)`  의 값을 계산합니다.

.. function:: double gsl_sf_transport_3 (double x)
              int gsl_sf_transport_3_e (double x, gsl_sf_result * result)

    운송 함수 :math:`J(3,x)`  의 값을 계산합니다.

.. function:: double gsl_sf_transport_4 (double x)
              int gsl_sf_transport_4_e (double x, gsl_sf_result * result)

    운송 함수 :math:`J(4,x)`  의 값을 계산합니다.

.. function:: double gsl_sf_transport_5 (double x)
              int gsl_sf_transport_5_e (double x, gsl_sf_result * result)

    운송 함수 :math:`J(5,x)`  의 값을 계산합니다.
