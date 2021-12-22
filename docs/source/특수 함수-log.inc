로그 함수에 관한 정보와 그 성질들은 Abramowitz & Stegun, Chapter 4를 참고할 수 있습니다. 
이 단원에서 기술된 함수들은 헤더 파일 :code:`gsl_sf_log.h` 에 기술되어 있습니다.

.. c:function:: double gsl_sf_log (double x)
                int gsl_sf_log_e (double x, gsl_sf_result * result)

    :math:`x>0`  인 :math:`x` 대해, :math:`\log(x)` 의 값을 계산합니다.

.. c:function:: double gsl_sf_log_abs (double x)
                int gsl_sf_log_abs_e (double x, gsl_sf_result * result)

    :math:`x \neq 0` 인 :math:`x` 대해, :math:`\log(|x|)` 을 계산합니다.

.. c:function:: int gsl_sf_complex_log_e (double zr, double zi, gsl_sf_result * lnr, gsl_sf_result * theta)

    복소수 :math:`z= z_r + i z_i` 의 로그값을 계산합니다. 결과 값은 :code:`lnr` 와 :code:`theta` 에 각각 저장되며, 다음과 같은 관계를 가집니다. :math:`\exp(lnr + i \theta) = z_r + i z_i`  , :math:`\theta`  는 :math:`[-\pi, \pi]`  의 범위를 가집니다.

.. c:function:: double gsl_sf_log_1plusx (double x)
                int gsl_sf_log_1plusx_e (double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, :math:`\log(1+x)` 의 값을 계산합니다. 
    이 함수에서 사용한 알고리즘은 작은 :math:`x` 대해 정확합니다.

.. c:function:: double gsl_sf_log_1plusx_mx (double x)
                int gsl_sf_log_1plusx_mx_e (double x, gsl_sf_result * result)

    :math:`x>-1` 에 대해, :math:`\log(1+x)-x` 의 값을 계산합니다.
    이 함수에서 사용한 알고르즘은 작은 :math:`x` 대해 정확합니다.
