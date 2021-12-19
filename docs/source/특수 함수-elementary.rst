.. index:: elementary operations
.. index:: multiplication

다음 함수들은 곱셈 과정에서 오차의 전파를 같이 계산합니다. 
이 함수들은 헤더 파일 :code:`gsl_sf_elementary.h`  에 정의되어 있습니다.

.. function:: double gsl_sf_multiply (double x, double y)
              int gsl_sf_multiply_e (double x, double y, gsl_sf_result * result)

   :math:`x` 와 :math:`y`의 곱셈을 계산하고, 계산 결과와 오차를 :math:`result` 에 저장합니다.

.. function:: int gsl_sf_multiply_err_e (double x, double dx, double y, double dy, gsl_sf_result * result)

    :math:`x` 와 :math:`y` 의 곱셈을 절대 오차 :math:`dx` 와 :math:`dy` 와 함께 연산합니다. :math:`result` 에는 :math:`xy \pm xy\sqrt{(dx/x)^2 + (dy/y)^2}` 가 저장됩니다.
